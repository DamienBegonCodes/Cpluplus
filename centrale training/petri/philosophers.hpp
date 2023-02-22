#pragma once
#include <petri.hpp>

namespace philo
{
    petri::Network network(int philosopher_nb, unsigned int seed);
    void construct_petri(int philosopher_nb);
}