/**
 * @file AddLettuce.hpp
 * @author Lunga
 * @brief AddBBQSauce, a ConcreteCommand of the Command(Order Class)
 * @version 0.1
 * @date 2023-11-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ADDLETTUCE_HPP
#define ADDLETTUCE_HPP

#include "Order.hpp"

class AddLettuce : public Order {
public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif