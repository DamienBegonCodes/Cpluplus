#include <petriTransition.hpp>

petri::Transition::Transition(std::string name, std::vector<slot> inputs, std::vector<slot> outputs):
    name(name), inputs(inputs), outputs(outputs) {}

bool petri::Transition::is_activable() const
{
    for(auto& i : inputs)
        if(i.first < i.second)
            return false;
    return true;
}

petri::Transition::operator bool () const {
  return is_activable();
}

void petri::Transition::activate()
{
    for(auto& i : inputs)  i.first->nb_tokens -= i.second;
    for(auto& o : outputs) o.first->nb_tokens += o.second;
}

void petri::Transition::operator()() {
  activate();
}

std::ostream& petri::operator<<(std::ostream& os, Transition t)
{
    os << '{';
    auto inputs = t.inputs;
    for (auto i = inputs.begin(); i != inputs.end(); ++i)
        os << i->first << '/' << i->second << ' ';
    os << "--> " << t.name << " --> ";
    auto outputs = t.outputs;
    for (auto o = outputs.begin(); o != outputs.end(); ++o)
        os << o->first << '/' << o->second << ' ';
    os << '}';
    return os;
}