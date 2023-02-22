// example-006-002-vector.cpp
#include "num.hpp"
#include <array>
#include <vector>

#define ARRAY_SIZE 3 

int main(int argc, char* argv[]) {
  int nb = 0;
  std::cout << "Enter a number of elements (>= 3): " << std::flush;
  std::cin >> nb;

  if(nb <= 3) nb = 3;

  ___;
  std::array<num, ARRAY_SIZE> val {{{"a", 13}, {"b", 14}, {"c", 13}}};
  ___;

  std::vector<std::array<num, ARRAY_SIZE>> tab(nb);
  // There are nb*ARRAY_SIZE num in the heap here.
  
  tab[1] = val;
  ___;
  

  return 0;
}

