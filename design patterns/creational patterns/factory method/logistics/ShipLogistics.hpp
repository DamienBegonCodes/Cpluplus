#ifndef H_SHIPLOGISTICS
#define H_SHIPLOGISTICS

#include "Logistics.hpp"

class ShipLogistics : public Logistics
{
public:
    Transport * factory_method();
};

#endif