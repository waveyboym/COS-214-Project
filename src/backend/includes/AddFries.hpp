/**
 * @file AddFries.hpp
 * @author Lunga
 * @brief AddFries, a ConcreteCommand of the Command(Order Class)
 * @version 0.1
 * @date 2023-11-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ADDFRIES_HPP
#define ADDFRIES_HPP

#include "Order.hpp"

class AddFries : public Order {
public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif