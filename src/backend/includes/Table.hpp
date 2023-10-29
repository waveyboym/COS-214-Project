/**
*@file Table.hpp Table.cpp
*@class Table
*@author Michael
*@implements Collectable
*@brief a Table class which is a component class of Collectable
*/
#ifndef TABLE_HPP
#define TABLE_HPP
#include "Collectable.hpp"
#include "Customer.hpp"
#include <memory>
#include <list>

/** 
*@brief a Table class which is a component class of Collectable
*/ 
class Table : public Collectable{
    public:
        /** 
        *@brief a null function to allow for polymorphic features to be used
        *@param none
        *@return void
        */
        void nill();
        /** 
        *@brief seats a customer at this table
        *@param customer a customer to seat at this table
        *@return void
        */ 
        virtual void seatCustomer(std::shared_ptr<Customer> customer) = 0;
        /** 
        *@brief unseats a customer from this table
        *@param customer a customer to unseat from this table
        *@return void
        */ 
        virtual void unseatCustomer(std::shared_ptr<Customer> customer) = 0;
        /** 
        *@brief checks if the passed in customer is seated at this table
        *@param customer a customer to check if they are seated at this table
        *@return bool
        */ 
        virtual bool isSeatedHere(std::shared_ptr<Customer> customer) = 0;
        /** 
        *@brief gets all customers seated at this table
        *@param none
        *@return std::list<std::shared_ptr<Customer>>
        */ 
        virtual std::list<std::shared_ptr<Customer>> getAllSeatedCustomers() = 0;
};

#endif