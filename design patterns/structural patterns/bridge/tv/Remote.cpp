#include "Remote.hpp"

void Remote::togglePower()
{
    if (device->isEnabled())
    {
        device->disable();
    }
    else
    {
        device->enable();
    }
}

void Remote::volumeDown()
{
    device->setVolume(device->getVolume() - 5);
}

void Remote::volumeUp()
{
    device->setVolume(device->getVolume() + 5);
}

void Remote::channelDown()
{
    device->setChannel(device->getChannel() - 1);
}

void Remote::channelUp()
{
    device->setChannel(device->getChannel() + 1);
}
