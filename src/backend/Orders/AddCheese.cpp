#ifndef ADD_CHEESE_CPP
#define ADD_CHEESE_CPP

#include "../includes/AddCheese.hpp"

std::shared_ptr<Meal> AddCheese::executeOrder(std::shared_ptr<Meal> m) {
    if (addedToList) {
        return m;
    } else {
        addedToList = true;
        return std::make_shared<Cheese>(m);
    }
}

#endif