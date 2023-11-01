#ifndef ADDBEEFBURGERPATTY_HPP
#define ADDBEEFBURGERPATTY_HPP

#include "Order.hpp"

class AddBeefBurgerPatty : public Order {
public:
    bool executeOrder();
};

#endif