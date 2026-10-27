#ifndef H_LOGISTICS
#define H_LOGISTICS

#include "Transport.hpp"

class Logistics
{
public:
    virtual ~Logistics();
    virtual Transport * factory_method() = 0;
    void plan_delivery();
};

#endif