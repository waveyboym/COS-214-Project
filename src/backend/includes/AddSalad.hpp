#ifndef ADDSALAD_HPP
#define ADDSALAD_HPP

#include "Order.hpp"

class AddSalad : public Order {
public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif