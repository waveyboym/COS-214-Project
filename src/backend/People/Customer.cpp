#include "../includes/Customer.hpp"

Customer::Customer(){
    this->currentEmotionalState = std::make_shared<Neutral>();
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
}