// example-001-001-allocation.cpp
#include "num.hpp"

int main(int argc, char* argv[]) {
  rem("Default allocation");
  num x;
  
  rem("Allocations from another type");
  num a("a", 10); 
  num b   {"b", 11}; 
  num c = {"c", 12};
  
  rem("Affectation");
  num d = {"d", 13}; // Not here, this is allocation...
  d = c;             // ... but here, since d already exists now.

  ___;
  
  return 0;
}
