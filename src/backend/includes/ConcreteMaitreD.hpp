/**
 *@file ConcreteMaitreD.hpp ConcreteMaitreD.cpp
 *@class ConcreteMaitreD
 *@implements MaitreD
 *@author Michael
 *@brief defines a Concrete MaitreD which is responsible for observing a
 *customer, seating a customer and assigning tables to a waiter
 */
#ifndef CONCRETE_MAITRE_D_HPP
#define CONCRETE_MAITRE_D_HPP
#include <list>
#include <map>
#include <string>

#include "Customer.hpp"
#include "JoinedTableIterator.hpp"
#include "MaitreD.hpp"
#include "SingleTableIterator.hpp"
#include "Table.hpp"
#include "Waiter.hpp"
#include "WaiterIterator.hpp"

<<<<<<< HEAD
/**
 *@brief defines a Concrete MaitreD which is responsible for observing a
 *customer, seating a customer and assigning tables to a waiter
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
     *@brief seats the customer at an open table and returns success if an open
     *table is found for the customer
     *@param restaurant_single_tables a reference list of tables at which a
     *customer is to be seated
     *@param restaurant_joined_tables a reference list of tables at which a
     *customer is to be seated
     *@param customer_to_seat a customer to seat in the restaurant
     *@return bool
     */
    bool seatCustomer(
        std::list<std::shared_ptr<SingleTable>>& restaurant_single_tables,
        std::list<std::shared_ptr<JoinedTable>>& restaurant_joined_tables,
        std::shared_ptr<Customer> customer_to_seat);

    /**
     *@brief un seats the customer from a table when they are done and returns
     *success if they are unseated
     *@param restaurant_single_tables a reference list of tables at which to
     *check if a customer is seated
     *@param restaurant_joined_tables a reference list of tables at which to
     *check if a customer is seated
     *@param customer_to_unseat a customer to un-seat in the restaurant
     *@return bool
     */
    bool unseatCustomer(
        std::list<std::shared_ptr<SingleTable>>& restaurant_single_tables,
        std::list<std::shared_ptr<JoinedTable>>& restaurant_joined_tables,
        std::shared_ptr<Customer> customer_to_unseat,
        std::map<std::string, std::shared_ptr<Waiter>>& waiters);
    /**
     *@brief returns a list of open tables from the list of tables in the
     *restaurant
     *@param restaurant_single_tables a reference list of tables at which a
     *customer is to be seated
     *@param restaurant_joined_tables a reference list of tables at which a
     *customer is to be seated
     *@return std::list<std::shared_ptr<Table>>
     */
    std::list<std::shared_ptr<Table>> availableTables(
        std::list<std::shared_ptr<SingleTable>>& restaurant_single_tables,
        std::list<std::shared_ptr<JoinedTable>>& restaurant_joined_tables);
    /**
     *@brief assigns a waiter to a table and returns true on success and false
     *on failure
     *@param restaurant_single_tables a reference list of tables at which a
     *customer is to be seated
     *@param restaurant_joined_tables a reference list of tables at which a
     *customer is to be seated
     *@param waiter waiter to assign a job to
     *@return bool
     */
    bool assignWaiterToTable(
        std::list<std::shared_ptr<SingleTable>>& restaurant_single_tables,
        std::list<std::shared_ptr<JoinedTable>>& restaurant_joined_tables,
        std::shared_ptr<Waiter> waiter);
    /**
     *@brief
     *@note TODO: more detail is needed about this function. ISSUE ID: 16
     *@param none
     *@return void
     */
    
    /**
     * @brief Reserves a table.
     *
     * @param T The table to reserve.
     * @param C The customer who is reserving the table.
     */
    bool reserveTable(std::shared_ptr<Table> T, std::shared_ptr<Customer> C);
=======
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
        *@brief 
        *@note TODO: more detail is needed about this function. ISSUE ID: 16
        *@param none
        *@return void
        */
        bool reserveTable(std::shared_ptr<Table> T,std::string C_uid);
>>>>>>> e36c27d3f464b4f49d037cf4a0399f5f5b6dc58a
};

#endif
