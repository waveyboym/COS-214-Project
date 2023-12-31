#ifndef ADD_JUICE_CPP
#define ADD_JUICE_CPP

#include "../includes/AddJuice.hpp"

std::shared_ptr<Meal> AddJuice::executeOrder(std::shared_ptr<Meal> m) {
    if (addedToList) {
        return m;
    } else {
        addedToList = true;
        return std::make_shared<Juice>(m);
    }
}

#endif