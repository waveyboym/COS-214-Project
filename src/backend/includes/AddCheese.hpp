/**
 * @file AddCheese.hpp AddCheese.cpp
 * @class AddCheese
 * @author Lunga
 * @implements Order
 * @brief AddCheese, a ConcreteCommand of the Command(Order Class)
 */
#ifndef ADDCHEESE_HPP
#define ADDCHEESE_HPP

#include "Order.hpp"
/**
 * @brief AddCheese class, which inherits from the Order interface.A ConcreteCommand which aides in generating a new Cheese Ingredient.
 */
class AddCheese : public Order{
    public:
/**
 * @brief creates a Cheese Ingredient and Passes a std::share_pte<Meal> as the "next" of the "ingredient" of the Meal
 * @param m 
 * @return std::shared_ptr<Meal> 
 */
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif