/**
 * @file Order.hpp
 * @author Lunga
 * @brief Order(Command), Abstract Class. Interface in Command Pattern
 * @version 0.1
 * @date 2023-11-03
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef ORDER_HPP
#define ORDER_HPP

#include "Meal.hpp"
#include "Bun.hpp"
#include "Ingredient.hpp"
#include "ConcreteBuns.hpp"
#include "ConcreteIngredients.hpp"
#include "Customer.hpp"



class Order {
protected:
    // std::shared
    std::shared_ptr<Meal> meal;

public:
    bool addedToList = false;
    virtual std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m) = 0;
    virtual ~Order();
};

#endif