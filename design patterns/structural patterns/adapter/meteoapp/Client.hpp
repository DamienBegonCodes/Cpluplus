#ifndef H_CLIENT
#define H_CLIENT

#include "Meteo.hpp"
#include <iostream>

class Client
{
private:
    Meteo * meteo;

public:
    Client(Meteo * m) : meteo(m) {};
    ~Client()
    {
        delete meteo;
    }
    void askTodaysTemperature()
    {
        meteo->displayTodaysTemperature();
    };
};


#endif