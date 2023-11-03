/**
 * @file AddTomato.hpp
 * @author Lunga
 * @brief AddTomato, a ConcreteCommand of the Command(Order Class)
 * @version 0.1
 * @date 2023-11-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ADDTOMATO_HPP
#define ADDTOMATO_HPP

#include "Order.hpp"

class AddTomato : public Order {
public:
std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif