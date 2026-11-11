#ifndef H_PLANE
#define H_PLANE

#include <string>
#include "Prototype.hpp"

class Plane : public Prototype
{
private:
    std::string core_material;
    int wing_length;
    int fuselage_length;
    int fuselage_width;
    int tailplane_length;
    int fin_length;

public: 
    Prototype * clone();
    Plane(std::string, int, int, int, int, int);
    std::string to_string();
};


#endif