#include "Logistics.hpp"
#include <iostream>

Logistics::~Logistics() {}

void Logistics::plan_delivery()
{
    Transport * t(this->factory_method());
    bool result(t->deliver());

    delete t;

    if (result)
    {
        std::cout << "The logistics platform confirms the arrival of the shipment in good condition" << std::endl;
    }
    else
    {
        std::cout << "The logistics platform informs that a problem occured with the shipment and did not arrive to its destination" << std::endl;
    }
}