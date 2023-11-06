/**
*@file AbstractChef.hpp AbstractChef.cpp
*@class AbstractChef
*@author Jaide
*@brief an AbstractChef class from which concrete BunChef, Chef, and HeadChef classes inherit
*/
#ifndef ABSTRACT_CHEF_HPP
#define ABSTRACT_CHEF_HPP
#include <memory>
#include <vector>
#include "Order.hpp"
#include "Customer.hpp"

/** 
*@brief an AbstractChef class that, when instantiated, is given a type to indicate specialisation
*/
class AbstractChef{
    private:
        /** 
        *@brief stores the next chef in the chain of responsibility
        */
        std::shared_ptr<AbstractChef> next;
    
    public:
        /** 
        *@brief stores the AbstractChef's type
        */
        std::string type;

        /** 
        *@brief initialises an AbstractChef from a type
        *@param type the type of chef to initialise: bun chef, chef, or head chef
        */
        AbstractChef(std::string type); 

        /** 
        *@brief handles the creation of a meal from an order by adding relevant 
        *@param order the list of orders to be implemented
        *@param customer the customer the order came from
        *@param meal the meal on which to build
        */
        virtual std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>> makeOrder(std::vector<std::shared_ptr<Order>> order, std::shared_ptr<Customer> customer, std::shared_ptr<Meal> meal) = 0;

        /** 
        *@brief adds a new chef to the chain of responsibility
        *@param c the chef to add
        *@return void
        */
        void add(std::shared_ptr<AbstractChef> c);

        /** 
        *@brief retrieves the next chef in the chain
        *@param none
        *@return std::shared_ptr<AbstractChef>
        */
        std::shared_ptr<AbstractChef> getNext(){
            return this->next;
        }

        /** 
        *@brief receives an order to be created
        *@param order the list of orders to be implemented
        *@param customer the customer the order is from
        *@return void
        */
        void receiveOrder(std::vector<std::shared_ptr<Order>> order, std::shared_ptr<Customer> customer);

};

#endif