#ifndef ADD_ONION_CPP
#define ADD_ONION_CPP

#include "../includes/AddOnion.hpp"

std::shared_ptr<Meal> AddOnion::executeOrder(std::shared_ptr<Meal> m) {
    if (addedToList) {
        return m;
    } else {
        addedToList = true;
        return std::make_shared<Onion>(m);
    }
}

#endif