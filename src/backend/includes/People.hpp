/**
*@file People.hpp People.cpp
*@class People
*@implements Collectable
*@author Michael
*@brief a People class which is a concrete iterator class of Collectable
*/
#ifndef PEOPLE_HPP
#define PEOPLE_HPP

#include <memory> // Include the memory header for std::shared_ptr

#include "Collectable.hpp"
#include "


class People : public Collectable {
protected:
    std::shared_ptr<MaitreD> maitre_d;
public:
/** 
        *@brief a null function to allow for polymorphic features to be used
        *@param none
        *@return void
        */
    void nill();
    virtual bool personAction() = 0;
};

#endif
