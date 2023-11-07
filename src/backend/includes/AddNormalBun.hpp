/**
 * @file AddNormalBun.hpp AddNormalBun.cpp
 * @class AddNormalBun
 * @author Lunga
 * @implements Order
 * @brief AddNormalBun, a ConcreteCommand of the Command(Order Class)
 */

#ifndef ADDNORMALBUN_HPP
#define ADDNORMALBUN_HPP

#include "Order.hpp"
/**
 * @brief AddNormalBun class, which inherits from the Order interface.A ConcreteCommand which aides in generating a new NormalBun Ingredient.
 */
class AddNormalBun :public Order{
public:
    /**
     * @brief creates a NormalBun Ingredient and Passes a std::share_pte<Meal> as the "next" of the "ingredient" of the Meal
    * @param m 
    * @return std::shared_ptr<Meal> 
    */
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif