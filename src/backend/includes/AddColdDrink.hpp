/**
 * @file AddColdDrink.hpp
 * @author Lunga
 * @brief AddColdDrink, a ConcreteCommand of the Command(Order Class)
 * @version 0.1
 * @date 2023-11-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ADDCOLDDRINK
#define ADDCOLDDRINK

#include "Order.hpp"

class AddColdDrink : public Order {
    public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal>);
};

#endif