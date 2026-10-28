#ifndef H_VICTORIANCOFFEETABLE
#define H_VICTORIANCOFFEETABLE

#include "CoffeeTable.hpp"
#include <string>

class VictorianCoffeeTable : public CoffeeTable
{
public:
    VictorianCoffeeTable()
    {
        this->plate_length = 150;
        this->plate_width = 42;
    };

    std::string plate_shape() {return "Rectangular plate with rounded corners";};
};

#endif