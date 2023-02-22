#include <iostream>
#include <algorithm>
#include <serie.hpp>
#include <num.hpp>

int main(int argc, char* argv[]) {
  scope("Swap");
  auto a = serie::range(0,  5);
  ___;
  auto b = serie::range(5, 10);
  std::cout << scope_indent << "a, b = " << a << ", " << b << std::endl;
  {
    scope("Naive");
    serie tmp = a;
    ___;
    a         = b;
    ___;
    b         = tmp;
    ___;
    std::cout << scope_indent << "a, b = " << a << ", " << b << std::endl;
  }
  {
    scope("Clever");
    serie tmp = std::move(a);
    ___;
    a         = std::move(b);
    ___;
    b         = std::move(tmp);
    ___;
    std::cout << scope_indent << "a, b = " << a << ", " << b << std::endl;
  }
  {
    scope("STL");
    std::swap(a, b);
    ___;
    std::cout << scope_indent << "a, b = " << a << ", " << b << std::endl;
  }

  std::cout << scope_indent << std::endl;
  rem("");
  rem("+-----------------------------------------------+");
  rem("|                                               |");
  rem("| Try to compile with -DserieDEBUG_MOVE_CALLS ! |");
  rem("|                                               |");
  rem("+-----------------------------------------------+");
  rem("");
  std::cout << scope_indent << std::endl;
	    
  
  return 0;
}
