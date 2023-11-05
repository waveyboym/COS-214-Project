#include "../includes/Chef.hpp"

Chef::Chef():AbstractChef("Chef"){}

std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>> Chef::makeOrder(std::vector<std::shared_ptr<Order>> order, std::shared_ptr<Customer> customer, std::shared_ptr<Meal> meal){

    //std::cout << "Chef makeOrder start" << std::endl;

    for(int i = 0; i < order.size(); i++){
        //std::cout << "going through order " << std::to_string(i) << std::endl;
        meal = order.at(i).get()->executeOrder(meal);
    }

    if(getNext().get()){
        //std::cout<< "chef sends to next" << std::endl;
        return getNext().get()->makeOrder(order, customer, meal);
    }

    return std::make_pair(meal, customer);
}