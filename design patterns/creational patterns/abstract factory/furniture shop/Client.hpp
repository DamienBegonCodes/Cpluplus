#ifndef H_CLIENT
#define H_CLIENT

#include "FurnitureFactory.hpp"
#include "Chair.hpp"

class Client
{
private:
    FurnitureFactory * ff;

public:
    Client(FurnitureFactory * ff) : ff(ff) {}
    ~Client()
    {
        delete ff;
    }
    Chair * order_chair() 
    {
        return ff->create_chair();
    }
};







#endif