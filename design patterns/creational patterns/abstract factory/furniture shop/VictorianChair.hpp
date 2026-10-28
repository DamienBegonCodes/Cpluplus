#ifndef H_VICTORIANCHAIR
#define H_VICTORIANCHAIR

#include "Chair.hpp"

class VictorianChair : public Chair
{
public:
    VictorianChair()
    {
        this->height = 102;
        this->length = 45;
        this->breadth = 63;
    };
    bool has_legs() {return true;};
};

#endif