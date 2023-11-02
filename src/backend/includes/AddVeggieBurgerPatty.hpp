#ifndef ADDVEGGIEBURGERPATTY_HPP
#define ADDVEGGIEBURGERPATTY_HPP

#include "Order.hpp"

class AddVeggieBurgerPatty : public Order {
public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif