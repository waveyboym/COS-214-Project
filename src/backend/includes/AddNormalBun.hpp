/**
 * @file AddNormalBun.hpp
 * @author Lunga
 * @brief AddNormalBun, a ConcreteCommand of the Command(Order Class)
 * @version 0.1
 * @date 2023-11-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ADDNORMALBUN_HPP
#define ADDNORMALBUN_HPP

#include "Order.hpp"

class AddNormalBun :public Order{
    public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif