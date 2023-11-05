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
// #include "POS.hpp"

/** 
*@brief a AbstractChef object
*/
class AbstractChef: public People{
    // private:
    //     /** 
    //     *@brief stores the next chef in the chain
    //     */
    //     std::shared_ptr<AbstractChef> next;

    //     /** 
    //     *@brief stores the pos this chef is attached to
    //     */
    //     std::shared_ptr<POS> pos_ptr;
    
    // public:
    //     /** 
    //     *@brief initialises an AbstractChef
    //     *@param none
    //     */
    //     AbstractChef(); 

    //     /** 
    //     *@brief handles the creation of a meal
    //     *@param order the list of orders to be implemented
    //     *@param meal the meal on which to build
    //     *@param waiterUUID the waiter the order came from
    //     */
    //     virtual void makeOrder(std::vector<std::shared_ptr<Order>> order, std::string waiterUUID, std::shared_ptr<Meal> meal) = 0;

    //      /** 
    //     *@brief adds a new chef to the chain
    //     *@param c the chef to add
    //     */
    //     void add(std::shared_ptr<AbstractChef> c);

    //     /** 
    //     *@brief receives an order to be created
    //     *@param order the list of orders to be implemented
    //     *@param waiterUUID the waiter the order is from
    //     */
    //     void receiveOrder(std::vector<std::shared_ptr<Order>> order, std::string waiterUUID);

    //     /** 
    //     *@brief sets the POS attribute
    //     *@param pos the new POS
    //     */
    //     void setPOS(std::shared_ptr<POS> pos);

    //     /** 
    //     *@brief returns this chef's POS
    //     *@return std::shared_ptr<POS>
    //     */
    //     std::shared_ptr<POS> getPOS();

};

#endif