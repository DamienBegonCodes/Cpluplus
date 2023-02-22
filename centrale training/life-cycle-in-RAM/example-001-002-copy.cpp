// example-001-002-copy.cpp
#include "num.hpp"

void f(num arg) {
  fun_scope;
  rem("the function does nothing...");
}

int main(int argc, char* argv[]) {
  
  num a {"a", 10};
  num x {"x", 10};

  ___;
  
  rem("Copy at declaration time");
  num b(a);
  num c {a};
  num d = a; // This is not an affectation.
  
  ___;
  
  rem("Copy at function call");
  f(x);
  ___;
  
  return 0;
}
