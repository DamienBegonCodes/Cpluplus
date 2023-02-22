#include <iostream>
#include <algorithm>
#include <serie.hpp>
#include <num.hpp>

int main(int argc, char* argv[]) {
  serie a = serie::range( 0,  3);
  serie b = serie::range( 3,  6);
  serie c = serie::range( 6,  9);
  serie d = serie::range( 9, 12);
  std::cout << scope_indent << "a = " << a << std::endl
	    << scope_indent << "b = " << b << std::endl
	    << scope_indent << "c = " << c << std::endl
	    << scope_indent << "d = " << d << std::endl
	    << scope_indent << "Let's compute e = (b + a) - (d + c)" << std::endl;
  rem("Minimal necessary allocation is 12 num values named ei.");
  {
    scope("By copying the intermediate results");
    auto tmp1 = b + a;
    std::cout << scope_indent << "tmp1 = " << tmp1 << std::endl;
    ___;
    auto tmp2 = d + c;
    std::cout << scope_indent << "tmp2 = " << tmp2 << std::endl;
    ___;
    auto e    = tmp1 - tmp2;
    ___;
    std::cout << scope_indent << "e   = " << e << std::endl;
    ___;
  }
  {
    scope("Expiring results can move");
    auto tmp1 = b + a;
    std::cout << scope_indent << "tmp1 = " << tmp1 << std::endl;
    ___;
    auto tmp2 = d + c;
    std::cout << scope_indent << "tmp2 = " << tmp2 << std::endl;
    ___;
    auto e    = std::move(tmp1) - std::move(tmp2);
    ___;
    std::cout << scope_indent << "tmp1 = " << tmp1 << std::endl
	      << scope_indent << "tmp2 = " << tmp2 << std::endl
              << scope_indent << "e    = " << e << std::endl;
    ___;
  }
  {
    scope("Expiring is induced by formulas");
    auto e = (a + b) - (d + c);
    ___;
    std::cout << scope_indent << "e = " << e << std::endl;
    ___;
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
  
  rem("Nums used in a, b, c and d are released hereafter.");
  return 0;
}
