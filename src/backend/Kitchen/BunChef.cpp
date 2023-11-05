#include "../includes/BunChef.hpp"
#include "../includes/ConcreteBuns.hpp"

#include "../includes/AddNormalBun.hpp"
#include "../includes/AddWholeWheatBun.hpp"
#include "../includes/AddNoBun.hpp"

BunChef::BunChef(){}

void BunChef::makeOrder(std::vector<std::shared_ptr<Order>> order, std::string waiterUUID, std::shared_ptr<Meal> meal){
    
    for (auto i = order.begin(); i != order.end(); ++i){
        if(typeid(*i).name() == typeid(AddNormalBun).name() || typeid(*i).name() == typeid(AddWholeWheatBun).name() || typeid(*i).name() == typeid(AddNoBun).name()){
            meal = (*i)->executeOrder(meal);
            order.erase(i);
        }
    }
    
    if(meal == nullptr){
        meal = std::shared_ptr<NoBun>();
    }
    this->next->makeOrder(order, waiterUUID, meal);
}