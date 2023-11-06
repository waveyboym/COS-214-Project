/**
 * @file AddJuice.hpp AddJuice.cpp
 * @class AddJuice
 * @author Lunga
 * @implements Order
 * @brief AddJuice, a ConcreteCommand of the Command(Order Class)
 */
#ifndef ADDJUICE_HPP
#define ADDJUICE_HPP

#include "Order.hpp"
/**
 * @brief AddJuice class, which inherits from the Order interface.A ConcreteCommand which aides in generating a new Juice Ingredient.
 */
class AddJuice : public Order {
    public:
/**
 * @brief creates a Juice Ingredient and Passes a std::share_pte<Meal> as the "next" of the "ingredient" of the Meal
 * @param m 
 * @return std::shared_ptr<Meal> 
 */
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif