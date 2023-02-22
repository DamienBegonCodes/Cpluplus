#include <philosophers.hpp>
#include <iostream>

int main()
{
    int philosopher_nb = 2;
    int iter_nb = 1000;
    double counter = 0;
    std::random_device rd;
    std::mt19937 gen(rd());
    for (int i = 0; i < iter_nb; ++i)
    {
        auto philosophers = philo::network(philosopher_nb, gen());
        while (philosophers()) ++counter;
    }
    std::cout << counter << std::endl;
    std::cout << counter/iter_nb << std::endl;
    return 0;
}