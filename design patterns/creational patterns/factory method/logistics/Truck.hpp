#ifndef H_TRUCK
#define H_TRUCK

#include "Transport.hpp"

class Truck : public Transport
{
public:
    ~Truck();
    bool deliver();
};

#endif