#include <iostream>

#include "Client.hpp"
#include "Contenu.hpp"
#include "Box.hpp"
#include "Product.hpp"

int main()
{
    std::cout << "------main------" << std::endl;

    Contenu * fer_a_repasser = new Product(5);
    Contenu * pomme = new Product(0.5);
    Contenu * stylo = new Product(0.05);
    Contenu * pc = new Product(10);
    
    Contenu * petite_boite = new Box(0.1, {pomme, stylo});
    Contenu * moyenne_boite = new Box(0.5, {pc, fer_a_repasser});
    
    Contenu * grande_boite = new Box(0.75, {petite_boite, moyenne_boite});

    Client c = Client(grande_boite);
    c.compteNombreProduit();
    c.peseLeContenu();

    delete grande_boite;
    
    std::cout << "-----(main)-----" << std::endl;
    return 0;
}