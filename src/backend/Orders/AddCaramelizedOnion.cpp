#ifndef ADD_CARAMELIZED_ONION_CPP
#define ADD_CARAMELIZED_ONION_CPP

#include "../includes/AddCaramelizedOnion.hpp"

std::shared_ptr<Meal> AddCaramelizedOnion::executeOrder(std::shared_ptr<Meal> m){
    if(addedToList){
        return m;
    }else{
        addedToList = true;
        return std::make_shared<CaramelizedOnion>(m);
    }
}

#endif