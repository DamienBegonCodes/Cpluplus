#ifndef H_TV
#define H_TV

#include "Device.hpp"

class TV : public Device
{
public:
    TV()
    {
        this->channel = 0;
        this->volume = 50;
        this->powerOn = false;
    };
    void setChannel(int channel)
    {
        if (channel > 350 || channel < 0)
        {
            std::cout << "Can not set TV channel to value outside of range [0; 350]" << std::endl;
            return;
        }
        this->channel = channel;
    };
};
#endif