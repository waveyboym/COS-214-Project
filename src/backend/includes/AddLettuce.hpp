#ifndef ADDLETTUCE_HPP
#define ADDLETTUCE_HPP

#include "Order.hpp"

class AddLettuce : public Order {
public:
    std::shared_ptr<Meal> executeOrder();
};

#endif