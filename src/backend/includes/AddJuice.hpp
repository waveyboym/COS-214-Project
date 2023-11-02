#ifndef ADDJUICE_HPP
#define ADDJUICE_HPP

#include "Order.hpp"

class AddJuice : public Order {
    public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif