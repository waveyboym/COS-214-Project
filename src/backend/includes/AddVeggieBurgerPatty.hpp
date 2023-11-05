/**
 * @file AddVeggieBurgerPatty.hpp
 * @author Lunga
 * @brief AddVeggieBurgerPatty, a ConcreteCommand of the Command(Order Class)
 * @version 0.1
 * @date 2023-11-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ADDVEGGIEBURGERPATTY_HPP
#define ADDVEGGIEBURGERPATTY_HPP

#include "Order.hpp"

class AddVeggieBurgerPatty : public Order {
public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif