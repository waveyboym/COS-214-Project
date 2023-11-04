/**
 * @file AddJuice.hpp
 * @author Lunga
 * @brief AddJuice, a ConcreteCommand of the Command(Order Class)
 * @version 0.1
 * @date 2023-11-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ADDJUICE_HPP
#define ADDJUICE_HPP

#include "Order.hpp"

class AddJuice : public Order {
    public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif