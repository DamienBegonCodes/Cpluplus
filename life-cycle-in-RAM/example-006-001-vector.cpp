// example-006-001-vector.cpp
#include "num.hpp"
#include <vector>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  int nb = 0;
  std::cout << "Enter a number of elements (>= 3): " << std::flush;
  std::cin >> nb;

  if(nb <= 3) nb = 3;
  
  // Nb is kown at execution time only ! We need the heap.

  {
    scope("non-STL dynamical arrays");
    num* tab = new num[nb]; // tab is a pointer, it has a l-value !
    tab[0] = 3;
    tab[2] = 2;
    num* first_ptr  = tab;
    num* second_ptr = tab + 1;
    num* last_ptr   = tab + (nb - 1);
    delete [] tab; // Do not forget releasing when you are done...
    //                ... and DO NOT FORGET THE [] !!!
  }
  {
    scope("STL dynamical arrays (i.e. vectors)");
    std::vector<num> tab(nb);
    tab[0] = 3;
    tab[2] = 2;
    auto first_ptr  = tab.begin();
    auto second_ptr = tab.begin() + 1;
    auto last_ptr   = tab.end()   - 1;

    // No delete here, the vector class does the release of the memory
    // it handles internally in the heap.
  }
  {
    scope("Range initialization");
    // Ok... here we know the size at compiling time.
    std::vector<num> tab {{{"a", 0}, {"b", 1}, {"c", 2}}};
    ___;
    // But we can add more elements, for example according to nb.
    for(int i = 0; i < nb; ++i)
      // We add {"new_i", i} at the end... reallocation of the whole vector may occur !
      tab.push_back({std::string("new_")+std::to_string(i), i});
    ___;
  }
  
  return 0;
}
