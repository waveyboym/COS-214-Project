#ifndef ADDPICKLES_HPP
#define ADDPICKLES_HPP

#include "Order.hpp"

class AddPickles : public Order {
public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif