#ifndef ADDNORMALBUN_HPP
#define ADDNORMALBUN_HPP

#include "Order.hpp"

class AddNormalBun :public Order{
    public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif