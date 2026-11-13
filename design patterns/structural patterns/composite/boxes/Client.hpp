#ifndef H_CLIENT
#define H_CLIENT

#include "Contenu.hpp"

#include <iostream>

class Client
{
private:
    Contenu * contenu;
public:
    Client(Contenu * contenu) : contenu(contenu) {};
    void compteNombreProduit()
    {
        std::cout << "Voici le nombre de produits après décompte : " << contenu->countProducts() << std::endl;
    };
    void peseLeContenu()
    {
        std::cout << "Voici le poid total de mon contenu après l'avoir posé sur une balance : " << contenu->getWeight() << std::endl;
    };
};

#endif 