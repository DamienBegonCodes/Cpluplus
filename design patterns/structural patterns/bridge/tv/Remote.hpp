#ifndef H_REMOTE
#define H_REMOTE

#include "Device.hpp"

class Remote
{
private:
    Device * device;

public:
    Remote(Device * device) : device(device) {};
    void togglePower();
    void volumeDown();
    void volumeUp();
    void channelDown();
    void channelUp();
};

#endif