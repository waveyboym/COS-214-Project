#ifndef ADDWATER_HPP
#define ADDWATER_HPP

#include "Order.hpp"

class AddWater : public Order {
public:
    bool executeOrder();
};

#endif