/**
 * @file AddNoBun.hpp AddNoBun.cpp
 * @class AddNoBun
 * @author Lunga
 * @implements Order
 * @brief AddNoBun, a ConcreteCommand of the Command(Order Class)
 */

#ifndef ADDNOBUN_HPP
#define ADDNOBUN_HPP

#include "Order.hpp"
/**
 * @brief AddNoBun class, which inherits from the Order interface.A ConcreteCommand which aides in generating a new NoBun Ingredient.
 */
class AddNoBun: public Order{
public:
    /**
    * @brief creates a NoBun Ingredient and Passes a std::share_pte<Meal> as the "next" of the "ingredient" of the Meal
    * @param m 
    * @return std::shared_ptr<Meal> 
    */
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif