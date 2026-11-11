#include <iostream>

#include "Prototype.hpp"
#include "Plane.hpp"

int main()
{
    std::cout << "------main------" << std::endl;

    Prototype * p = new Plane("aluminum", 
                                10,
                                25,
                                4,
                                2,
                                3);

    Prototype * p2 = p->clone();

    
    std::cout << p->to_string() << std::endl;
    std::cout << p2->to_string() << std::endl;
  
    delete p;
    delete p2;
    
    std::cout << "-----(main)-----" << std::endl;
    return 0;
}