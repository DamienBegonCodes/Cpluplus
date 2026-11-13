#ifndef H_DEVICE
#define H_DEVICE

class Device
{
protected:
    int channel;
    int volume;
    bool powerOn;

public:
    virtual ~Device() {};
    bool isEnabled();
    void enable();
    void disable();
    int getVolume();
    void setVolume(int);
    int getChannel();
    virtual void setChannel(int) = 0;
};


#endif