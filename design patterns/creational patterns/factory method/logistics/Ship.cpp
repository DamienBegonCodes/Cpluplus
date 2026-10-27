#include "Ship.hpp"
#include <iostream>

Ship::~Ship() {}

bool Ship::deliver()
{
    std::cout << "Ship has delivered the shipment" << std::endl;
    return true;
}