#include "../includes/BunChef.hpp"
#include "../includes/ConcreteBuns.hpp"

#include "../includes/AddNormalBun.hpp"
#include "../includes/AddWholeWheatBun.hpp"
#include "../includes/AddNoBun.hpp"

BunChef::BunChef(){}

std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>> BunChef::makeOrder(std::vector<std::shared_ptr<Order>> order, std::shared_ptr<Customer> customer, std::shared_ptr<Meal> meal){
   
    for (auto i = order.begin(); i != order.end(); ++i){
        if(typeid(*i).name() == typeid(AddNormalBun).name() || typeid(*i).name() == typeid(AddWholeWheatBun).name() || typeid(*i).name() == typeid(AddNoBun).name()){
            meal = (*i)->executeOrder(meal);
            order.erase(i);
        }
    }
    
    if(meal == nullptr){
        meal = std::shared_ptr<NoBun>();
    }
    
    if(next){
        return this->next->makeOrder(order, customer, meal);
    }
    else{
        return std::make_pair(meal, customer);
    }
    
}