#include "Truck.hpp"
#include "Ship.hpp"
#include "ShipLogistics.hpp"
#include <iostream>

int main()
{
    // Truck t;
    // std::cout << std::boolalpha << t.deliver() << std::endl;

    // Ship s;
    // std::cout << std::boolalpha << s.deliver() << std::endl;


    ShipLogistics sl;

    sl.plan_delivery();

    return 0;
}