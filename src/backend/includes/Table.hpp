/**
 *@file Table.hpp Table.cpp
 *@class Table
 *@author Michael
 *@implements Collectable
 *@brief a Table class which is a component class of Collectable
 */
#ifndef TABLE_HPP
#define TABLE_HPP
#include <list>
#include <memory>
#include <list>
#include <string>

#include "Collectable.hpp"
#include "Customer.hpp"

/**
 *@brief a Table class which is a component class of Collectable
 */
class Table : public Collectable {
protected:
    /**
     *@brief whether or not this table is currently assigned a waiter
     */
    bool assigned_a_waiter = false;
    /**
     *@brief id of this table
     */
    int table_id = -1;
    /**
     *@brief id of the waiter assigned to this table
     */
    std::string waiter_uuid = "";
    /**
     *@brief id of the customer that reserved this table
     */
    std::string reserver_uuid = "";

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
    /**
     *@brief checks if this table is occupied
     *@param none
     *@return bool
     */
    virtual bool isTableAvailable() = 0;
    /**
     *@brief checks if this table is assigned a waiter
     *@param none
     *@return bool
     */
    bool isAssignedAWaiter();
    /**
     *@brief sets whether or not this table is assigned to a waiter
     *@param set_to assign to set to
     *@return void
     */
    void setIsAssignedAWaiter(bool set_to);
    /**
     *@brief gets the id of this table
     *@param none
     *@return int
     */
    int getTableID();
    /**
     *@brief sets the id of this table
     *@note this should only be set once when this object is created
     *@param set_to id to set to
     *@return void
     */
    void setID(int set_to);
    /**
     *@brief gets the id of the waiter assigned to this table
     *@param none
     *@return std::string
     */
    std::string getAssignedWaiterID();
    /**
     *@brief sets the id of the waiter who has been assigned to this table
     *@param set_to id to set to
     *@return void
     */
    void setWaiterID(std::string set_to);
    /**
     * @brief Get the ID of the customer that reserved this table.
     * @return std::string The customer's ID.
     */
    std::string getReserverUUID() const {
        return reserver_uuid;
    }

    /**
     * @brief Set the ID of the customer that reserved this table.
     * @param reserverID The customer's ID to set.
     */
    void setReserverUUID(const std::string& reserverID) {
        reserver_uuid = reserverID;
    }
};

#endif