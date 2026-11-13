#ifndef H_CLIENT
#define H_CLIENT

#include "Remote.hpp"

class Client
{
private:
    Remote * remote;
public:
    Client(Remote * remote) : remote(remote) {};

    void spendSomeTimeOnTV()
    {
        remote->togglePower();
        remote->volumeUp();
        remote->volumeUp();
        remote->volumeUp();
        remote->channelDown();
        remote->channelUp();
        remote->channelUp();
        remote->togglePower();
    }
};

#endif