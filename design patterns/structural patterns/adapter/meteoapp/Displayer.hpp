#ifndef H_DISPLAYER
#define H_DISPLAYER

#include <iostream>

class Displayer
{
public:
    void display(float temp_cel)
    {
        std::cout << "Today's temperature is " << temp_cel << " degree Celsius !" << std::endl;
    };
};


#endif