/**
 * @file AddOnion.hpp
 * @author Lunga
 * @brief AddBBQSauce, a ConcreteCommand of the Command(Order Class)
 * @version 0.1
 * @date 2023-11-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ADDONION_HPP
#define ADDONION_HPP

#include "Order.hpp"

class AddOnion : public Order {
public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif