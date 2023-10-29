/**
*@file Bill.hpp Bill.cpp
*@class Bill
*@author Michael
*@implements Collectable
*@brief a Bill class which is a component class of Collectable
*/
#ifndef BILL_HPP
#define BILL_HPP
#include "Collectable.hpp"
#include <string>

/** 
*@brief an Bill class which is a component class of Collectable
*/
class Bill : public Collectable{
    public:
        /** 
        *@brief a null function to allow for polymorphic features to be used
        *@param none
        *@return void
        */
        void nill();
        /** 
        *@brief returns a string representation of the bill
        *@param none
        *@return std::string
        */
        virtual std::string toString() = 0;
        /** 
        *@brief returns the bill total
        *@param none
        *@return int
        */
        virtual int getTotal() = 0;
};

#endif