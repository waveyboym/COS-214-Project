/**
 * @file AddMayo.hpp AddMayo.cpp
 * @class AddMayo
 * @author Lunga
 * @implements Order
 * @brief AddMayo, a ConcreteCommand of the Command(Order Class)
 */
#ifndef ADDMAYO_HPP
#define ADDMAYO_HPP

#include "Order.hpp"
/**
 * @brief AddMayo Class,which inherits from the Order interface.A ConcreteCommand which aides in generating a new Mayo Ingredient.
 */
class AddMayo : public Order {
public:
/**
 * @brief creates a Mayo Ingredient and Passes a std::share_pte<Meal> as the "next" of the "ingredient" of the Meal
 * @param m 
 * @return std::shared_ptr<Meal> 
 */
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif