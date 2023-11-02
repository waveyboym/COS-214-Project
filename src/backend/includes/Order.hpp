#ifndef ORDER_HPP
#define ORDER_HPP

#include "Customer.hpp"
#include "Meal.hpp"

class Order{

protected:
// std::shared_ptr<Customer> customer;
std::shared_ptr<Meal> meal;
bool addedToList = false;

public:
virtual std::shared_ptr<Meal>  executeOrder(std::shared_ptr<Meal>  m) = 0;

};

#endif 