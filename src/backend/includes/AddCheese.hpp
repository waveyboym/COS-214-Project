#ifndef ADDCHEESE_HPP
#define ADDCHEESE_HPP

#include "Order.hpp"

class AddCheese : public Order{
    public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif