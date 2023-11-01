#ifndef ADDTOMATO_HPP
#define ADDTOMATO_HPP

#include "Order.hpp"

class AddTomato : public Order {
public:
    bool executeOrder();
};

#endif