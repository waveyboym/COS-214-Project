#ifndef ADDVEGGIEBURGERPATTY_HPP
#define ADDVEGGIEBURGERPATTY_HPP

#include "Order.hpp"

class AddVeggieBurgerPatty : public Order {
public:
    bool executeOrder();
};

#endif