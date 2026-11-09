#ifndef H_MODERNCHAIR
#define H_MODERNCHAIR

#include "Chair.hpp"

class ModernChair : public Chair
{
public:
    ModernChair()
    {
        this->height = 115;
        this->length = 73;
        this->breadth = 52;
    };
    bool has_legs() {return false;};
};

#endif