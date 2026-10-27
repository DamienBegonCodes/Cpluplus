#include "ShipLogistics.hpp"
#include "Ship.hpp"

Transport * ShipLogistics::factory_method()
{
    return new Ship;
}