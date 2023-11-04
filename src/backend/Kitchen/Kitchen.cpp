#include "../includes/Kitchen.hpp"
#include "../includes/Chef.hpp"
#include "../includes/BunChef.hpp"
#include "../includes/HeadChef.hpp"

Kitchen::Kitchen(std::vector<std::shared_ptr<Waiter>> waiters){
    //set waiters
    this->waiters = waiters;

    //assemble chain
    this->chain_of_chefs = std::make_shared<BunChef>();
    (*chain_of_chefs).add(std::make_shared<Chef>());
    (*chain_of_chefs).add(std::make_shared<HeadChef>());
}


void Kitchen::createMeal(std::vector<std::shared_ptr<Order>> order, std::shared_ptr<Customer> customer){
    std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>> new_meal = (*chain_of_chefs).makeOrder(order, customer, nullptr);
    this->completed_meals.push_back(new_meal);
}

std::vector<std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>>>  Kitchen::getCompletedMeals(){
    return this->completed_meals;
}


void Kitchen::notifyWaiters(){
    for(int i = 0; i < waiters.size(); i++){
        waiters.at(i).get()->getUpdate(completed_meals);
    }
    this->completed_meals.clear();
}