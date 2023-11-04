/**
*@file HeadChef.hpp HeadChef.cpp
*@class HeadChef
*@author Jaide
*@brief a HeadChef object
*/
#ifndef HEAD_CHEF_HPP
#define HEAD_CHEF_HPP
#include "AbstractChef.hpp"

/** 
*@brief a HeadChef object
*/
class HeadChef: public AbstractChef{
    private:
        /** 
        *@brief stores the next chef in the chain
        */
        std::shared_ptr<AbstractChef> next;
    
    public:
        /** 
        *@brief initialises a Chef
        *@param none
        */
        HeadChef(); 

         /** 
        *@brief handles the creation of a meal
        *@param order the list of orders to be implemented
        *@param customer the customer the order came from
        *@param meal the meal on which to build
        */
        virtual std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>> makeOrder(std::vector<std::shared_ptr<Order>> order, std::shared_ptr<Customer> customer, std::shared_ptr<Meal> meal);

};

#endif