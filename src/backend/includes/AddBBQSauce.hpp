#ifndef ADDBBQSAUCE_HPP
#define ADDBBQSUACE_HPP

#include "Order.hpp"

class AddBBQSauce :public Order {
public:
std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif