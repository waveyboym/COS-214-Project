/**
 * @file AddPineapple.hpp AddPineapple.cpp
 * @class AddPineapple
 * @author Lunga
 * @implements Order
 * @brief AddPineapple, a ConcreteCommand of the Command(Order Class)
 */
#ifndef ADDPINEAPPLE_HPP
#define ADDPINEAPPLE_HPP

#include "Order.hpp"
/**
 * @brief AddPineapple class, which inherits from the Order interface.A ConcreteCommand which aides in generating a new Pineapple Ingredient.
 */
class AddPineApple : public Order {
public:
/**
 * @brief creates a Pineapple Ingredient and Passes a std::shared_ptr<Meal> as the "next" of the "ingredient" of the Meal
 * @param m 
 * @return std::shared_ptr<Meal> 
 */
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif