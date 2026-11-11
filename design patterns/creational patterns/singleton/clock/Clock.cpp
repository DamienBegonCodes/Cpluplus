#include "Clock.hpp"
#include <iostream>

Clock * Clock::instance = nullptr;

Clock::Clock() : seconds(0), minutes(0), hours(0) {}

Clock::~Clock()
{
    if (instance != nullptr)
    {
        delete instance;
    }
}

Clock * Clock::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Clock();
    }
    return instance;
}

void Clock::setTime(int seconds, int minutes, int hours)
{
    if (seconds >= 60 || seconds < 0)
    {
        std::cout << "Cannot set clock seconds to value outside of range [0; 59]" << std::endl;
        return;
    }
    if (minutes >= 60 || minutes < 0)
    {
        std::cout << "Cannot set clock minutes to value outside of range [0; 59]" << std::endl;
        return;
    }
    if (hours >= 24 || hours < 0)
    {
        std::cout << "Cannot set clock hours to value outside of range [0; 23]" << std::endl;
        return;
    }
    this->seconds   = seconds;
    this->minutes   = minutes;
    this->hours     = hours;
}

void Clock::readTime()
{
    std::cout   << "Current time is :" << std::endl
                << "    Hours : " << this->hours << std::endl
                << "    Minutes : " << this->minutes << std::endl
                << "    Seconds : " << this->seconds << std::endl;
}