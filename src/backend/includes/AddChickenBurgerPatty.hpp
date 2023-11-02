#ifndef ADDCHICKENBURGERPATTY_HPP
#define ADDCHICKENBURGERPATTY_HPP

#include "Order.hpp"

class AddChickenBurgerPatty :public Order{
    public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};


#endif