#ifndef H_ARTDECOCOFFEETABLE
#define H_ARTDECOCOFFEETABLE

#include "CoffeeTable.hpp"
#include <string>

class ArtDecoCoffeeTable : public CoffeeTable
{
public:
    ArtDecoCoffeeTable()
    {
        this->plate_length = 89;
        this->plate_width = 35;
    };

    std::string plate_shape() {return "Thick rectangular plate";};
};

#endif