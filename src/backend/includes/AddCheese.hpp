/**
 * @file AddCheese.hpp
 * @author Lunga
 * @brief AddCheese, a ConcreteCommand of the Command(Order Class)
 * @version 0.1
 * @date 2023-11-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ADDCHEESE_HPP
#define ADDCHEESE_HPP

#include "Order.hpp"

class AddCheese : public Order{
    public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif