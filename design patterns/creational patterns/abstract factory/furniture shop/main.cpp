#include "ModernChair.hpp"
#include "VictorianFurnitureFactory.hpp"
#include <iostream>


int main()
{
    // ModernChair mc;
    // std::cout << std::boolalpha << "Does modern chair has legs ? --> " << mc.has_legs() << std::endl;

    FurnitureFactory * ff(new VictorianFurnitureFactory);
    Chair * vc(ff->create_chair());

    std::cout << std::boolalpha << "Does the chair from victorian furniture factory has legs ? --> " << vc->has_legs() << std::endl;
    

    return 0;
}