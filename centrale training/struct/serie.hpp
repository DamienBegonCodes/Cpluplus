// This is the serie.hpp file.

#pragma once
#include <num.hpp>

// Forward declaration.
struct elem;
struct serie;
// The type serie (and elem) definition is pending (to be done later),
// but the compiler knows it exists. We can use serie&, serie* since
// this do not require to know sizeof(serie), which is not defined
// yet.
//
// Moreover, we can use the type serie in function headers, as soon
// has no function call has to be compiled.

// The following should return a "const serie" type in order to forbid
// the writing of (a+b) = c. Nevertheless, returning const type
// prevents the application of optimization with expiring.
//
// a + b + c <=> (a + b) + c, so temporary results are often on the
// left.
serie operator+(const serie&  a, const serie&  b);
serie operator+(      serie&& a, const serie&  b);
serie operator+(const serie&  a,       serie&& b);
serie operator+(      serie&& a,       serie&& b);
serie operator-(const serie&  a, const serie&  b);
serie operator-(      serie&& a, const serie&  b);
serie operator-(const serie&  a,       serie&& b);
serie operator-(      serie&& a,       serie&& b);

bool operator==(const serie&, const serie&);
bool operator!=(const serie&, const serie&);

// Serialization
std::ostream& operator<<(std::ostream&, const serie&);
std::istream& operator>>(std::istream&,       serie&);

struct serie {
  elem* front;
  elem* back;
  std::size_t size;

  // The constructors and affectations that should be implemented
  // since default ones my be used if there definition is missing
  // here.
  serie();
  serie(const serie&);
  serie(serie&&);
  serie& operator=(const serie& );
  serie& operator=(      serie&&);

  // Constructors and affectation from an external type.
  serie(int);

  // Destructor
  ~serie();

  // Conversion to bool (false <=> empty)
  operator bool() const;                  // if(s) {...};
  serie& operator+=(const serie& );       // a += b // prepend
  serie& operator+=(      serie&&);       // a += b // prepend
  serie& operator-=(const serie& );       // a -= b // append
  serie& operator-=(      serie&&);       // a -= b // append
  
  // Other features
  void clear();
  static serie empty();                   // serie::empty()
  static serie range(int start, int end); // serie::range(3, 8);
};
