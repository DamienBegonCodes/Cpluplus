#ifndef H_ARTDECOFURNITUREFACTORY
#define H_ARTDECOFURNITUREFACTORY

#include "FurnitureFactory.hpp"

#include "Chair.hpp"
#include "Sofa.hpp"
#include "CoffeeTable.hpp"

#include "ArtDecoChair.hpp"
#include "ArtDecoSofa.hpp"
#include "ArtDecoCoffeeTable.hpp"

class ArtDecoFurnitureFactory : public FurnitureFactory
{
public:
    Chair * create_chair() {return new ArtDecoChair;};
    Sofa * create_sofa() {return new ArtDecoSofa;};
    CoffeeTable * create_coffee_table() {return new ArtDecoCoffeeTable;};
};

#endif