#ifndef ADDFRIES_HPP
#define ADDFRIES_HPP

#include "Order.hpp"

class AddFries : public Order {
public:
    bool executeOrder();
};

#endif