/**
*@file AbstractChef.hpp AbstractChef.cpp
*@class AbstractChef
*@author Jaide
*@brief an AbstractChef object
*/
#ifndef ABSTRACT_CHEF_HPP
#define ABSTRACT_CHEF_HPP
#include <memory>
#include <vector>
#include "Order.hpp"
//#include "POS.hpp"

/** 
*@brief a AbstractChef object
*/
class AbstractChef{
    private:
        /** 
        *@brief stores the next chef in the chain
        */
        std::shared_ptr<AbstractChef> next;
    
    public:
        /** 
        *@brief initialises an AbstractChef
        *@param none
        */
        AbstractChef(); 

        /** 
        *@brief handles the creation of a meal
        *@param order the list of orders to be implemented
        *@param customer the customer the order came from
        *@param meal the meal on which to build
        */
        virtual std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>> makeOrder(std::vector<std::shared_ptr<Order>> order, std::shared_ptr<Customer> customer, std::shared_ptr<Meal> meal) = 0;

        /** 
        *@brief adds a new chef to the chain
        *@param c the chef to add
        */
        void add(std::shared_ptr<AbstractChef> c);

        /** 
        *@brief receives an order to be created
        *@param order the list of orders to be implemented
        *@param customer the customer the order is from
        */
        void receiveOrder(std::vector<std::shared_ptr<Order>> order, std::shared_ptr<Customer> customer);

};

#endif