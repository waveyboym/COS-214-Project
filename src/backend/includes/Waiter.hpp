/**
*@file Waiter.hpp Waiter.cpp
*@class Waiter
*@author Michael
*@implements People
*@brief a waiter object
*/
#ifndef WAITER_HPP
#define WAITER_HPP
#include "People.hpp"
#include "Table.hpp"
//#include "Orders.hpp"
#include <memory>
#include <string>

/** 
*@brief a waiter object
*/
class Waiter : public People{
    private:
    public:
        /** 
        *@brief constructor
        *@param none
        */
        Waiter();
        /** 
        *@brief constructor
        *@param waiteruuid the uuid of this waiter
        */
        Waiter(std::string waiteruuid);
        /** 
        *@brief 
        *@param none
        *@return bool
        */
        bool personAction();
};

#endif