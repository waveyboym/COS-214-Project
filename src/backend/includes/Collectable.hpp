/**
*@file Collectable.hpp Collectable.cpp
*@class Collectable
*@author Michael
*@brief a Collectable class which all classes that make use of an interator must inherit from
*/
#ifndef COLLECTABLE_HPP
#define COLLECTABLE_HPP

/** 
*@brief a Collectable class which all classes that make use of an interator must inherit from
*/
class Collectable{
    public:
        /** 
        *@brief a null function to allow for polymorphic features to be used
        *@param none
        *@return void
        */
        virtual void nill() = 0;
};

#endif