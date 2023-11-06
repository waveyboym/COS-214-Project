/**
 * @file AddCaramelizedOnion.hpp AddCaramelizedOnion.cpp
 * @class AddCaramelizedOnion
 * @author Lunga
 * @implements Order
 * @brief AddCaramelizedOnion, a ConcreteCommand of the Command(Order Class)
 */
#ifndef ADDCARAMELIZEDONION_HPP
#define ADDCARAMELIZEDONION_HPP

#include "Order.hpp"
/**
 * @brief AddCaramelizedOnion class, which inherits from the Order interface.A ConcreteCommand which aides in generating a new CaramelizedOnion Ingredient.
 */
class AddCaramelizedOnion : public Order {
public:
/**
 * @brief creates a CaramelizedOnion Ingredient and Passes a std::share_pte<Meal> as the "next" of the "ingredient" of the Meal
 * @param m 
 * @return std::shared_ptr<Meal> 
 */
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif