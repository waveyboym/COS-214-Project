#include "../includes/HeadChef.hpp"
#include <iostream>

HeadChef::HeadChef(){}

std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>> HeadChef::makeOrder(std::vector<std::shared_ptr<Order>> order, std::shared_ptr<Customer> customer, std::shared_ptr<Meal> meal){
    if(order.size() != 0){
        std::cout << "Missed an order" << std::endl;    
    }
    return (std::make_pair(meal, customer));
}