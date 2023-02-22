// example-008-001-return.cpp
#include "num.hpp"

num f() {
  fun_scope;
  num res {"res", 10};
  return res;
}

num g() {
  fun_scope;
  return {"res", 10};
}

num h(num x) {
  fun_scope;
  return x;
}


int main(int argc, char* argv[]) {
  {
    scope("Testing f");
    num a = f();
    ___;
    num b;
    b = f();
    ___;
  }
  {
    scope("Testing g");
    num a = g();
    ___;
    num b;
    b = g();
    ___;
  }
  {
    scope("Testing h");
    num a {"a", 10};
    ___;
    num b = h(a);
    ___;
  }

  return 0;
}
