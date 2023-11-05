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
    return true;
}

bool Customer::getHasCompletedMeal(){
    if(this->has_completed_meal){
        return this->has_completed_meal;//true
    }
    this->current = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = this->current - this->start;
    if(elapsed_seconds.count() >= 5.0){//customer takes 5 seconds to eat
        this->has_completed_meal = true;
    }
    return this->has_completed_meal;
}

void Customer::setHasCompletedMeal(bool set_to){
    this->has_completed_meal = set_to;
}