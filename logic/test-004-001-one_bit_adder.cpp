#include <gate.hpp>
#include <adder.hpp>

int main(int argc, char* argv[]) {
  auto sim = gate::agenda();

  auto bit1 = gate::wire();
  auto bit2 = gate::wire();
  auto sum = gate::wire();
  auto carry_in = gate::wire();
  auto carry_out = gate::wire();
  
  auto p1 = gate::PROBE(sim, "bit1", bit1);
  auto p2 = gate::PROBE(sim, "bit2", bit2);
  auto p3 = gate::PROBE(sim, "sum", sum);
  auto p4 = gate::PROBE(sim, "carry_in", carry_in);
  auto p5 = gate::PROBE(sim, "carry_out", carry_out);

  auto g = adder::one_bit_adder(sim, carry_in, bit1, bit2, sum, carry_out); 

  gate::notify(sim, bit1, true,  0.0);
  gate::notify(sim, bit2, true,  10.0);
  gate::notify(sim, bit1, false, 20.0);
  gate::notify(sim, bit2, false,  30.0);

  gate::____();
  gate::flush(sim);
  gate::____();
  
  return 0;
}
