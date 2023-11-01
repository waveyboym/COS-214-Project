#ifndef ORDER_HPP
#define ORDER_HPP

#include "Customer.hpp"

class Order{

private:
std::shared_ptr<Customer> customer;
//std::shared_ptr<Meal> meal;

public:
std::shared_ptr<Customer> getCustomer();
bool setCustomer(std::shared_ptr<Customer> c);
//std::shared_ptr<Customer> getMeal();
//bool setMeal(std::shared_ptr<Meal> m);

virtual bool  executeOrder() = 0;

};

#endif 