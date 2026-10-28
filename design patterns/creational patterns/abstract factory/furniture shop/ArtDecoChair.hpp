#ifndef H_ARTDECOCHAIR
#define H_ARTDECOCHAIR

#include "Chair.hpp"

class ArtDecoChair : public Chair
{
public:
    ArtDecoChair()
    {
        this->height = 92;
        this->length = 51;
        this->breadth = 71;
    };
    bool has_legs() {return true;};
};

#endif