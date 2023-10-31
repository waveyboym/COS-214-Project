/**
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

#include <list>
#include <memory>
#include <string>

#include "Collectable.hpp"
#include "Customer.hpp"

/**
 * @brief A Table class which is a component class of Collectable.
 */
class Table : public Collectable {
protected:
    /**
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
   
};

#endif
