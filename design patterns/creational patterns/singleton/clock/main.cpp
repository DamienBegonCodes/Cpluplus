#include <iostream>

#include "Clock.hpp"


int main()
{
    std::cout << "------main------" << std::endl;

    {
        Clock * first_clock = Clock::getInstance();

        first_clock->readTime();
        first_clock->setTime(700, 40, 14);
        first_clock->setTime(59, 40, 14);
    }

    {
        Clock * second_clock = Clock::getInstance();

        second_clock->readTime();
    }
    std::cout << "-----(main)-----" << std::endl;
    return 0;
}