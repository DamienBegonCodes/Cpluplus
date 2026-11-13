#include "Device.hpp"

#include <iostream>

bool Device::isEnabled()
{
    return this->powerOn;
}

void Device::enable()
{
    if (!this->powerOn)
    {
        this->powerOn = true;
    }
}

void Device::disable()
{
    if (this->powerOn)
    {
        this->powerOn = false;
    }
}

int Device::getVolume()
{
    return this->volume;
}

void Device::setVolume(int percent)
{
    if (percent > 100 || percent < 0)
    {
        std::cout << "Can not set volume to value outside of range [0; 100]" << std::endl;
        return;
    }
    this->volume = percent;
}

int Device::getChannel()
{
    return this->channel;
}