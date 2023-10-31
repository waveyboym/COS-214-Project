#ifndef PEOPLE_HPP
#define PEOPLE_HPP

#include <memory> // Include the memory header for std::shared_ptr

#include "Collectable.hpp"

// Forward declaration of MaitreD class
class MaitreD;

class People : public Collectable {
protected:
    std::shared_ptr<MaitreD> maitre_d;
public:
    void nill();
    virtual bool personAction() = 0;
};

#endif
