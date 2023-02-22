#include <iostream>
#include <algorithm>
#include <serie.hpp>
#include <num.hpp>

int main(int argc, char* argv[]) {  
  auto e = (serie::range( 3,  6) + serie::range( 0,  3)) + (serie::range( 9, 12) + serie::range( 6,  9));
  ___;

  std::cout << scope_indent << std::endl;
  rem("");
  rem("+-----------------------------------------------+");
  rem("|                                               |");
  rem("| Try to compile with -DserieDEBUG_MOVE_CALLS ! |");
  rem("|                                               |");
  rem("+-----------------------------------------------+");
  rem("");
  std::cout << scope_indent << std::endl;
  
  rem("Check that the number of allocated nums is minimal here.");
  return 0;
}
