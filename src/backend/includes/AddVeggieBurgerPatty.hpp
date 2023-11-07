/**
 * @file AddVeggieBurgerPatty.hpp AddVeggieBurgerPatty.cpp
 * @class AddVeggieBurgerPatty
 * @author Lunga
 * @brief AddVeggieBurgerPatty, a ConcreteCommand of the Command(Order Class)
 * @implements Order
 */
#ifndef ADDVEGGIEBURGERPATTY_HPP
#define ADDVEGGIEBURGERPATTY_HPP

#include "Order.hpp"

/**
 *@brief AddVeggieBurgerPatty, a ConcreteCommand of the Command(Order Class)
*/
class AddVeggieBurgerPatty : public Order {
public:
    /**
     * @brief creates a Veggie Burger Patty Ingredient and Passes a std::shared_ptr<Meal> as the "next" of the "ingredient" of the Meal
     * @param m 
     * @return std::shared_ptr<Meal> 
     */
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif