#ifndef H_TRUCKLOGISTICS
#define H_TRUCKLOGISTICS

#include "Logistics.hpp"

class TruckLogistics : public Logistics
{
public:
    Transport * factory_method();
};

#endif