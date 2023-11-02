#ifndef ADDWATER_HPP
#define ADDWATER_HPP

#include "Order.hpp"

class AddWater : public Order {
public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif