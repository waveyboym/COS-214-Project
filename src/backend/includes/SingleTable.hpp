/**
*@file SingleTable.hpp SingleTable.cpp
*@class SingleTable
*@author Michael
*@implements Table
*@brief a SingleTable class which is a leaf class of Table
*/
#ifndef SINGLE_TABLE_HPP
#define SINGLE_TABLE_HPP
#include "Table.hpp"

/** 
*@brief an SingleTable class which is a leaf class of Table
*/ 
class SingleTable : public Table{
    private:
        /** 
        *@brief a list containing all customers seated at this table
        */ 
        std::list<std::shared_ptr<Customer>> customer_list;
    public:
        /** 
        *@brief constructor
        *@param none
        */ 
        SingleTable();
        /** 
        *@brief constructor
        *@param tableid id of this table
        */ 
        SingleTable(int tableid);
        /** 
        *@brief seats a customer at this table
        *@param customer a customer to seat at this table
        *@return void
        */ 
        void seatCustomer(std::shared_ptr<Customer> customer);
        /** 
        *@brief unseats a customer from this table
        *@param customer a customer to unseat from this table
        *@return void
        */ 
        void unseatCustomer(std::shared_ptr<Customer> customer);
        /** 
        *@brief checks if the passed in customer is seated at this table
        *@param customer a customer to check if they are seated at this table
        *@return bool
        */ 
        bool isSeatedHere(std::shared_ptr<Customer> customer);
        /** 
        *@brief gets all customers seated at this table
        *@param none
        *@return std::list<std::shared_ptr<Customer>>
        */ 
        std::list<std::shared_ptr<Customer>> getAllSeatedCustomers();
        /** 
        *@brief checks if this table is occupied
        *@param none
        *@return bool
        */ 
        bool isTableAvailable();
};

#endif