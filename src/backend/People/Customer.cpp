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