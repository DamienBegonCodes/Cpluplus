#ifndef H_SHIP
#define H_SHIP

#include "Transport.hpp"

class Ship : public Transport
{
public:
    ~Ship();
    bool deliver();
};

#endif