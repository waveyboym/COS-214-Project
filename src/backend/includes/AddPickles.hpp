/**
 * @file AddPickles.hpp
 * @author Lunga
 * @brief AddPickles, a ConcreteCommand of the Command(Order Class)
 * @version 0.1
 * @date 2023-11-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ADDPICKLES_HPP
#define ADDPICKLES_HPP

#include "Order.hpp"

class AddPickles : public Order {
public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif