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
#include "Table.hpp"  // Keep the "Table.hpp" inclusion
#include "Order.hpp"
#include "JoinedTable.hpp"
#include <memory>
#include <string>

/** 
 * @brief A waiter object.
 */
class Waiter : public People {
private:
    bool is_assigned_table = false;
    int assigned_table_id = -1;
    std::shared_ptr<Order> order;

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

    /** 
     * @brief Joins two tables together regardless of them being a single table or a joined table.
     * @param table_to_join_to Table that will have another table joined to it.
     * @param table_to_join Table that will be joined to another table.
     * @return void
     */
    void joinTables(std::shared_ptr<JoinedTable> table_to_join_to, std::shared_ptr<Table> table_to_join);
};

#endif
