// example-003-001-text.cpp
#include "num.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  {
    scope("arguments in the text");
    auto c = num("zero", 0) * num() + num("one", 1); // auto is guessed as type num....
    ___;
    std::cout << scope_indent << "c = " << c << std::endl;
  }
  {
    scope("copy constructors from text values");
    num a = num("a", 10); // useless, since ...
    num b = {"a", 10};    // ... does the same.

    // But with auto, you can have this.
    auto c = num("c", 10); // nota : direct copy here, not a move construction.
    auto d = c;
  }
  {
    scope("The compiler is clever");
    auto a = num(num(num(num(num(num(num(num("c", 10))))))));
  }

  return 0;
}
