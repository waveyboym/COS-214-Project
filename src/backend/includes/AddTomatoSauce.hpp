/**
 * @file AddTomatoSauce.hpp, AddTomatoSauce.cpp
 * @class AddTomatoSauce
 * @author Lunga
 * @implements Order
 * @brief AddTomatoSauce, a ConcreteCommand of the Command(Order Class)
 */
#ifndef ADDTOMATOSAUCE_HPP
#define ADDTOMATOSAUCE_HPP

#include "Order.hpp"
/**
 * @brief AddTomatoSauce Class,which inherits from the Order interface.A ConcreteCommand which aides in generating a new TomatoSauce Ingredient.
 */
class AddTomatoSauce:public Order{
public:
/**
 * @brief creates a TomatoSauce Ingredient and Passes a std::share_pte<Meal> as the "next" of the "ingredient" of the Meal
 * @param m 
 * @return std::shared_ptr<Meal> 
 */
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif