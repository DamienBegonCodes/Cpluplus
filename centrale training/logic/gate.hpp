#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <functional>
#include <memory>
#include <utility>
#include <map>
#include <tuple>
#include <algorithm>
#include <list>


namespace gate {
  
  using ref_action = std::shared_ptr<std::function<void ()>>;
  using wref_action = std::weak_ptr<std::function<void ()>>;
  using wire_ = std::pair<bool, std::list<wref_action>>;
  using ref_wire = std::shared_ptr<wire_>;
  using request_list = std::multimap<double, std::tuple<ref_wire, bool>>;
  using agenda_ = std::tuple<double, request_list>;
  using ref_agenda = std::shared_ptr<agenda_>;
  using gate_ = std::list<ref_action>;
  using binary_number = std::list<ref_wire>;
  using ref_bin = std::shared_ptr<binary_number>;


  void ____()
  {
    std::cout << "+-----------------+---------+-----+" << std::endl;
  }
  
  void ____display(double time, std::string name, bool status)
  {
    std::string status_str = status ? "on" : "off";

    std::cout.precision(2);
    std::cout << "| " << std::left << std::setw(15) << name << ' ';
    std::cout << "| " << std::right << std::fixed << std::setw(7) << time << ' ';
    std::cout << "| " << std::left << std::setw(3) << status_str << " |" << std::endl; 
  }

  ref_action action(std::function<void ()> func)
  {
    return std::make_shared<std::function<void ()>>(func);
  }

  void execute(ref_action ref_a)
  {
    (*ref_a)();
  }

  ref_wire wire()
  {
    wire_ wire = std::make_pair<bool, std::list<wref_action>> (0, {});
    return std::make_shared<wire_>(wire);
  }

  bool value(ref_wire ref_w)
  {
    return ref_w->first;
  }

  void link(ref_wire ref_w, ref_action ref_a)
  {
    wref_action wref_a = ref_a;
    ref_w->second.push_back(wref_a);
  }

  void set(ref_wire ref_w, bool value)
  {
    if (ref_w->first != value)
    {
      ref_w->first = value;
      for(auto it = ref_w->second.begin(); it != ref_w->second.end(); ++it)
      {
        if (auto wref_a = it->lock(); wref_a)
          (*wref_a)();
      }
    }
  }

  ref_agenda agenda()
  {
    request_list request_list;
    agenda_ agenda;
    std::get<0> (agenda) = 0.0;
    std::get<1> (agenda) = request_list;
    return std::make_shared<agenda_> (agenda);
  }

  double now(ref_agenda ref_ag)
  {
    return std::get<0>(*ref_ag);
  }

  void notify(ref_agenda ref_ag, ref_wire ref_w, bool state, double time)
  {
    std::get<1>(*ref_ag).insert({time, {ref_w, state}});
  }

  bool next(ref_agenda ref_ag)
  {
    request_list requests = std::get<1>(*ref_ag);
    if (requests.empty())
      return 0;
    else
    {
      double time = requests.begin()->first;
      std::get<0>(*ref_ag) += time;
      ref_wire ref_w = std::get<0>(requests.begin()->second);
      bool value = std::get<1>(requests.begin()->second);
      requests.erase(requests.begin());
      request_list time_updated_list;
      auto copy_into_new_map = [&time, &time_updated_list](auto request)
      {
        time_updated_list.insert({request.first - time, request.second});
      };
      std::for_each(requests.begin(), requests.end(), copy_into_new_map);
      std::get<1>(*ref_ag) = time_updated_list;
      set(ref_w, value);
      return 1;
    }
  }

  void flush(ref_agenda ref_ag)
  {
    while(next(ref_ag));
  }

  void flush(ref_agenda ref_ag, int nb_iter)
  {
    while(nb_iter != 0 && next(ref_ag))
      --nb_iter;
  }

  ref_action PROBE(ref_agenda ref_ag, std::string wire_name, ref_wire ref_w)
  {
    ref_action probe = action([ref_ag, wire_name, ref_w](){____display(now(ref_ag), wire_name, value(ref_w));});
    link(ref_w, probe);
    return probe;
  }

