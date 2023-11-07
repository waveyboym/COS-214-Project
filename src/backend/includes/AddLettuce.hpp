/**
 * @file AddLettuce.hpp AddLettuce.cpp
 * @class AddLettuce
 * @author Lunga
 * @implements Order
 * @brief AddLettuce, a ConcreteCommand of the Command(Order Class)
 */
#ifndef ADDLETTUCE_HPP
#define ADDLETTUCE_HPP

#include "Order.hpp"
/**
 * @brief AddLettuce class, which inherits from the Order interface.A ConcreteCommand which aides in generating a new Lettuce Ingredient.
 */
class AddLettuce : public Order {
/**
 * @brief creates a Lettuce Ingredient and Passes a std::share_pte<Meal> as the "next" of the "ingredient" of the Meal
 * @param m 
 * @return std::shared_ptr<Meal> 
 */
public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif