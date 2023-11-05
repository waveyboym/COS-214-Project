#include "../includes/HeadChef.hpp"
#include <iostream>

HeadChef::HeadChef():AbstractChef("headchef"){}

std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>> HeadChef::makeOrder(std::vector<std::shared_ptr<Order>> order, std::shared_ptr<Customer> customer, std::shared_ptr<Meal> meal){
    //std::cout << "HeadChef makeOrder start" << std::endl;
    
    if(getNext().get()){
        //std::cout<< "headchef sends to next" << std::endl;
        return getNext().get()->makeOrder(order, customer, meal);
    }

    return (std::make_pair(meal, customer));
}