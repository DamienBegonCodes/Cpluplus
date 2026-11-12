#ifndef H_METEO
#define H_METEO

// The Meteo class returns temperatures only in Fahrenheit
// The problem is that our displayer class displays Celsius values only
// Let's use an adapter on Meteo to display temperature in Celsius 

#include "Displayer.hpp"

class Meteo
{
protected:
    Displayer * displayer;
    float getTodaysTemperature() {return 68.0;};

public:
    Meteo() : displayer(nullptr) {};
    Meteo(Displayer * displayer) : displayer(displayer) {};
    virtual ~Meteo() 
    {
        delete displayer;
    };
    virtual void displayTodaysTemperature()
    {
        displayer->display(this->getTodaysTemperature());
    };
};

#endif