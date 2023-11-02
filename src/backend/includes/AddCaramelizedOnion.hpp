#ifndef ADDCARAMELIZEDONION_HPP
#define ADDCARAMELIZEDONION_HPP

#include "Order.hpp"

class AddCaramelizedOnion : public Order {
public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif