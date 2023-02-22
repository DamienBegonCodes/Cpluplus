#pragma once

#include <car.hpp>
#include <builder.hpp>

class CarBuilder: public Builder
{
    private:
        Car* car;

    public:
        CarBuilder() {reset();};
        void reset() {car = new Car();};
        void setSeats(int n) {car->nb_seats = n;};
        void setEngine(Engine e) {car->engine = e;};
        void setTripComputer(bool b) {car->trip_computer = b;};
        void setGps(bool b) {car->gps = b;};
        Car* getProduct()
        {
            auto product = car;
            reset();
            return product;
        };
};