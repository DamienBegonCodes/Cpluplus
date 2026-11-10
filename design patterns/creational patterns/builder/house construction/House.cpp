#include "House.hpp"
#include <string>
#include <sstream>

House::House() : 
        nbWindows(0),
        nbDoors(0),
        nbRooms(0),
        hasPool(false),
        poolSize(0),
        hasGarden(false),
        gardenSize(0),
        hasGarage(false),
        garageSize(0),
        totalLivingSurface(0)
{}

std::string House::to_string()
{
    std::stringstream house;
    house   << std::boolalpha
            << "House :" << std::endl
            << "    nbWindows : " << nbWindows << std::endl
            << "    nbDoors : " << nbDoors << std::endl
            << "    nbRooms : " << nbRooms << std::endl
            << "    hasPool : " << hasPool << std::endl
            << "    poolSize : " << poolSize << std::endl
            << "    hasGarden : " << hasGarden << std::endl
            << "    gardenSize : " << gardenSize << std::endl
            << "    hasGarage : " << hasGarage << std::endl
            << "    garageSize : " << garageSize << std::endl
            << "    totalLivingSurface : " << totalLivingSurface << std::endl;
    return house.str();
}