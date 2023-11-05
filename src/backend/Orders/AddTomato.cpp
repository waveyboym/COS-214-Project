#ifndef ADD_TOMATO_CPP
#define ADD_TOMATO_CPP

#include "../includes/AddTomato.hpp"

std::shared_ptr<Meal> AddTomato::executeOrder(std::shared_ptr<Meal> m) {
    if (addedToList) {
        return m;
    } else {
        addedToList = true;
        return std::make_shared<Tomato>(m);
    }
}

#endif