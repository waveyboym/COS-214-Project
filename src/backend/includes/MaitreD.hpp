/**
*@file MaitreD.hpp MaitreD.cpp
*@class MaitreD
*@author Michael
*@brief defines an abstract MaitreD class
*/
#ifndef MAITRE_D_HPP
#define MAITRE_D_HPP
#include "People.hpp"
#include <memory>

/** 
*@brief defines an abstract MaitreD class
*/
class MaitreD{
    public:
    /** 
        *@brief notifies the passed in person object
        *@param person the person to notify
        *@return bool
        */
        virtual bool notifyPerson(std::shared_ptr<People> person) = 0;
};

#endif
