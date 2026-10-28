#ifndef H_MODERNCOFFEETABLE
#define H_MODERNCOFFEETABLE

#include "CoffeeTable.hpp"
#include <string>

class ModernCoffeeTable : public CoffeeTable
{
public:
    ModernCoffeeTable()
    {
        this->plate_length = 164;
        this->plate_width = 54;
    };

    std::string plate_shape() {return "Thin oval plate";};
};

#endif