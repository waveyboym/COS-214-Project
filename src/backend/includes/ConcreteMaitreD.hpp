/**
*@file ConcreteMaitreD.hpp ConcreteMaitreD.cpp
*@class ConcreteMaitreD
*@implements MaitreD
*@author Michael
*@brief defines a Concrete MaitreD which is responsible for observing a customer, seating a customer and assigning tables to a waiter
*/
#ifndef CONCRETE_MAITRE_D_HPP
#define CONCRETE_MAITRE_D_HPP
#include "MaitreD.hpp"
#include "Table.hpp"
#include "SingleTableIterator.hpp"
#include "JoinedTableIterator.hpp"
#include "Customer.hpp"
#include "Waiter.hpp"
#include "WaiterIterator.hpp"
#include <list>
#include <map>
#include <string>

/**
*@brief defines a Concrete MaitreD which is responsible for observing a customer, seating a customer and assigning tables to a waiter
*/
class ConcreteMaitreD : public MaitreD {
    public:
        /**
         *@brief constructor
        *@param none
        */
        ConcreteMaitreD();
        /**
         *@brief notifies the passed in person object
        *@note TODO: more detail is needed about this function. ISSUE ID: 17
        *@param person the person to notify
        *@return bool
        */
        bool notifyPerson(std::shared_ptr<People> person);
        /**
         *@brief seats the customer at an open table and returns success if an open table is found for the customer
        *@param restaurant_single_tables a reference list of tables at which a customer is to be seated
        *@param restaurant_joined_tables a reference list of tables at which a customer is to be seated
        *@param customer_to_seat a customer to seat in the restaurant
        *@return bool
        */
        bool seatCustomer(std::list<std::shared_ptr<SingleTable>>& restaurant_single_tables,std::list<std::shared_ptr<JoinedTable>>& restaurant_joined_tables,std::shared_ptr<Customer> customer_to_seat);

        /**
        *@brief un seats the customer from a table when they are done and returns success if they are unseated
        *@param restaurant_single_tables a reference list of tables at which to check if a customer is seated
        *@param restaurant_joined_tables a reference list of tables at which to check if a customer is seated
        *@param customer_to_unseat a customer to un-seat in the restaurant
        *@return bool
        */
        bool unseatCustomer(std::list<std::shared_ptr<SingleTable>>& restaurant_single_tables, std::list<std::shared_ptr<JoinedTable>>& restaurant_joined_tables, std::shared_ptr<Customer> customer_to_unseat, std::map<std::string, std::shared_ptr<Waiter>>& waiters);
        /**
        *@brief returns a list of open tables from the list of tables in the restaurant
        *@param restaurant_single_tables a reference list of tables at which a customer is to be seated
        *@param restaurant_joined_tables a reference list of tables at which a customer is to be seated
        *@return std::list<std::shared_ptr<Table>>
        */
        std::list<std::shared_ptr<Table>> availableTables(std::list<std::shared_ptr<SingleTable>>& restaurant_single_tables, std::list<std::shared_ptr<JoinedTable>>& restaurant_joined_tables);
        /**
        *@brief assigns a waiter to a table and returns true on success and false on failure
        *@param restaurant_single_tables a reference list of tables at which a customer is to be seated
        *@param restaurant_joined_tables a reference list of tables at which a customer is to be seated
        *@param waiter waiter to assign a job to
        *@return bool
        */
        bool assignWaiterToTable(std::list<std::shared_ptr<SingleTable>>& restaurant_single_tables, std::list<std::shared_ptr<JoinedTable>>& restaurant_joined_tables, std::shared_ptr<Waiter> waiter);

        /**
         *@brief reserves the a table for a customer
        *@param t Table to be reserved
        *@param c_uid uid of customer reserving the table
        *@return bool
        */
        bool reserveTable(std::shared_ptr<Table> t, std::string c_uid);
};

#endif
