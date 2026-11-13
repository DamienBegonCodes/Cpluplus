#ifndef H_BOX
#define H_BOX

#include <vector>
#include "Contenu.hpp"

class Box : public Contenu
{
private:
    std::vector<Contenu *> contenus;

public:
    Box(float weight, std::vector<Contenu *> contenus) : contenus(contenus)
    {
        this->ownWeight = weight;
    };

    ~Box()
    {
        for (Contenu * c : contenus)
        {
            c->~Contenu();
        }
    };

    int countProducts()
    {
        int sum(0);
        for (Contenu * c : contenus)
        {
            sum += c->countProducts();
        }
        return sum;
    };

    float getWeight()
    {
        float sum(this->ownWeight);
        for (Contenu * c : contenus)
        {
            sum += c->getWeight();
        }
        return sum;
    };
};

#endif