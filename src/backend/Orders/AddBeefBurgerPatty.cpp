#ifndef ADD_BEEF_PATTY_CPP
#define ADD_BEEF_PATTY_CPP

#include "../includes/AddBeefBurgerPatty.hpp"

std::shared_ptr<Meal> AddBeefBurgerPatty::executeOrder(std::shared_ptr<Meal> m){
    if(addedToList){
        return m;
    }else{
        addedToList = true;
        return std::make_shared<BeefPatty>(m);
    }
}

#endif