#ifndef ADDTOMATOSAUCE_HPP
#define ADDTOMATOSAUCE_HPP

#include "Order.hpp"

class AddTomatoSauce:public Order{
public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif