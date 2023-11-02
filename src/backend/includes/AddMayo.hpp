#ifndef ADDMAYO_HPP
#define ADDMAYO_HPP

#include "Order.hpp"

class AddMayo : public Order {
public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif