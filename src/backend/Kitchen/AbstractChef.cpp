#include "../includes/AbstractChef.hpp"

AbstractChef::AbstractChef(std::string type){
    this->next = nullptr;
    this->type = type;
}

void AbstractChef::add(std::shared_ptr<AbstractChef> c){

    if(this->next){
        next.get()->add(c);
    }
    else{
        this->next = c;
    }
}


void AbstractChef::receiveOrder(std::vector<std::shared_ptr<Order>> order, std::shared_ptr<Customer> c){
    this->makeOrder(order, c, nullptr);
}

