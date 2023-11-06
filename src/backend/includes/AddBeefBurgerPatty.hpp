/**
 * @file AddBeefBurgerPatty.hpp AddBeefBurgerPatty.cpp
 * @class AddBeefBurgerPatty
 * @author Lunga
 * @implements Order
 * @brief AddBeefBurger, a ConcreteCommand of the Command(Order Class)
 */
#ifndef ADDBEEFBURGERPATTY_HPP
#define ADDBEEFBURGERPATTY_HPP

#include "Order.hpp"
/**
 * @brief AddBeefBurgerPatty Class,which inherits from the Order interface.A ConcreteCommand which aides in generating a new BeefPatty Ingredient.
 */
class AddBeefBurgerPatty : public Order {
public:
/**
 * @brief creates a BeefPatty Ingredient and Passes a std::share_pte<Meal> as the "next" of the "ingredient" of the Meal
 * @param m 
 * @return std::shared_ptr<Meal> 
 */
std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif