/**
 * @file AddBBQSauce.hpp AddBBQSauce.cpp
 * @class AddBBQSauce.hpp
 * @author Lunga
 * @brief AddBBQSauce, a ConcreteCommand of the Command(Order Class)
 */

#ifndef ADDBBQSAUCE_HPP
#define ADDBBQSAUCE_HPP

#include "Order.hpp"
/**
 * @brief AddBBQSauce Class,which inherits from the Order interface.A ConcreteCommand which aides in generating a new BBQSauce Ingredient.
 */
class AddBBQSauce :public Order {
public:
/**
 * @brief creates a BBQSauce Ingredient and Passes a std::share_pte<Meal> as the "next" of the "ingredient" of the Meal
 * @param m 
 * @return std::shared_ptr<Meal> 
 */
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif