/**
 * @file AddCaramelizedOnion.hpp
 * @author Lunga
 * @brief AddCaramelizedOnion, a ConcreteCommand of the Command(Order Class)
 * @version 0.1
 * @date 2023-11-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ADDCARAMELIZEDONION_HPP
#define ADDCARAMELIZEDONION_HPP

#include "Order.hpp"

class AddCaramelizedOnion : public Order {
public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif