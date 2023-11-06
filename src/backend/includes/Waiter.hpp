/**
*@file Waiter.hpp Waiter.cpp
*@class Waiter
*@author Michael
*@implements People
*@brief a waiter object
*/
#ifndef WAITER_HPP
#define WAITER_HPP
#include "People.hpp"
#include "Table.hpp"
#include "Meal.hpp"
#include "color.hpp"
#include "MainBill.hpp"
#include "SubBill.hpp"
#include <memory>
#include <string>
#include <vector>
#include <cstdlib>

/** 
*@brief a waiter object
*/
class Waiter : public People{
    private:
        /** 
        *@brief whether or not this waiter is assigned a table
        */
        bool is_assigned_table = false;
        /** 
        *@brief whether or not this waiter has orders
        */
        bool has_orders = false;
        /** 
        *@brief the table id that this waiter is assigned to
        */
        int assigned_table_id = -1;
        /** 
        *@brief the table that this waiter is assigned to
        */
        std::shared_ptr<Table> my_table = nullptr;
        /** 
        *@brief orders for this waiter to fulfill
        */
        std::vector<std::pair<std::vector<std::shared_ptr<Order>>, std::shared_ptr<Customer>>> order;
    public:
        /** 
        *@brief constructor
        *@param none
        */
        Waiter();
        /** 
        *@brief constructor
        *@param waiteruuid the uuid of this waiter
        */
        Waiter(std::string waiteruuid);
        /** 
        *@brief 
        *@param none
        *@return bool
        */
        bool personAction();
        /** 
        *@brief returns a bool indicating whether this waiter has been assigned a table or not
        *@param none
        *@return bool
        */
        bool isAssignedATable();
        /** 
        *@brief set whether or not this waiter is assigned to a table
        *@param set_to the bool value to set to
        *@return bool
        */
        void setIsAssignedATable(bool set_to);
        /** 
        *@brief gets the id that this waiter is assigned to
        *@param none
        *@return int
        */ 
        int getAssignedTableID();
        /** 
        *@brief assigns this waiter an id of a table for them to serve
        *@param set_to id to set to
        *@return void
        */ 
        void assignID(int set_to);
        /** 
        *@brief assigns this waiter a table for them to serve
        *@param set_to table to set to
        *@return void
        */ 
        void assignTable(std::shared_ptr<Table> set_to);
        /** 
        *@brief getAssignedTable
        *@param none
        *@return std::shared_ptr<Table>
        */ 
        std::shared_ptr<Table> getTable();
        /** 
        *@brief alerts this waiter to check the kitchen for new food. Given a list of new_meals it will deliver any meals that belong to one of the customers it is serving.
        *@param new_meals the meals that have been recently prepared
        *@return void
        */ 
        void getUpdate(std::vector<std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>>> new_meals);
        /**
        *@brief waiter takes customer's order
        *@param std::shared_ptr<Customer>
        *@return void 
        */
        void takeOrder(std::shared_ptr<Customer> customer);
        /**
        *@brief pops and returns order from vector
        *@param none
        *@return  std::pair<std::vector<std::shared_ptr<Order>>, std::shared_ptr<Customer>>
        */
        std::pair<std::vector<std::shared_ptr<Order>>, std::shared_ptr<Customer>> sendOrder();
        /** 
        *@brief returns a bool indicating whether this waiter has orders
        *@param none
        *@return bool
        */
        bool getHasOrders();
};

#endif