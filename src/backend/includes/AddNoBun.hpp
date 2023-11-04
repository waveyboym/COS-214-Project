/**
 * @file AddNoBun.hpp
 * @author Lunga
 * @brief AddNoBun, a ConcreteCommand of the Command(Order Class)
 * @version 0.1
 * @date 2023-11-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ADDNOBUN_HPP
#define ADDNOBUN_HPP

#include "Order.hpp"

class AddNoBun: public Order{
    public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif