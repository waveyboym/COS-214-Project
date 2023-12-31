#ifndef ADD_PINEAPPLE_CPP
#define ADD_PINEAPPLE_CPP

#include "../includes/AddPineapple.hpp"

std::shared_ptr<Meal> AddPineApple::executeOrder(std::shared_ptr<Meal> m){
    if(addedToList){
        return m;
    }else{
        addedToList = true;
        return std::make_shared<Pineapple>(m);
    }
}

#endif