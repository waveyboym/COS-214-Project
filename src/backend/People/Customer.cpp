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

void Customer::setOrder(){
    int rNum = rand();

    switch(rNum%3){
        case 0:
            order = std::make_shared<AddNoBun>();
            order->executeOrder();
            break;
        case 1:
            order = std::make_shared<AddNormalBun>();
            order->executeOrder();
            break;
        case 2:
            order = std::make_shared<AddWholeWheatBun>();
            order->executeOrder();
            break;
    }

    for (int i = 0; i < 10; i++)
    {
        std::shared_ptr<Meal> m = order->meal;

        switch(rand()%17){
            case 0:
                break;
            case 1:
                order = std::make_shared<AddBBQSauce>();
                order->executeOrder(m);
                break;
            case 2:
                order = std::make_shared<AddBeefBurgerPatty>();
                order->executeOrder(m);
                break;
            case 3:
                order = std::make_shared<AddCaramelizedOnion>();
                order->executeOrder(m);
                break;
            case 4:
                order = std::make_shared<AddCheese>();
                order->executeOrder(m);
                break;
            case 5:
                order = std::make_shared<AddChickenBurgerPatty>();
                order->executeOrder(m);
                break;
            case 6:
                order = std::make_shared<AddColdDrink>();
                order->executeOrder(m);
                break;
            case 7:
                order = std::make_shared<AddFries>();
                order->executeOrder(m);
                break;
            case 8:
                order = std::make_shared<AddJuice>();
                order->executeOrder(m);
                break;
            case 9:
                order = std::make_shared<AddLettuce>();
                order->executeOrder(m);
                break;
            case 10:
                order = std::make_shared<AddMayo>();
                order->executeOrder(m);
                break;
            case 11:
                order = std::make_shared<AddOnion>();
                order->executeOrder(m);
                break;
            case 12:
                order = std::make_shared<AddPickles>();
                order->executeOrder(m);
                break;
            case 13:
                order = std::make_shared<AddPineApple>();
                order->executeOrder(m);
                break;
            case 14:
                order = std::make_shared<AddTomato>();
                order->executeOrder(m);
                break;
            case 15:
                order = std::make_shared<AddVeggieBurgerPatty>();
                order->executeOrder(m);
                break;
            case 16:
                order = std::make_shared<AddWater>();
                order->executeOrder(m);
                break;
        }
    }
    
}

std::shared_ptr<Order> Customer::getOrder() const{
    return order;
}