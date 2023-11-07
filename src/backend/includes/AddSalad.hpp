/**
 * @file AddSalad.hpp AddSalad.cpp
 * @class AddSalad
 * @author Lunga
 * @implements Order
 * @brief AddSalad, a ConcreteCommand of the Command(Order Class)
 */
#ifndef ADDSALAD_HPP
#define ADDSALAD_HPP

#include "Order.hpp"
/**
 * @brief AddSalad class, which inherits from the Order interface.A ConcreteCommand which aides in generating a new Salad Ingredient.
 */
class AddSalad : public Order {
public:
/**
 * @brief creates a Salad Ingredient and Passes a std::shared_ptr<Meal> as the "next" of the "ingredient" of the Meal
 * @param m 
 * @return std::shared_ptr<Meal> 
 */
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif