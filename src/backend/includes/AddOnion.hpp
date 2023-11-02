#ifndef ADDONION_HPP
#define ADDONION_HPP

#include "Order.hpp"

class AddOninion : public Order {
public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif