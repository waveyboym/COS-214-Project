#include "../includes/Chef.hpp"

Chef::Chef(){}

std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>> Chef::makeOrder(std::vector<std::shared_ptr<Order>> order, std::shared_ptr<Customer> customer, std::shared_ptr<Meal> meal){

    for(int i = 0; i < order.size(); i++){
        meal = order.at(i).get()->executeOrder(meal);
    }

    if(this->next){
        return this->next->makeOrder(order, customer, meal);
    }

    return std::make_pair(meal, customer);
}