/**
 * @file Order.hpp Order.cpp
 * @class Order.hpp
 * @author Lunga
 * @brief Order(Command), Abstract Class. Interface in Command Pattern
 */
#ifndef ORDER_HPP
#define ORDER_HPP

#include "Meal.hpp"
#include "Bun.hpp"
#include "Ingredient.hpp"
#include "ConcreteBuns.hpp"
#include "ConcreteIngredients.hpp"

class Order {
    public:
        /**
         * @brief std::shared<ptr> meal allows for an Order's associated Meal to be set or specified.
         */
        std::shared_ptr<Meal> meal;
        /**
         * @brief addedToList is boolean which checks whether the Order has already been handled with in the Kitchen class
         */
        bool addedToList = false;
        /**
         * @brief pure virtual implementation of executeOrder(std::share_ptr<Meal>), required by relevant child classes to implement.
         * @param m 
         * @return std::shared_ptr<Meal> 
         */
        virtual std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m) = 0;
        /**
         * @brief Destroy the Order object
         * 
         */
        virtual ~Order();
};

#endif