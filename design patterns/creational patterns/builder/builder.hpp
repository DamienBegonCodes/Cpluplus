#pragma once

#include <car.hpp>

class Builder
{
    public:
        virtual void reset() = 0;
        virtual void setSeats(int) = 0;
        virtual void setEngine(Engine) = 0;
        virtual void setTripComputer(bool) = 0;
        virtual void setGps(bool) = 0;
};