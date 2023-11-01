#ifndef ADDJUICE_HPP
#define ADDJUICE_HPP

#include "Order.hpp"

class AddJuice : public Order {
    public:
    bool executeOrder();
};

#endif