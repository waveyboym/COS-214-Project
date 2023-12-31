#ifndef ADD_MAYO_CPP
#define ADD_MAYO_CPP

#include "../includes/AddMayo.hpp"

std::shared_ptr<Meal> AddMayo::executeOrder(std::shared_ptr<Meal> m) {
    if (addedToList) {
        return m;
    } else {
        addedToList = true;
        return std::make_shared<Mayo>(m);
    }
}

#endif