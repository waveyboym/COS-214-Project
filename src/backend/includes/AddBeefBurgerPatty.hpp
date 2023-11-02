#ifndef ADDBEEFBURGERPATTY_HPP
#define ADDBEEFBURGERPATTY_HPP

#include "Order.hpp"

class AddBeefBurgerPatty : public Order {
public:
std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif