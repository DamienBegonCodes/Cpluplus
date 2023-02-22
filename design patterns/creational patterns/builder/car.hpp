#pragma once

enum Engine {RegularEngine, SportsEngine};

class Car
{
    public:
        bool gps;
        int nb_seats;
        Engine engine;
        bool trip_computer;
};