#include "ModernFurnitureFactory.hpp"
#include "Client.hpp"
#include "Chair.hpp"

#include <iostream>



int main()
{
    // ModernChair mc;
    // std::cout << std::boolalpha << "Does modern chair has legs ? --> " << mc.has_legs() << std::endl;

    Client client_1(new ModernFurnitureFactory());
    Chair * chair(client_1.order_chair());

    std::cout << std::boolalpha << "Does the chair has legs ? --> " << chair->has_legs() << std::endl;

    delete chair;

    return 0;
}