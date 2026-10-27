#ifndef H_TRANSPORT
#define H_TRANSPORT


class Transport
{
public:
    virtual ~Transport() {};
    virtual bool deliver() = 0;
};

#endif