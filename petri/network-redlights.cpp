#include <iostream>
#include <petri.hpp>
#include <iterator>
#include <random>
#include <fstream>

int main(int argc, char* argv[]) {
    std::random_device rd;
    petri::Network redlights(rd()); // rd() gets a random seed.

    // Here are the pools

    auto red1    = petri::make_pool("red-1",    1);
    auto green1  = petri::make_pool("green-1",  0);
    auto orange1 = petri::make_pool("orange-1", 0);

    auto red2    = petri::make_pool("red-2",    1);
    auto green2  = petri::make_pool("green-2",  0);
    auto orange2 = petri::make_pool("orange-2", 0);

    auto all_red = petri::make_pool("all-red", 1);

    // Let us add transitions

    auto out_trans_iter = std::back_inserter(redlights.transitions);
    *(out_trans_iter++) = {"1 turns green",
                {{red1,    1}, {all_red, 1}},
                {{green1,  1}}};
    *(out_trans_iter++) = {"1 turns orange",
                {{green1,  1}},
                {{orange1, 1}}};
    *(out_trans_iter++) = {"1 turns red",
                {{orange1, 1}},
                {{red1, 1}, {all_red, 1}}};
    *(out_trans_iter++) = {"2 turns green",
                {{red2,    1}, {all_red, 1}},
                {{green2,  1}}};
    *(out_trans_iter++) = {"2 turns orange",
                {{green2,  1}},
                {{orange2, 1}}};
    *(out_trans_iter++) = {"2 turns red",
                {{orange2, 1}},
                {{red2, 1}, {all_red, 1}}};

    // Let us run the sumulation
    redlights.transition_verbosity = true;
    for(unsigned int nb_steps = 0; (nb_steps < 10) && redlights() ; ++nb_steps);

    // Let's write the network in a .dot file to save it
    std::ofstream file("redlights.dot");
    file << redlights; // redlights is a petri::Network

    return 0;
}

