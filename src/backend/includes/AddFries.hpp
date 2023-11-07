/**
 * @file AddFries.hpp AddFries.cpp
 * @class AddFries
 * @author Lunga
 * @implements Order
 * @brief AddFries, a ConcreteCommand of the Command(Order Class)
 */
#ifndef ADDFRIES_HPP
#define ADDFRIES_HPP

#include "Order.hpp"
/**
 * @brief AddFries class, which inherits from the Order interface.A ConcreteCommand which aides in generating a new Fries Ingredient.
 */
class AddFries : public Order {
public:
/**
 * @brief creates a Fries Ingredient and Passes a std::share_pte<Meal> as the "next" of the "ingredient" of the Meal
 * @param m 
 * @return std::shared_ptr<Meal> 
 */
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif