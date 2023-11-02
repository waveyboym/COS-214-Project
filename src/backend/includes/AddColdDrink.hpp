#ifndef ADDCOLDDRINK
#define ADDCOLDDRINK

#include "Order.hpp"

class AddColdDrink : public Order {
    public:
    std::shared_ptr<Meal> executeOrder();
};

#endif