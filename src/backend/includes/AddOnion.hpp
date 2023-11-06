/**
 * @file AddOnion.hpp AddOnion.cpp
 * @class AddOnion
 * @author Lunga
 * @implements Order
 * @brief AddBBQSauce, a ConcreteCommand of the Command(Order Class)
 */
#ifndef ADDONION_HPP
#define ADDONION_HPP

#include "Order.hpp"
/**
 * @brief AddLettuce class, which inherits from the Order interface.A ConcreteCommand which aides in generating a new Lettuce Ingredient.
 */
class AddOnion : public Order {
public:
/**
 * @brief creates a Onion Ingredient and Passes a std::shared_ptr<Meal> as the "next" of the "ingredient" of the Meal
 * @param m 
 * @return std::shared_ptr<Meal> 
 */
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif