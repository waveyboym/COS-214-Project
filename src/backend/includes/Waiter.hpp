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
};

#endif
