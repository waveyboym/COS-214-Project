/**
 * @file AddTomato.hpp AddTomato.cpp
 * @class AddTomato
 * @author Lunga
 * @implements Order
 * @brief AddTomato, a ConcreteCommand of the Command(Order Class)
 */

#ifndef ADDTOMATO_HPP
#define ADDTOMATO_HPP

#include "Order.hpp"
/**
 * @brief AddTomato class, which inherits from the Order interface.A ConcreteCommand which aides in generating a new Tomato Ingredient.
 */
class AddTomato : public Order {
public:
    /**
     * @brief creates a Tomato Ingredient and Passes a std::share_pte<Meal> as the "next" of the "ingredient" of the Meal
    * @param m 
    * @return std::shared_ptr<Meal> 
    */
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif