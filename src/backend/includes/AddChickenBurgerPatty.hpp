/**
 * @file AddChickenBurgerPatty.hpp AddChickenBurgerPatty.hpp
 * @class AddChickenBurgerPatty
 * @author Lunga
 * @implements Order
 * @brief AddChickenBurgerPatty, a ConcreteCommand of the Command(Order Class)
 */
#ifndef ADDCHICKENBURGERPATTY_HPP
#define ADDCHICKENBURGERPATTY_HPP

#include "Order.hpp"
/**
 * @brief AddChickenBurgerPatty class, which inherits from the Order interface.A ConcreteCommand which aides in generating a new ChickenPatty Ingredient.
 */
class AddChickenBurgerPatty :public Order{
    public:
/**
 * @brief creates a ChickenPatty Ingredient and Passes a std::share_pte<Meal> as the "next" of the "ingredient" of the Meal
 * @param m 
 * @return std::shared_ptr<Meal> 
 */
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};


#endif