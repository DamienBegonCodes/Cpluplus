#ifndef H_MODERNFURNITUREFACTORY
#define H_MODERNFURNITUREFACTORY

#include "FurnitureFactory.hpp"

#include "Chair.hpp"
#include "Sofa.hpp"
#include "CoffeeTable.hpp"

#include "ModernChair.hpp"
#include "ModernSofa.hpp"
#include "ModernCoffeeTable.hpp"

class ModernFurnitureFactory : public FurnitureFactory
{
public:
    Chair * create_chair() {return new ModernChair;};
    Sofa * create_sofa() {return new ModernSofa;};
    CoffeeTable * create_coffee_table() {return new ModernCoffeeTable;};
};

#endif