#include "../includes/BunChef.hpp"
#include "../includes/ConcreteBuns.hpp"

#include "../includes/AddNormalBun.hpp"
#include "../includes/AddWholeWheatBun.hpp"
#include "../includes/AddNoBun.hpp"

BunChef::BunChef():AbstractChef("BunChef"){}

std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>> BunChef::makeOrder(std::vector<std::shared_ptr<Order>> order, std::shared_ptr<Customer> customer, std::shared_ptr<Meal> meal){

     //std::cout << "bUNChef makeOrder start" << std::endl;

    for (auto i = order.begin(); i != order.end(); ++i){
        if(typeid(*i).name() == typeid(AddNormalBun).name() || typeid(*i).name() == typeid(AddWholeWheatBun).name() || typeid(*i).name() == typeid(AddNoBun).name()){
            meal = (*i)->executeOrder(meal);
            order.erase(i);
        }
    }
    
    if(meal.get() == nullptr){
        meal = std::make_shared<AddNoBun>().get()->executeOrder(meal);
    }
    
    if(getNext().get() != nullptr){
        //std::cout<< "bunchef sends to next" << std::endl;
        return getNext().get()->makeOrder(order, customer, meal);
    }
    else{
        return std::make_pair(meal, customer);
    }
    
}