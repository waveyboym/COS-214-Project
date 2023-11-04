/**
 * @file AddBBQSauce.hpp
 * @author Lunga
 * @brief AddBBQSauce, a ConcreteCommand of the Command(Order Class)
 * @version 0.1
 * @date 2023-11-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ADDBBQSAUCE_HPP
#define ADDBBQSUACE_HPP

#include "Order.hpp"

class AddBBQSauce :public Order {
public:
/**
 * @brief Creates a BBQSauce Ingredient and Passes a std::share_pte<Meal> has the "next" of the "ingredient" of the Meal
 * 
 * @param m 
 * @return std::shared_ptr<Meal> 
 */
AddBBQSauce();
std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif