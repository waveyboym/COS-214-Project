#include "../includes/HeadChef.hpp"
#include <iostream>

HeadChef::HeadChef(){}

void HeadChef::makeOrder(std::vector<std::shared_ptr<Order>> order, std::string waiterUUID, std::shared_ptr<Meal> meal){
    if(pos_ptr != nullptr){
       pos_ptr->sendMealToPOS(meal, waiterUUID);
    }
    else{
        std::cout << "No POS attached" << std::endl;
    }
}