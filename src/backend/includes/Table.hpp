/**
<<<<<<< HEAD
 * @file Table.hpp Table.cpp
 * @class Table
 * @author Michael
 * @implements Collectable
 * @brief A Table class which is a component class of Collectable.
 *
 * The Table class represents a table in a restaurant, which can be assigned to customers and waiters.
 * It is a component of the Collectable hierarchy.
 */
#ifndef TABLE_HPP
#define TABLE_HPP

=======
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
>>>>>>> e36c27d3f464b4f49d037cf4a0399f5f5b6dc58a
#include <list>
#include <memory>
#include <string>

#include "Collectable.hpp"
#include "Customer.hpp"

/**
<<<<<<< HEAD
 * @brief A Table class which is a component class of Collectable.
=======
 *@brief a Table class which is a component class of Collectable
>>>>>>> e36c27d3f464b4f49d037cf4a0399f5f5b6dc58a
 */
class Table : public Collectable {
protected:
    /**
<<<<<<< HEAD
     * @brief Whether or not this table is currently assigned a waiter.
     */
    bool assigned_a_waiter = false;

    /**
     * @brief ID of this table.
     */
    int table_id = -1;

    /**
     * @brief ID of the waiter assigned to this table.
     */
    std::string waiter_uuid = "";

    /**
     * @brief Pointer to the customer who has reserved the table.
     */
    std::shared_ptr<Customer> ReservedBy = NULL;

public:
    /**
     * @brief A null function to allow for polymorphic features to be used.
     */
    void nill();

    /**
     * @brief Seats a customer at this table.
     * @param customer A customer to seat at this table.
     */
    virtual void seatCustomer(std::shared_ptr<Customer> customer) = 0;

    /**
     * @brief Unseats a customer from this table.
     * @param customer A customer to unseat from this table.
     */
    virtual void unseatCustomer(std::shared_ptr<Customer> customer) = 0;

    /**
     * @brief Checks if the passed-in customer is seated at this table.
     * @param customer A customer to check if they are seated at this table.
     * @return bool
     */
    virtual bool isSeatedHere(std::shared_ptr<Customer> customer) = 0;

    /**
     * @brief Gets all customers seated at this table.
     * @return std::list<std::shared_ptr<Customer>>
     */
    virtual std::list<std::shared_ptr<Customer>> getAllSeatedCustomers() = 0;

    /**
     * @brief Checks if this table is occupied.
     * @return bool
     */
    virtual bool isTableAvailable() = 0;

    /**
     * @brief Checks if this table is assigned a waiter.
     * @return bool
     */
    bool isAssignedAWaiter();

    /**
     * @brief Sets whether or not this table is assigned to a waiter.
     * @param set_to Assign to set to.
     */
    void setIsAssignedAWaiter(bool set_to);

    /**
     * @brief Gets the ID of this table.
     * @return int
     */
    int getTableID();

    /**
     * @brief Sets the ID of this table.
     * @note This should only be set once when this object is created.
     * @param set_to ID to set to.
     */
    void setID(int set_to);

    /**
     * @brief Gets the ID of the waiter assigned to this table.
     * @return std::string
     */
    std::string getAssignedWaiterID();

    /**
     * @brief Sets the ID of the waiter who has been assigned to this table.
     * @param set_to ID to set to.
     */
    void setWaiterID(std::string set_to);

    /**
     * @brief Sets the customer who has reserved this table.
     * @param ReservedBy A shared_ptr to the customer who has reserved the table.
     */
    virtual void setReservedBy(std::shared_ptr<Customer> ReservedBy);

    /**
     * @brief Gets the customer who has reserved this table.
     * @return std::shared_ptr<Customer>
     */
   virtual std::shared_ptr<Customer> getReservedBy();
   
=======
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
>>>>>>> e36c27d3f464b4f49d037cf4a0399f5f5b6dc58a
};

#endif
