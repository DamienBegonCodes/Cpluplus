// example-007-002-emplace-back.cpp
#include "num.hpp"
#include <vector>

int main(int argc, char* argv[]) {
  std::vector<num> v;

  // Let us allocate at once a big chunk of memory.
  ___;
  v.reserve(1024);
  std::cout << scope_indent << "Vector size = " << v.size() << std::endl;
  ___;
  
  for(int i = 0; i < 5 /* avoid magic numbers */; ++i)
    // The arguments of emplace_back should fit the arguments of one of the num constructors.
    v.emplace_back(std::string("x_")+std::to_string(i), i);

  // No memory allocation is done here, since we did it when we have
  // reserved 1024 nums previously.
  ___;
  std::cout << scope_indent << "Vector size = " << v.size() << std::endl;
  ___;
  
  
  return 0;
}
