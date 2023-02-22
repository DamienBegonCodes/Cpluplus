#pragma once
#include <gate.hpp>
#include <iostream>
#include <algorithm>

namespace adder
{
    using wire = gate::ref_wire;
    using agenda = gate::ref_agenda;
    using gate_ = gate::gate_;
    using binary_number = std::list<wire>;
    using ref_bin = std::shared_ptr<binary_number>;



    gate_ one_bit_adder(agenda agenda, wire carry_in, wire bit1, wire bit2, wire sum, wire carry_out)
    {
        auto intermediate_wire1 = gate::wire();
        auto intermediate_wire2 = gate::wire();
        auto intermediate_wire3 = gate::wire();
        gate_ xor1 = gate::XOR(agenda, bit1, bit2, intermediate_wire1);
        gate_ xor2 = gate::XOR(agenda, carry_in, intermediate_wire1, sum);
        gate_ and1 = gate::AND(agenda, intermediate_wire1, carry_in, intermediate_wire2);
        gate_ and2 = gate::AND(agenda, bit1, bit2, intermediate_wire3);
        gate_ or_gate = gate::OR(agenda, intermediate_wire2, intermediate_wire3, carry_out);

        return gate::merge_gates({xor1, xor2, and1, and2, or_gate});
    }

    // gate allowing to add two binary numbers in a form of list<wire>
    // bin1 and bin2 must be of same size but can be empty
    // sum must be initialized with bin1.size() + 1 wires (with function gate::bin(bin1.size() + 1)) 
    gate_ n_bit_adder(agenda agenda, ref_bin bin1, ref_bin bin2, ref_bin sum)
    {
        gate_ n_bit_adder;
        if (bin1->empty() || bin2->empty())
        {
            std::cerr << "parameters bin1 or/and bin2 are empty, can't proceed further, read comments at the top of adder::n_bit_adder" << std::endl;
            return n_bit_adder;
        }
        else if (bin1->size() != bin2->size() || bin1->size() != sum->size() - 1 || bin2->size() != sum->size() - 1)
        {
            std::cerr << "parameters bin1, bin2 and sum shapes are not correct, can't proceed further, read comments at the top of adder::n_bit_adder" << std::endl;
            return n_bit_adder;
        }

        std::list<wire> carries;
        for (int size = 0; size < bin1->size(); ++size)
            carries.push_back(gate::wire());

        auto bin1_it = --bin1->end();
        auto bin2_it = --bin2->end();
        auto sum_it = --sum->end();
        auto carries_it = carries.begin();
        std::list<gate_> adder_gates;
        wire carry_in;
        wire carry_out;
        for (;bin1_it != bin1->begin() && bin2_it != bin2->begin() && sum_it != ++sum->begin() && carries_it != --carries.end(); --bin1_it, --bin2_it, --sum_it)
        {
            carry_in = *carries_it;
            carry_out = *(++carries_it);
            adder_gates.push_back(one_bit_adder(agenda, carry_in, *bin1_it, *bin2_it, *sum_it, carry_out));
        }
        carry_in = *carries_it;
        carry_out = *sum_it;
        adder_gates.push_back(one_bit_adder(agenda, carry_in, *bin1_it, *bin2_it, carry_out, *(--sum_it)));
        n_bit_adder = gate::merge_gates(adder_gates);
        return n_bit_adder;
    }
}







