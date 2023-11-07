/**
 * @file AddWholeWheatBun.hpp AddWholeWheatBun.cpp
 * @class AddWholeWheatBun
 * @author Lunga
 * @brief AddWholeWheat, a ConcreteCommand of the Command(Order Class)
 * @implements Order
 * 
 */
#ifndef ADDWHOLEWHEATBUN_HPP
#define ADDWHOLEWHEATBUN_HPP

#include "Order.hpp"

/**
 *@brief AddWholeWheat, a ConcreteCommand of the Command(Order Class)
*/
class AddWholeWheatBun : public Order {
public:
    /**
     * @brief creates a WholeWeatBun Ingredient and Passes a std::shared_ptr<Meal> as the "next" of the "ingredient" of the Meal
     * @param m 
     * @return std::shared_ptr<Meal> 
     */
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif