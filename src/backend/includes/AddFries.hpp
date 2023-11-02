#ifndef ADDFRIES_HPP
#define ADDFRIES_HPP

#include "Order.hpp"

class AddFries : public Order {
public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif