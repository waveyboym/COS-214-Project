#ifndef PEOPLE_HPP
#define PEOPLE_HPP
#include "Collectable.hpp"

class People : public Collectable{
    //TODO: implement
    public:
        void nill();
        virtual bool personAction() = 0;
};

#endif