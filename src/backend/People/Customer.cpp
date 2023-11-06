#include "../includes/Customer.hpp"

Customer::Customer(){
    this->currentEmotionalState = std::make_shared<Neutral>();
}

Customer::Customer(std::string customeruuid){
    this->currentEmotionalState = std::make_shared<Neutral>();
    this->person_uuid = customeruuid;
}

bool Customer::personAction(){
    return false;
}

std::string Customer::getCurrentEmotionalStateString(){
    return this->currentEmotionalState->getEmotionalStateString();
}

EMOTIONAL_STATE Customer::getCurrentEmotionalStateEnum(){
    return this->currentEmotionalState->getEmotionalStateEnum();
}

void Customer::setEmotionalState(EMOTIONAL_STATE state){
    if(state == EMOTIONAL_STATE::ANGRY){
        this->currentEmotionalState = std::make_shared<Angry>();
    }
    else if(state == EMOTIONAL_STATE::HAPPY){
        this->currentEmotionalState = std::make_shared<Happy>();
    }
    else if(state == EMOTIONAL_STATE::NEUTRAL){
        this->currentEmotionalState = std::make_shared<Neutral>();
    }
    else if(state == EMOTIONAL_STATE::SLIGHTLY_ANGRY){
        this->currentEmotionalState = std::make_shared<SlightlyAngry>();
    }
    else if(state == EMOTIONAL_STATE::SLIGHTLY_HAPPY){
        this->currentEmotionalState = std::make_shared<SlightlyHappy>();
    }
}

bool Customer::getIsSeated(){
    return this->is_seated;
}

void Customer::setIsSeated(bool set_to){
    this->is_seated = set_to;
}

bool Customer::startEatingMeal(){
    this->start = std::chrono::system_clock::now();
    this->has_completed_meal = false;
    this->has_started_eating_meal = true;
    return true;
}

bool Customer::getHasCompletedMeal(){
    if(this->has_completed_meal){
        return this->has_completed_meal;//true
    }
    if(!this->has_started_eating_meal){
        return false;
    }
    this->current = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = this->current - this->start;
    if(elapsed_seconds.count() >= 7.0){//customer takes 10 seconds to eat
        this->has_completed_meal = true;
    }
    return this->has_completed_meal;
}

void Customer::setHasCompletedMeal(bool set_to){
    this->has_completed_meal = set_to;
}

void Customer::setOrder(){
    int rNum = rand();
    std::shared_ptr<Order> o;

    switch(rNum%3){
        case 0:
            order.push_back(std::make_shared<AddNoBun>());
            break;
        case 1:
            order.push_back(std::make_shared<AddNormalBun>());
            break;
        case 2:
            order.push_back(std::make_shared<AddWholeWheatBun>());
            break;
    }

    for (int i = 0; i < 10; i++)
    {
        switch(rand()%17){
            case 0:
                break;
            case 1:
                order.push_back(std::make_shared<AddBBQSauce>());
                break;
            case 2:
                order.push_back(std::make_shared<AddBeefBurgerPatty>());
                break;
            case 3:
                order.push_back(std::make_shared<AddCaramelizedOnion>());
                break;
            case 4:
                order.push_back(std::make_shared<AddCheese>());
                break;
            case 5:
                order.push_back(std::make_shared<AddChickenBurgerPatty>());
                break;
            case 6:
                order.push_back(std::make_shared<AddColdDrink>());
                break;
            case 7:
                order.push_back(std::make_shared<AddFries>());
                break;
            case 8:
                order.push_back(std::make_shared<AddJuice>());
                break;
            case 9:
                order.push_back(std::make_shared<AddLettuce>());
                break;
            case 10:
                order.push_back(std::make_shared<AddMayo>());
                break;
            case 11:
                order.push_back(std::make_shared<AddOnion>());
                break;
            case 12:
                order.push_back(std::make_shared<AddPickles>());
                break;
            case 13:
                order.push_back(std::make_shared<AddPineApple>());
                break;
            case 14:
                order.push_back(std::make_shared<AddTomato>());
                break;
            case 15:
                order.push_back(std::make_shared<AddVeggieBurgerPatty>());
                break;
            case 16:
                order.push_back(std::make_shared<AddWater>());
                break;
        }
    }
    
    has_decided = true;
}

void Customer::setFrontendOrder(std::vector<std::string> order_list){
    for(auto it = order_list.begin(); it != order_list.end(); ++it){
        if(*it == "burger"){
            order.push_back(std::make_shared<AddNormalBun>());
            order.push_back(std::make_shared<AddBeefBurgerPatty>());
            order.push_back(std::make_shared<AddCheese>());
            order.push_back(std::make_shared<AddColdDrink>());
            order.push_back(std::make_shared<AddLettuce>());
            order.push_back(std::make_shared<AddPickles>());
        }
        else if(*it == "fries"){
            order.push_back(std::make_shared<AddFries>());
        }
        else if(*it == "steak"){
            order.push_back(std::make_shared<AddBeefBurgerPatty>());
            order.push_back(std::make_shared<AddBBQSauce>());
        }
        else if(*it == "chicken"){
            order.push_back(std::make_shared<AddChickenBurgerPatty>());
        }
        else if(*it == "lettuce"){
            order.push_back(std::make_shared<AddLettuce>());
        }
        else if(*it == "tomatoe"){
            order.push_back(std::make_shared<AddTomato>());
        }
        else if(*it == "salad"){
            order.push_back(std::make_shared<AddLettuce>());
            order.push_back(std::make_shared<AddMayo>());
            order.push_back(std::make_shared<AddOnion>());
            order.push_back(std::make_shared<AddTomato>());
            order.push_back(std::make_shared<AddWater>());
        }
    }

    this->has_decided = true;
    this->has_ordered = false;
}

std::vector<std::shared_ptr<Order>> Customer::getOrder() const{
    return order;
}

bool Customer::getHasDecided(){
    return has_decided;
}

bool Customer::getHasOrdered(){
    return has_ordered;
}

void Customer::Ordered(){
    has_ordered = true;
}

void Customer::setIsAFrontendCustomer(bool set_to){
    this->is_a_frontend_customer = true;
}

bool Customer::isAFrontendCustomer(){
    return this->is_a_frontend_customer;
}