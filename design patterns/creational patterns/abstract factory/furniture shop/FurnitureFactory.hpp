#ifndef H_FURNITUREFACTORY
#define H_FURNITUREFACTORY

#include "Chair.hpp"
#include "Sofa.hpp"
#include "CoffeeTable.hpp"

class FurnitureFactory
{
public:
    virtual ~FurnitureFactory() {};
    virtual Chair * create_chair() = 0;
    virtual Sofa * create_sofa() = 0;
    virtual CoffeeTable * create_coffee_table() = 0;
};


#endif