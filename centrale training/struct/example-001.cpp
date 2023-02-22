#include <iostream>
#include <serie.hpp>
#include <num.hpp>
#include <sstream>

int main(int argc, char* argv[]) {
  {
    scope("External");

    serie a {1};
    ___;
    serie b {2};
    ___;
    serie c = a + b;
    ___;
    serie d = a - b;
    ___;
    std::cout << scope_indent << "a = " << a << std::endl
	      << scope_indent << "b = " << b << std::endl
	      << scope_indent << "c = " << c << std::endl
	      << scope_indent << "d = " << d << std::endl;
    ___;
  }
  {
    scope("Serialization");
    std::istringstream is(" [] [1] [1, 2, 3] [1, 2, 3]");
    
    serie a;
    serie b;
    serie c;
    serie d;
    ___;
    is >> a >> b >> c >> d;
    ___;
    std::cout << scope_indent << "a = " << a << std::endl
	      << scope_indent << "b = " << b << std::endl
	      << scope_indent << "c = " << c << std::endl
	      << scope_indent << "d = " << d << std::endl
	      << std::boolalpha
	      << scope_indent << "b == c ? " << (b == c) << std::endl
	      << scope_indent << "c == d ? " << (c == d) << std::endl;
    ___;
  }
  {
    scope("Static constructors");
    auto a = serie::empty();
    auto b = serie::range(2, 8);
    ___;
    std::cout << scope_indent << "a = " << a << std::endl
	      << scope_indent << "b = " << b << std::endl;
    ___;
  }
  {
    scope("Affectation");
    auto a = serie::empty();
    auto b = serie::range(0, 5);
    auto c = serie::range(10, 20);
    ___;
    std::cout << scope_indent << "a = " << a << std::endl
	      << scope_indent << "b = " << b << std::endl
	      << scope_indent << "c = " << c << std::endl;
    {
      scope("a = c");
      ___;
      std::cout << scope_indent << "a = " << a << std::endl
		<< scope_indent << "c = " << c << std::endl;
      ___;
      a = c;
      ___;
      std::cout << scope_indent << "a = " << a << std::endl
		<< scope_indent << "c = " << c << std::endl;
      ___;
    }
    {
      scope("a = b");
      std::cout << scope_indent << "a = " << a << std::endl
		<< scope_indent << "b = " << b << std::endl;
      ___;
      a = b;
      ___;
      std::cout << scope_indent << "a = " << a << std::endl
		<< scope_indent << "b = " << b << std::endl;
      ___;
    }
    {
      scope("c = move(b)");
      std::cout << scope_indent << "c = " << c << std::endl
		<< scope_indent << "b = " << b << std::endl;
      ___;
      c = std::move(b);
      ___;
      std::cout << scope_indent << "c = " << c << std::endl
		<< scope_indent << "b = " << b << std::endl;
      ___;
    }
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
