#include "../includes/Kitchen.hpp"
#include "../includes/Chef.hpp"
#include "../includes/BunChef.hpp"
#include "../includes/HeadChef.hpp"

Kitchen::Kitchen(std::map<std::string, std::shared_ptr<Waiter>>& m_waiters){
    //set waiters
    this->waiters = m_waiters;

    //assemble chain
    this->chain_of_chefs = std::make_shared<BunChef>();
    (*chain_of_chefs).add(std::make_shared<Chef>());
    (*chain_of_chefs).add(std::make_shared<HeadChef>());
}


void Kitchen::createMeal(std::vector<std::shared_ptr<Order>> order, std::shared_ptr<Customer> customer){
    std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>> new_meal = (*chain_of_chefs).makeOrder(order, customer, nullptr);
    this->completed_meals.push_back(new_meal);

    has_completed_meals = true;
}

std::vector<std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>>>  Kitchen::getCompletedMeals(){
    return this->completed_meals;
}


void Kitchen::notifyWaiters(){
    std::shared_ptr<WaiterIterator> w_i = std::make_shared<WaiterIterator>(this->waiters);
    while(!w_i->isDone())
    { 
        std::shared_ptr<Waiter> curWaiter = std::dynamic_pointer_cast<Waiter>(w_i->currentItem());
        if (curWaiter != nullptr && curWaiter->isAssignedATable())
        {
            curWaiter->getUpdate(completed_meals);
        }
        w_i->next();
    }

    this->completed_meals.clear();

    has_completed_meals = false;
}

bool Kitchen::getHasCompletedMeals(){
    return has_completed_meals;
}