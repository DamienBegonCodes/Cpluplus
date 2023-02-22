#include <philosophers.hpp>
#include <string>
#include <fstream>


petri::Network philo::network(int philosopher_nb, unsigned int seed)
{
    petri::Network philosophers(seed);

    std::vector<petri::pool_ref> philosophers_thinking;
    std::vector<petri::pool_ref> philosophers_needing_right_fork;
    std::vector<petri::pool_ref> philosophers_eating;
    std::vector<petri::pool_ref> forks;

    // Here are the pools
    for (int i = 1; i <= philosopher_nb; ++i)
    {
        philosophers_thinking.push_back(petri::make_pool("philosopher_thinking" + std::to_string(i), 1));
        philosophers_needing_right_fork.push_back(petri::make_pool("philosopher_needing_right_fork" + std::to_string(i), 0));
        philosophers_eating.push_back(petri::make_pool("philosopher_eating" + std::to_string(i), 0));
        forks.push_back(petri::make_pool("fork" + std::to_string(i), 1));
    }


    // Here are the transitions
    auto out_it = std::back_inserter(philosophers.transitions);
    for (int i = 0; i < philosopher_nb; ++i)
    {
        int left_fork_id = i == philosopher_nb - 1 ? 0 : i;
        int right_fork_id = i == 0 ? philosopher_nb - 1: i - 1;
        *(out_it++) = {"philosopher" + std::to_string(i + 1) + "_takes_left_fork",
                              {{philosophers_thinking[i], 1}, {forks[left_fork_id], 1}},
                              {{philosophers_needing_right_fork[i], 1}}};
        *(out_it++) = {"philosopher" + std::to_string(i + 1) + "_takes_right_fork",
                              {{philosophers_needing_right_fork[i], 1}, {forks[right_fork_id], 1}},
                              {{philosophers_eating[i], 1}}};
        *(out_it++) = {"philosopher" + std::to_string(i + 1) + "_releases_forks",
                              {{philosophers_eating[i], 1}},
                              {{philosophers_thinking[i], 1}, {forks[left_fork_id], 1}, {forks[right_fork_id], 1}}};
    }
    return philosophers;
}

void philo::construct_petri(int philosopher_nb)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    auto philosophers = network(philosopher_nb, gen());
    
    // Let's write the network in a .dot file to save it
    std::ofstream file(std::to_string(philosopher_nb) + "_philosophers.dot");
    file << philosophers; // redlight is a petri::Network
}