  gate_ AND(ref_agenda ref_ag, ref_wire wire1, ref_wire wire2, ref_wire output_wire)
  {
    ref_action and_action = action([wire1, wire2, output_wire, ref_ag]()
    {
      notify(ref_ag, output_wire, value(wire1) && value(wire2), 0.5);
    });
    link(wire1, and_action);
    link(wire2, and_action);
    execute(and_action);
    gate_ and_gate{and_action};
    return and_gate;
  }

  gate_ AND_explicit(ref_agenda ref_ag, ref_wire wire1, ref_wire wire2, ref_wire output_wire)
  {
    ref_action and_action = action([wire1, wire2, output_wire, ref_ag]()
    {
      std::cout << "wire 1 : " << value(wire1) << " wire 2 : " << value(wire2) << std::endl;
      notify(ref_ag, output_wire, value(wire1) && value(wire2), 0.5);
    });
    link(wire1, and_action);
    link(wire2, and_action);
    execute(and_action);
    gate_ and_gate{and_action};
    return and_gate;
  }

  gate_ OR(ref_agenda ref_ag, ref_wire wire1, ref_wire wire2, ref_wire output_wire)
  {
    ref_action or_action = action([wire1, wire2, output_wire, ref_ag]()
    {
      notify(ref_ag, output_wire, value(wire1) || value(wire2), 0.5);
    });
    link(wire1, or_action);
    link(wire2, or_action);
    execute(or_action);
    gate_ or_gate{or_action};
    return or_gate;
  }

  gate_ NOT(ref_agenda ref_ag, ref_wire input_wire, ref_wire output_wire)
  {
    ref_action not_action = action([input_wire, output_wire, ref_ag]()
    {
      notify(ref_ag, output_wire, !value(input_wire), 0.1);
    });
    link(input_wire, not_action);
    execute(not_action);
    gate_ not_gate{not_action};
    return not_gate;
  }

  gate_ merge_gates(std::list<gate_> gates)
  {
    gate_ out;
    for (auto i = gates.begin(); i != gates.end(); ++i)
    {
      for (auto action : *i)
        out.push_back(std::move(action));
    }
    return out;
  }

  gate_ XOR(ref_agenda agenda, ref_wire input_wire1, ref_wire input_wire2, ref_wire output_wire)
  {
    auto not_wire1 = wire();
    auto intermediate_wire1 = wire();
    gate_ not_gate1 = NOT(agenda, input_wire1, not_wire1);
    gate_ and_gate1 = AND(agenda, not_wire1, input_wire2, intermediate_wire1);

    auto not_wire2 = wire();
    auto intermediate_wire2 = wire();
    gate_ not_gate2 = NOT(agenda, input_wire2, not_wire2);
    gate_ and_gate2 = AND(agenda, not_wire2, input_wire1, intermediate_wire2);

    gate_ or_gate = OR(agenda, intermediate_wire1, intermediate_wire2, output_wire);

    return merge_gates({not_gate1, and_gate1, not_gate2, and_gate2, or_gate});
  }

  ref_bin bin(int size)
  {
    binary_number bin;
    for (int i = 0; i < size; ++i)
      bin.push_back(gate::wire());
    
    return std::make_shared<binary_number>(bin);
  }

  // create a probe for binaries, will display binary's wires one by one
  std::list<ref_action> PROBE(ref_agenda agenda, std::string bin_name, ref_bin bin)
  {
    std::list<ref_action> bin_probe;
    ref_action probe;
    std::string probe_name;
    int count = bin->size();
    for (auto i = bin->begin(); i != bin->end(); ++i)
    {
      probe_name = bin_name + "_wire" + std::to_string(count);
      probe = action([agenda, probe_name, i](){____display(now(agenda), probe_name, value(*i));});
      link(*i, probe);
      bin_probe.push_back(probe);
      --count;
    }
    return bin_probe;
  }

  // notify the agenda of a change in a binary
  void notify(ref_agenda ref_ag, ref_bin bin, std::list<bool> states, double time)
  {
    auto states_it = states.begin();
    auto bin_it = bin->begin();
    for (; states_it != states.end() && bin_it != bin->end(); ++states_it, ++bin_it)
      std::get<1>(*ref_ag).insert({time, {*bin_it, *states_it}});
  }
  
  
}

