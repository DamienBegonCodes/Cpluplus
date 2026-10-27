#include "TruckLogistics.hpp"
#include "Truck.hpp"

Transport * TruckLogistics::factory_method()
{
    return new Truck;
}