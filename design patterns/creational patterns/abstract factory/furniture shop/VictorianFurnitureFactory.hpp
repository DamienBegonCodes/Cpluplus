#ifndef H_VICTORIANFURNITUREFACTORY
#define H_VICTORIANFURNITUREFACTORY

#include "FurnitureFactory.hpp"

#include "Chair.hpp"
#include "Sofa.hpp"
#include "CoffeeTable.hpp"

#include "VictorianChair.hpp"
#include "VictorianSofa.hpp"
#include "VictorianCoffeeTable.hpp"

class VictorianFurnitureFactory : public FurnitureFactory
{
public:
    Chair * create_chair() {return new VictorianChair;};
    Sofa * create_sofa() {return new VictorianSofa;};
    CoffeeTable * create_coffee_table() {return new VictorianCoffeeTable;};
};

#endif