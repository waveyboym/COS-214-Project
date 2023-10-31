/**
 * @file Waiter.hpp Waiter.cpp
 * @class Waiter
 * @author Michael
 * @implements People
 * @brief A waiter object.
 */
#ifndef WAITER_HPP
#define WAITER_HPP
#include "People.hpp"
<<<<<<< HEAD
#include "Table.hpp"
//#include "Orders.hpp"
#include <memory>
#include <string>

/**
 * @brief A waiter object.
 */
class Waiter : public People {
private:
public:
    /**
     * @brief Constructor with no parameters.
     */
    Waiter();

    /**
     * @brief Constructor with a waiter UUID.
     * @param waiteruuid The UUID of this waiter.
     */
    Waiter(std::string waiteruuid);

    /**
     * @brief Specifies the action performed by the waiter.
     * @return bool
     */
    bool personAction();

    /**
     * @brief Checks if the waiter is assigned to a table.
     * @return bool
     */
    bool isAssignedATable();

    /**
     * @brief Sets whether the waiter is assigned to a table.
     * @param set_to Value to set.
     */
    void setIsAssignedATable(bool set_to);

    /**
     * @brief Gets the ID of the table assigned to the waiter.
     * @return int
     */
    int getAssignedTableID();

    /**
     * @brief Assigns an ID to the waiter for the table they are assigned to.
     * @param set_to ID to set.
     */
    void assignID(int set_to);
=======
#include "Order.hpp"
#include "JoinedTable.hpp"
#include <memory>
#include <string>

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
        *@brief the table id that this waiter is assigned to
        */
        int assigned_table_id = -1;
        /** 
        *@brief order for this waiter to fulfill
        */
        std::shared_ptr<Order> order;
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
        *@brief joins two tables together regardless of them being a single table or a joined table
        *@param table_to_join_to table that will have another table be joined to it
        *@param table_to_join table that will be joined to another table
        *@return void
        */
        void joinTables(std::shared_ptr<JoinedTable> table_to_join_to, std::shared_ptr<Table> table_to_join);
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
>>>>>>> 579f5a0e258bfd12a1e22aeb73f5d471e5fa3840
};

#endif
