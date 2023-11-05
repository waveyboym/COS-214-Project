#include "../includes/Chef.hpp"

Chef::Chef(){}

void Chef::makeOrder(std::vector<std::shared_ptr<Order>> order, std::string waiterUUID, std::shared_ptr<Meal> meal){

    for(int i = 0; i < order.size(); i++){
        meal = order.at(i).get()->executeOrder(meal);
    }

    if(this->next){
        this->next->makeOrder(order, waiterUUID, meal);
    }
}