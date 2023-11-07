#ifndef ADD_NORMAL_CPP
#define ADD_NORMAL_CPP

#include "../includes/AddNormalBun.hpp"

std::shared_ptr<Meal> AddNormalBun::executeOrder(std::shared_ptr<Meal> m) {
    if (addedToList) {
        return m;
    } else {
        addedToList = true;
        return std::make_shared<PlainBun>();
    }
}

#endif