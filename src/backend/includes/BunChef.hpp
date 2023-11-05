/**
*@file BunChef.hpp BunChef.cpp
*@class BunChef
*@author Jaide
*@brief a BunChef object. Bun chef will create the initial meal object on which the order chefs can decorate
*/
#ifndef BUN_CHEF_HPP
#define BUN_CHEF_HPP

#include "../includes/AbstractChef.hpp"

class BunChef : public AbstractChef{

    private:
        /** 
        *@brief stores the next chef in the chain
        */
        std::shared_ptr<AbstractChef> next;

    public:

        std::string type;

        /** 
        *@brief initialises a BunChef
        *@param none
        */
        BunChef();
        
        /** 
        *@brief handles the creation of a meal
        *@param order the list of orders to be implemented
        *@param meal the meal on which to build
        *@param waiterUUID the waiter the order came from
        */
        virtual void makeOrder(std::vector<std::shared_ptr<Order>> order, std::string waiterUUID, std::shared_ptr<Meal> meal);
};

#endif
