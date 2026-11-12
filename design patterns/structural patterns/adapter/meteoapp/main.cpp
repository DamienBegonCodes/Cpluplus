#include <iostream>

#include "Client.hpp"
#include "Meteo.hpp"
#include "Adapter.hpp"
#include "Displayer.hpp"

int main()
{
    std::cout << "------main------" << std::endl;
    Displayer * d(new Displayer);
    Meteo * m(new Adapter(d));

    Client client(m);
    client.askTodaysTemperature();
    
    std::cout << "-----(main)-----" << std::endl;
    return 0;
}