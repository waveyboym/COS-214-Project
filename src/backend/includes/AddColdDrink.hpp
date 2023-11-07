/**
 * @file AddColdDrink.hpp AddColdDrink.cpp
 * @class AddColdDrink
 * @author Lunga
 * @implements Order
 * @brief AddColdDrink, a ConcreteCommand of the Command(Order Class)
 
 */
#ifndef ADDCOLDDRINK
#define ADDCOLDDRINK

#include "Order.hpp"
/**
 * @brief AddColdDrink class, which inherits from the Order interface.A ConcreteCommand which aides in generating a new ColdDrink Ingredient.
 */
class AddColdDrink : public Order {
    public:
/**
 * @brief creates a ColdDrink Ingredient and Passes a std::share_pte<Meal> as the "next" of the "ingredient" of the Meal
 * @param m 
 * @return std::shared_ptr<Meal> 
 */
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal>);
};

#endif