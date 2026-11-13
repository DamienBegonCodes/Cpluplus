#include <iostream>

#include "TV.hpp"
#include "Client.hpp"
#include "Radio.hpp"

int main()
{
    std::cout << "------main------" << std::endl;

    Device * tv = new TV();
    Remote * tv_remote = new Remote(tv);

    Client client(tv_remote);

    client.spendSomeTimeOnTV();
    
    std::cout << "-----(main)-----" << std::endl;
    return 0;
}