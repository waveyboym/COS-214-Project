/**
 * @file AddWater.hpp AddWater.cpp
 * @class AddWater
 * @author Lunga
 * @implements Order
 * @brief AddWater, a ConcreteCommand of the Command(Order Class)
 */

#ifndef ADDWATER_HPP
#define ADDWATER_HPP

#include "Order.hpp"
/**
 * @brief AddWater class, which inherits from the Order interface.A ConcreteCommand which aides in generating a new Water Ingredient.
 */
class AddWater : public Order {
public:
    /**
    * @brief creates a Water Ingredient and Passes a std::share_pte<Meal> as the "next" of the "ingredient" of the Meal
    * @param m 
    * @return std::shared_ptr<Meal> 
    */
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif