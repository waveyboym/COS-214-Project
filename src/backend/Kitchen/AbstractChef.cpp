#include "../includes/AbstractChef.hpp"

AbstractChef::AbstractChef(){
    this->next = nullptr;
    this->pos_ptr = nullptr;
}

void AbstractChef::add(std::shared_ptr<AbstractChef> c){
    if(this->next){
        next.get()->add(c);
    }
    else{
        this->next = c;
    }
}

void AbstractChef::receiveOrder(std::vector<std::shared_ptr<Order>> order, std::string waiterUUID){
    this->makeOrder(order, waiterUUID, nullptr);
}

void AbstractChef::setPOS(std::shared_ptr<POS> pos){
    this->pos_ptr = pos;
}

std::shared_ptr<POS> AbstractChef::getPOS(){
    return this->pos_ptr;
}

