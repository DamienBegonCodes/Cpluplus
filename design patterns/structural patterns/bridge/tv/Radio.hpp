#ifndef H_RADIO
#define H_RADIO

#include "Device.hpp"

class Radio : public Device
{
public:
    Radio()
    {
        this->channel = 88;
        this->volume = 50;
        this->powerOn = false;
    }
    void setChannel(int channel)
    {
        if (channel > 350 || channel < 0)
        {
            std::cout << "Can not set radio channel to value outside of range [88; 108]" << std::endl;
            return;
        }
        this->channel = channel;
    };
};
#endif