#include <builder_pattern.hpp>

int main()
{
    Director director;

    CarBuilder* car_builder = new CarBuilder();
    director.constructSportsCar(car_builder);
    Car* car = car_builder->getProduct();

    ManualBuilder* manual_builder = new ManualBuilder();
    director.constructSportsCar(manual_builder);

    Manual* manual = manual_builder->getProduct();
}