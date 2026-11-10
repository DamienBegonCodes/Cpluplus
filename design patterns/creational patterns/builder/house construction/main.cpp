#include <iostream>

#include "House.hpp"
#include "HouseBuilder.hpp"

int main()
{
    std::cout << "------main------" << std::endl;

    HouseBuilder hb;

    hb.build_windows(5);
    hb.build_rooms(3);
    hb.build_pool(20);
    hb.build_garden(30);
    hb.build_pool(40);
    hb.build_pool(20);
    House * h = hb.get_product();

    std::cout << h->to_string() << std::endl;
    delete h;

    std::cout << "-----(main)-----" << std::endl;
    return 0;
}