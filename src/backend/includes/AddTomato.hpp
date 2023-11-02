#ifndef ADDTOMATO_HPP
#define ADDTOMATO_HPP

#include "Order.hpp"

class AddTomato : public Order {
public:
std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif