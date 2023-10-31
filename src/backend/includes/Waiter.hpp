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
#include "Table.hpp"
#include "Orders.hpp"
#include <memory>

/** 
*@brief a waiter object
*/
class Waiter : public People{
    //TODO: implement
    private:
    vector<std::shared_ptr<Order>> OrderList;
    std::shared_ptr<Table> T;
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
        bool personAction(std::shared_ptr<People> c);
};

#endif