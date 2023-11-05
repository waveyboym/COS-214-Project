/**
*@file Chef.hpp Chef.cpp
*@class Chef
*@author Jaide
*@brief a Chef object
*/
#ifndef CHEF_HPP
#define CHEF_HPP
#include "AbstractChef.hpp"

/** 
*@brief a AbstractChef object
*/
class Chef: public AbstractChef{
    private:
        /** 
        *@brief stores the next chef in the chain
        */
        std::shared_ptr<AbstractChef> next;

        /** 
        *@brief stores the pos this chef is attached to
        */
        std::shared_ptr<POS> pos_ptr;
    
    public:
        /** 
        *@brief initialises a Chef
        *@param none
        */
        Chef(); 

        /** 
        *@brief handles the creation of a meal
        *@param order the list of orders to be implemented
        *@param meal the meal on which to build
        *@param waiterUUID the waiter the order came from
        */
        virtual void makeOrder(std::vector<std::shared_ptr<Order>> order, std::string waiterUUID, std::shared_ptr<Meal> meal);
};

#endif