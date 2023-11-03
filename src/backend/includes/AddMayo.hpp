/**
 * @file AddMayo.hpp
 * @author Lunga
 * @brief AddMayo, a ConcreteCommand of the Command(Order Class)
 * @version 0.1
 * @date 2023-11-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ADDMAYO_HPP
#define ADDMAYO_HPP

#include "Order.hpp"

class AddMayo : public Order {
public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif