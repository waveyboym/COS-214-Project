/**
 * @file AddBeefBurgerPatty.hpp
 * @author Lunga
 * @brief AddBeefBurger, a ConcreteCommand of the Command(Order Class)
 * @version 0.1
 * @date 2023-11-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ADDBEEFBURGERPATTY_HPP
#define ADDBEEFBURGERPATTY_HPP

#include "Order.hpp"

class AddBeefBurgerPatty : public Order {
public:
std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif