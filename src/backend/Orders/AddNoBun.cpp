#ifndef ADD_NO_BUN_CPP
#define ADD_NO_BUN_CPP

#include "../includes/AddNoBun.hpp"

std::shared_ptr<Meal> AddNoBun::executeOrder(std::shared_ptr<Meal> m){
 if(addedToList)
    return m;
 else{
    addedToList=true;
    return std::make_shared<NoBun>();
 }
}

#endif