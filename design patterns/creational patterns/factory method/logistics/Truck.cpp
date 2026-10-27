#include "Truck.hpp"
#include <iostream>

Truck::~Truck() {}

bool Truck::deliver()
{
    std::cout << "Truck has delivered the shipment" << std::endl;
    return true;
}