/**
*@file Kitchen.hpp Kitchen.cpp
*@class Kitchen
*@author Jaide
*@brief an Kitchen object
*/
#ifndef KITCHEN_HPP
#define KITCHEN_HPP
#include <memory>
#include <vector>
#include "Order.hpp"
#include "Waiter.hpp"
#include "AbstractChef.hpp"

/** 
*@brief a Kitchen object
*/
class Kitchen{
    private:
        /** 
        *@brief stores the next chef in the chain
        */
        std::vector<std::shared_ptr<Waiter>> waiters;
        /** 
        *@brief stores the start of the chain of chefs
        */
        std::shared_ptr<AbstractChef> chain_of_chefs; 
        /** 
        *@brief stores pairs of Orders and the customer the order came from. These will be requests that have yet to be made into meals
        */
        std::vector<std::pair<std::shared_ptr<std::vector<Order>>, std::shared_ptr<Customer>>> requests;
        /** 
        *@brief stores pairs of Meals and the customer the meal's order came from
        */
        std::vector<std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>>> completed_meals; //vector of pairs
    
    public:
        /** 
        *@brief initialises the Kitchen
        *@param waiters the list of waiters to observe on
        */
        Kitchen(std::vector<std::shared_ptr<Waiter>> waiters); 

        /** 
        *@brief handles the creation of a meal
        *@param order the list of orders to be implemented
        *@param customer the customer this order came from 
        */
        void createMeal(std::vector<std::shared_ptr<Order>> order, std::shared_ptr<Customer> customer);

        /** 
        *@brief alerts waiters that there are meals to be collected
        *@param none
        */
        void notifyWaiters();

        /** 
        *@brief returns the completed meals in the kitchen
        *@param none
        */
        std::vector<std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>>> getCompletedMeals();

};

#endif