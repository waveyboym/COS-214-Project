#ifndef ADDPINEAPPLE_HPP
#define ADDPINEAPPLE_HPP

#include "Order.hpp"

class AddPineApple : public Order {
public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif