#include "HouseBuilder.hpp"
#include "House.hpp"
#include <iostream>

HouseBuilder::HouseBuilder()
{
    house = new House();
}

HouseBuilder::~HouseBuilder()
{
    delete house;
}

void HouseBuilder::reset()
{
    house = new House();
}

void HouseBuilder::build_windows(int nb_windows)
{
    house->nbWindows = nb_windows;
}

void HouseBuilder::build_doors(int nb_doors)
{
    house->nbDoors = nb_doors;
}

void HouseBuilder::build_rooms(int nb_rooms)
{
    house->nbRooms = nb_rooms;
}

void HouseBuilder::build_pool(int pool_size)
{
    if (!house->hasGarden)
    {
        std::cout << "Can not build a pool if there is no garden" << std::endl;
        return;
    }
    if (house->gardenSize < pool_size)
    {
        std::cout << "Size of garden (" << house->gardenSize << ") is not sufficient to build a pool of size " << pool_size << std::endl;
        return;
    }
    house->hasPool = true;
    house->poolSize = pool_size;
}

void HouseBuilder::build_garden(int garden_size)
{
    house->hasGarden = true;
    house->gardenSize = garden_size;
}

void HouseBuilder::build_garage(int garage_size)
{
    house->hasGarage = true;
    house->garageSize = garage_size;
}

House * HouseBuilder::get_product()
{
    house->totalLivingSurface = house->nbRooms * 30 + house->gardenSize + house->garageSize;
    House * result = house;
    reset();
    return result;
}