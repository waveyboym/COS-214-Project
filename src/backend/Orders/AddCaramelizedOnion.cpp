#include "AddCaramelizedOnion.hpp"

std::shared_ptr<Meal> AddCaramelizedOnion::executeOrder(std::shared_ptr<Meal> m){
    if(addedToList){
        return m;
    }else{
        addedToList = true;
        return std::make_shared<CaramelizedOnion>(m);
    }
}