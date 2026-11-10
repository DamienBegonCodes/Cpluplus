#pragma once

#include <builder.hpp>
#include <car.hpp>

class Director
{
    public:
        void constructSportsCar(Builder* builder)
        {
            builder->reset();
            builder->setSeats(2);
            builder->setEngine(SportsEngine);
            builder->setTripComputer(true);
            builder->setGps(true);
        };

        void constructSuv(Builder* builder)
        {
            builder->reset();
            builder->setSeats(4);
            builder->setEngine(RegularEngine);
            builder->setTripComputer(true);
            builder->setGps(true);
        };
};