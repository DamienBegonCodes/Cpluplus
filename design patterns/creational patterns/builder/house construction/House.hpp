#ifndef H_HOUSE
#define H_HOUSE

#include <string>



class House
{
private:
    int nbWindows;
    int nbDoors;
    int nbRooms;
    bool hasPool;
    int poolSize;
    bool hasGarden;
    int gardenSize;
    bool hasGarage;
    int garageSize;
    int totalLivingSurface;

public:
    House();

    std::string to_string();

    friend class HouseBuilder;
};



#endif