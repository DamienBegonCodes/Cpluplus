// This is the serie.cpp file.

#include "serie.hpp"
#include <string>

#ifdef serieDEBUG_MOVE_CALLS
#include <sstream>
#endif

// Elem is not needed by the serie users. So it can be defined in the
// .cpp file. It is somehow "private" to the serie definition.
struct elem {
  num content;
  elem* next;

  // Here, we define the contructors inline.
  elem(int             val) : content(std::string("e") + std::to_string(val), val), next(nullptr) {}
  elem(const num&  content) : content(content),                                     next(nullptr) {}
  elem(      num&& content) : content(std::move(content)),                          next(nullptr) {
#ifdef serieDEBUG_MOVE_CALLS
    std::ostringstream ostr;
    ostr << "elem::elem(num&&  " << content << ")";
    scope(ostr.str());
#endif
  }
};

serie::serie()
  : front(nullptr), back(nullptr), size(0) {
}

serie::serie(const serie& copy)
  : front(nullptr), back(nullptr), size(0) {
  *this = copy; // affectation by copy defined later.
}

serie::serie(serie&& copy)
  : front(nullptr), back(nullptr), size(0) {
  
#ifdef serieDEBUG_MOVE_CALLS
  std::ostringstream ostr;
  ostr << "serie::serie(serie&& " << copy << ")";
  scope(ostr.str());
#endif
  
  *this = std::move(copy); // affectation by move defined later.
}

// Try to draw the memory chunks here...
serie& serie::operator=(const serie& arg) {
  // We try to reuse the memory we already have.
  elem*  src_iter = arg.front;
  back            = front;
  
  elem** dst_iter = &front;
  // The content of dst_iter is where next element address should be
  // stored. In other words, dst_iter stores the address of the place
  // where the address of the next element is stored. So *dst_iter is
  // the address of the next element.

  while(src_iter != nullptr) {
    if(*dst_iter == nullptr) // we have no existing element at "this", we create it.
      *dst_iter = new elem(src_iter->content);
    else
      (*dst_iter)->content = src_iter->content;
    back     = *dst_iter;
    src_iter = src_iter->next;
    dst_iter = &((*dst_iter)->next);
  }

  if(back->next != nullptr) {// this was longer than arg
    elem* it = back->next;
    while(it != nullptr) {
      elem* next = it->next;
      delete it;
      it = next;
    }
    back->next = nullptr;
  }
  return *this;
}

serie& serie::operator=(serie&& arg) {
#ifdef serieDEBUG_MOVE_CALLS
  std::ostringstream ostr;
  ostr << "serie& serie::operator=(serie&& " << arg << ")";
  scope(ostr.str());
#endif
  
  clear();
  front = arg.front;
  back  = arg.back;
  size  = arg.size;

  // Do not arg.clear() here ! It would be a bug.
  arg.front = nullptr;
  arg.back  = nullptr;
  arg.size  = 0;
  return *this;
}

serie::serie(int value)
  : front(new elem(value)), back(nullptr), size(1) {
  back = front;
}

serie::~serie() {
  clear();
}

serie::operator bool() const {
  return front != nullptr;
}
     
serie& serie::operator+=(const serie& arg) {
  if(arg) {
    elem* src_iter   = arg.front; // not nullptr here.
    elem* new_elems  = new elem(src_iter->content);
    elem* current    = new_elems;
    for(src_iter = src_iter->next; src_iter != nullptr; src_iter = src_iter->next, current = current->next)
      current->next = new elem(src_iter->content);
    current->next  = front;
    front          = new_elems;
    size          += arg.size;
  }
  return *this;
}

serie& serie::operator+=(serie&& arg) {
#ifdef serieDEBUG_MOVE_CALLS
  std::ostringstream ostr;
  ostr << "serie& serie::operator+=(serie&& " << arg << ")";
  scope(ostr.str());
#endif
  
  if(arg) {
    arg.back->next  = front;
    front            = arg.front;
    size            += arg.size;
    // Do not arg.clear() here ! It would be a bug.
    arg.front = nullptr;
    arg.back  = nullptr;
    arg.size  = 0;
  }
  return *this;
}

serie& serie::operator-=(const serie& arg) {
  if(arg) {
    elem* src_iter   = arg.front; // not nullptr here.
    elem* new_elems  = new elem(src_iter->content);
    elem* current    = new_elems;
    for(src_iter = src_iter->next; src_iter != nullptr; src_iter = src_iter->next, current = current->next)
      current->next = new elem(src_iter->content);
    if(*this) {
      back->next  = new_elems;
      size       += arg.size;
    }
    else {
      front = new_elems;
      size  = arg.size;
    }
    back = current;
  }
  return *this;
}

