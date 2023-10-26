/**
*@file Waiter.hpp Waiter.cpp
*@class Waiter
*@author 
*@implements People
*@brief a waiter object
*/
#ifndef WAITER_HPP
#define WAITER_HPP
#include "People.hpp"
#include <memory>

/** 
*@brief a waiter object
*/
class Waiter : public People{
    //TODO: implement
    private:
    public:
        /** 
        *@brief initialises a waiter object
        *@param none
        */
        Waiter();
        /** 
        *@brief 
        *@param none
        *@return bool
        */
        bool personAction();
};

#endif