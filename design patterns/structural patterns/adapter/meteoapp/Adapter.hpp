#ifndef H_ADAPTER
#define H_ADAPTER

#include "Meteo.hpp"

class Adapter : public Meteo
{
public:
    Adapter(Displayer * displayer) 
    {
        this->displayer = displayer;
    };
    void displayTodaysTemperature() override
    {
        float temp_fah = this->getTodaysTemperature();
        float temp_cel = (temp_fah - 32) * 5 / 9;
        displayer->display(temp_cel);
    };
};


#endif