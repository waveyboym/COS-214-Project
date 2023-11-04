/**
 * @file AddWholeWheatBun.hpp
 * @author Lunga
 * @brief AddWholeWheat, a ConcreteCommand of the Command(Order Class)
 * @version 0.1
 * @date 2023-11-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ADDWHOLEWHEATBUN_HPP
#define ADDWHOLEWHEATBUN_HPP

#include "Order.hpp"

class AddWholeWheatBun : public Order {
public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif