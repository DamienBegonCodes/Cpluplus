// example-005-001-array.cpp
#include "num.hpp"
#include <array>

#define ARRAY_SIZE 3 // Avoid magic numbers in your code...

// Only constants can be used where we use ARRAY_SIZE. The value had
// to be known at compiling time (i.e. it is hard-coded in the receipe).

int main(int argc, char* argv[]) {
  {
    scope("non-STL arrays");
    num tab[ARRAY_SIZE]; // tab has no l-value !
    tab[0] = 3;
    tab[2] = 2;
    num* first_ptr  = tab;
    num* second_ptr = tab + 1;
    num* last_ptr   = tab + (ARRAY_SIZE - 1);
  }
  {
    scope("STL arrays");
    std::array<num, ARRAY_SIZE> tab;
    tab[0] = 3;
    tab[2] = 2;
    auto first_ptr  = tab.begin();
    auto second_ptr = tab.begin() + 1;
    auto last_ptr   = tab.end()   - 1;
  }
  {
    scope("Range initialization");
    std::array<num, ARRAY_SIZE> tab {{{"a", 0}, {"b", 1}, {"c", 2}}};
  }
  
  return 0;
}

