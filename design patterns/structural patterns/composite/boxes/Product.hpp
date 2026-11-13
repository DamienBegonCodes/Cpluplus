#ifndef H_PRODUCT
#define H_PRODUCT

#include "Contenu.hpp"

class Product : public Contenu
{
public:
    Product(float weight) 
    {
        this->ownWeight = weight;
    };

    int countProducts()
    {
        return 1;
    };

    float getWeight()
    {
        return this->ownWeight;
    };
};

#endif