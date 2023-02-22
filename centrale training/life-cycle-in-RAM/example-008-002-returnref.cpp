// example-008-002-returnref.cpp
#include "num.hpp"

num& max(num& a, num& b, num& c) {
  fun_scope;
  if(b >= a && b >= c) return b;
  if(c >= a && c >= b) return c;
  return a;
}

int main(int argc, char* argv[]) {
  num a {"a", 10};
  num b {"b", 20};
  num c {"c",  9};

  ___;
  
  max(a, b, c) = 18;
  ___;

  return 0;
}
