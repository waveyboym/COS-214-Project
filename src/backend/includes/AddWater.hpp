/**
 * @file AddWater.hpp
 * @author Lunga
 * @brief AddWater, a ConcreteCommand of the Command(Order Class)
 * @version 0.1
 * @date 2023-11-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ADDWATER_HPP
#define ADDWATER_HPP

#include "Order.hpp"

class AddWater : public Order {
public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif