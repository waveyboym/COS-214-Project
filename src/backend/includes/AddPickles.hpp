/**
 * @file AddPickles.hpp AddPickle.cpp
 * @class AddPickles
 * @author Lunga
 * @implements Order
 * @brief AddPickles, a ConcreteCommand of the Command(Order Class)
 */
#ifndef ADDPICKLES_HPP
#define ADDPICKLES_HPP

#include "Order.hpp"

/**
 * @brief AddPickles class, which inherits from the Order interface.A ConcreteCommand which aides in generating a new Pickles Ingredient.
 */
class AddPickles : public Order {
public:
/**
 * @brief creates a Pickles Ingredient and Passes a std::shared_ptr<Meal> as the "next" of the "ingredient" of the Meal
 * @param m 
 * @return std::shared_ptr<Meal> 
 */
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif