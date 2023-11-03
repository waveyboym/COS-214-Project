/**
 * @file AddChickenBurgerPatty.hpp
 * @author Lunga
 * @brief AddChickenBurgerPatty, a ConcreteCommand of the Command(Order Class)
 * @version 0.1
 * @date 2023-11-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ADDCHICKENBURGERPATTY_HPP
#define ADDCHICKENBURGERPATTY_HPP

#include "Order.hpp"

class AddChickenBurgerPatty :public Order{
    public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};


#endif