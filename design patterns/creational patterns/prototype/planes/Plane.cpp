#include "Plane.hpp"
#include <sstream>

Prototype * Plane::clone()
{
    return new Plane(*this);
}

Plane::Plane(std::string core_material, int wing_length, int fuselage_length, int fuselage_width, int tailplane_length, int fin_length)
    : core_material(core_material), wing_length(wing_length), fuselage_length(fuselage_length), fuselage_width(fuselage_width), tailplane_length(tailplane_length), fin_length(fin_length)
{}

std::string Plane::to_string()
{
    std::stringstream plane;
    plane   << "Plane :" << std::endl
            << "    core_material : " << core_material << std::endl
            << "    wing_length : " << wing_length << std::endl
            << "    fuselage_length : " << fuselage_length << std::endl
            << "    fuselage_width : " << fuselage_width << std::endl
            << "    tailplane_length : " << tailplane_length << std::endl
            << "    fin_length : " << fin_length << std::endl;

    return plane.str();
}
