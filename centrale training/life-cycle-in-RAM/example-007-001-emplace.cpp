// example-007-001-emplace.cpp
#include "num.hpp"

#define BUF_SIZE 1024
#define OFFSET    341

int main(int argc, char* argv[]) {
  char buffer[BUF_SIZE]; // an std::array could have been used here.

  void* storage_place = buffer + OFFSET;

  ___;
  rem("In place initialization.");
  // Let us initialize the bytes from address storage_place with a num
  // constructor.
  num* a_ptr = new (storage_place) num("a", 10);
  std::cout << scope_indent << a_ptr << " should be equal to " << storage_place << std::endl;
  ___;
  rem("Example of standard use as a num.");
  num b = *a_ptr; // Copy
  ___;
  rem("Cleaning up.");

  // delete a_ptr;  THIS IS A BUG !!!
  //                We just need to clean before buffer is released.
  
  a_ptr->~num();
  ___;
  rem("The buffer is released here too !");
  
  
  return 0;
}
