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

    public:
        /** 
        *@brief stores the AbstractChef's type
        */
        std::string type;

        /** 
        *@brief initialises a Chef
        *@param none
        */
        Chef(); 

        /** 
        *@brief handles the creation of a meal
        *@param order the list of orders to be implemented
        *@param customer the customer the order came from
        *@param meal the meal on which to build
        */
        virtual std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>> makeOrder(std::vector<std::shared_ptr<Order>> order, std::shared_ptr<Customer> customer, std::shared_ptr<Meal> meal);

};

#endif