serie& serie::operator-=(serie&& arg) {
#ifdef serieDEBUG_MOVE_CALLS
  std::ostringstream ostr;
  ostr << "serie& serie::operator-=(serie&& " << arg << ")";
  scope(ostr.str());
#endif
  
  if(arg) {
    if(*this) 
      back->next = arg.front;
    else 
      front = arg.front;
    size += arg.size;
    back  = arg.back;
    
    // Do not arg.clear() here ! It would be a bug.
    arg.front = nullptr;
    arg.back  = nullptr;
    arg.size  = 0;
  }
  return *this;
}

void serie::clear() {
  elem* iter = front;
  while(iter != nullptr) {
    elem* next = iter->next;
    delete iter;
    iter = next;
  }
  size  = 0;
  front = nullptr;
  back  = nullptr;
}

serie serie::empty() {
  return {};
}

serie serie::range(int start, int end) {
  serie res;
  for(int i = start; i != end; ++i)
    res -= i;
  return res;
}

serie operator+(const serie& a, const serie& b) {
  serie res = a;
  res += b;
  return res;
}

serie operator+(serie&& a, const serie& b) {
#ifdef serieDEBUG_MOVE_CALLS
  std::ostringstream ostr;
  ostr << "const serie serie::operator+(serie&& " << a
       << ", const serie& " << b << ")";
  scope(ostr.str());
#endif
  
  serie res = std::move(a);
  res += b;
  return res;
}

serie operator+(const serie& a, serie&& b) {
#ifdef serieDEBUG_MOVE_CALLS
  std::ostringstream ostr;
  ostr << "const serie serie::operator+(const serie& " << a
       << ", serie&& " << b << ")";
  scope(ostr.str());
#endif
  
  serie res = std::move(b);
  res += a;
  return res;
}

serie operator+(serie&& a, serie&& b) {
#ifdef serieDEBUG_MOVE_CALLS
  std::ostringstream ostr;
  ostr << "const serie serie::operator+(serie&& " << a
       << ", serie&& " << b << ")";
  scope(ostr.str());
#endif
  
  serie res = std::move(a);
  res += std::move(b);
  return res;
}

serie operator-(const serie& a, const serie& b) {
  serie res = a;
  res -= b;
  return res;
}

serie operator-(serie&& a, const serie& b) {
#ifdef serieDEBUG_MOVE_CALLS
  std::ostringstream ostr;
  ostr << "const serie serie::operator-(serie&& " << a
       << ", const serie& " << b << ")";
  scope(ostr.str());
#endif
  
  serie res = std::move(a);
  res -= b;
  return res;
}

serie operator-(const serie& a, serie&& b) {
#ifdef serieDEBUG_MOVE_CALLS
  std::ostringstream ostr;
  ostr << "const serie serie::operator-(const serie& " << a
       << ", serie&& " << b << ")";
  scope(ostr.str());
#endif
  
  serie res = std::move(b);
  res -= a;
  return res;
}

serie operator-(serie&& a, serie&& b) {
#ifdef serieDEBUG_MOVE_CALLS
  std::ostringstream ostr;
  ostr << "const serie serie::operator-(serie&& " << a
       << ", serie&& " << b << ")";
  scope(ostr.str());
#endif
  
  serie res = std::move(a);
  res -= std::move(b);
  return res;
}

bool operator==(const serie& a, const serie& b) {
  if(a.size != b.size) return false;
  if(a.size == 0)      return true;
  elem* a_iter = a.front;
  elem* b_iter = b.front;
  for(; a_iter != nullptr; a_iter = a_iter->next, b_iter = b_iter->next)
    if(a_iter->content != b_iter->content) return false;
  return true;
}

bool operator!=(const serie& a, const serie& b) {
  return !(a == b);
}

std::ostream& operator<<(std::ostream& os, const serie& s) {
  os << '[';
  if(s) {
    elem* it = s.front;
    os << it->content;
    for(it = it->next; it != nullptr; it = it->next)
      os << ", " << it->content;
  }
  os << ']';
  return os;
}

std::istream& operator>>(std::istream& is, serie& s) {
  s.clear();
  // We could be more efficient here, and reuse the memory in s. You
  // can try to improve this function.
  
  char c;
  int value;
  is >> c; // eats white spaces and then c <- '['
  while(c != ']') {
    is >> c;
    if(c != ']') {
      is.putback(c);
      is >> value >> c;
      s -= value;
    }
  }
  return is;
}

