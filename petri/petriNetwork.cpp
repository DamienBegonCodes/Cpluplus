#include <petriNetwork.hpp>
#include <vector>
#include <map>
#include <iomanip>

#define NODE_WIDTH 12
#define LABEL_WIDTH 30

petri::Network::Network(unsigned int seed)
  : gen(seed), transitions(), transition_verbosity(false) {}

bool petri::Network::operator()()
{
  std::vector<Transition*> activable_transi;
  int N{0};
  for (auto& transition : transitions)
    if (transition)
    {
      activable_transi.push_back(&transition);
      ++N;
    }
  if(!N) return false;

  std::uniform_int_distribution<> distrib(0, N-1);
  Transition& transi = *(activable_transi[distrib(gen)]);
  if (transition_verbosity) std::cout << transi.name << std::endl;
  transi();
  return true; 
}

std::ostream& petri::operator<<(std::ostream& os, const Network& network)
{
  std::map<pool_ref, unsigned int> idf_of_pool;
  std::string edges;

  os << "digraph Petri {" << std::endl
     << std::endl
     << "\toverlap=scale" << std::endl
     << std::endl
     << "\t/* nodes */" << std::endl
     << std::endl;

  int transition_id = 1, pool_id = 1;
  for (auto& transition : network.transitions)
  {
    for (auto& slot : transition.inputs) 
    {
      if (idf_of_pool.insert({slot.first, pool_id}).second) ++pool_id;
      auto found = idf_of_pool.find(slot.first);

      edges += "\tpool" + std::to_string(found->second)
            + " -> transition" + std::to_string(transition_id) + " [label=\""
            + std::to_string(slot.second) + "\"];\n";
    }
    for (auto& slot : transition.outputs)
    {
      if (idf_of_pool.insert({slot.first, pool_id}).second) ++pool_id;
      auto found = idf_of_pool.find(slot.first);

      edges += "\ttransition" + std::to_string(transition_id)
            + " -> pool" + std::to_string(found->second)
            + " [label=\"" + std::to_string(slot.second) + "\"];\n";
    }

    // Printing transitions
    os << "\t" << std::left << std::setw(NODE_WIDTH)
       << "transition" + std::to_string(transition_id++)
       << " [label=\"" << std::left << std::setw(LABEL_WIDTH) << transition.name + "\","
       << " shape=box, color=red, style=bold];" << std::endl;
  }
  os << std::endl;

  // Printing pools
  for (auto& [pool, id] : idf_of_pool) 
  {
    os << "\t" << std::left << std::setw(NODE_WIDTH) << "pool" + std::to_string(id)
       << " [label=\"" << std::left << std::setw(LABEL_WIDTH) << pool->name + "\","
       << " color=blue, style=bold];" << std::endl;
  }

  // Printing edges
  os << std::endl
     << "\t/* edges */"
     << std::endl
     << edges
     << "}";
  return os;
}