#pragma once

#include <manual.hpp>
#include <builder.hpp>

class ManualBuilder: public Builder
{
    private:
        Manual* manual;

    public:
        ManualBuilder() {reset();};
        void reset() {manual = new Manual();};
        void setSeats(int n) {manual->nb_seats = n;};
        void setEngine(Engine e) {manual->engine = e;};
        void setTripComputer(bool b) {manual->trip_computer = b;};
        void setGps(bool b) {manual->gps = b;};
        Manual* getProduct()
        {
            auto product = manual;
            reset();
            return product;
        };
};