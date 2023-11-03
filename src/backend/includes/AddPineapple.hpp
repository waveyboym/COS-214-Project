/**
 * @file AddPineapple.hpp
 * @author Lunga
 * @brief AddPineapple, a ConcreteCommand of the Command(Order Class)
 * @version 0.1
 * @date 2023-11-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ADDPINEAPPLE_HPP
#define ADDPINEAPPLE_HPP

#include "Order.hpp"

class AddPineApple : public Order {
public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif