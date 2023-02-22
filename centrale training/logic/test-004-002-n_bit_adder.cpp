#include <gate.hpp>
#include <adder.hpp>

int main(int argc, char* argv[]) {
    auto sim = gate::agenda();

    auto bin1 = gate::bin(3);
    auto bin2 = gate::bin(3);
    auto sum = gate::bin(4);

    auto p1 = gate::PROBE(sim, "bin1", bin1);
    auto p2 = gate::PROBE(sim, "bin2", bin2);
    auto p3 = gate::PROBE(sim, "sum", sum);

    auto g = adder::n_bit_adder(sim, bin1, bin2, sum); 

    // test 1
    std::cout << "test 1" << std::endl;
    gate::notify(sim, bin1, {true, false, true},  0.0);
    gate::notify(sim, bin2, {false, true, false},  10.0);
    gate::notify(sim, bin2, {false, true, true},  20.0);

    gate::____();
    gate::flush(sim);
    gate::____();
    std::cout << std::endl;

    // raz
    std::cout << "raz" << std::endl;
    gate::notify(sim, bin1, {false, false, false},  0.0);
    gate::notify(sim, bin2, {false, false, false},  10.0);

    gate::____();
    gate::flush(sim);
    gate::____();
    std::cout << std::endl;

    // test 2
    std::cout << "test 2" << std::endl;
    gate::notify(sim, bin1, {true, true, true},  0.0);
    gate::notify(sim, bin2, {true, true, true},  10.0);

    gate::____();
    gate::flush(sim);
    gate::____();
    return 0;
}
