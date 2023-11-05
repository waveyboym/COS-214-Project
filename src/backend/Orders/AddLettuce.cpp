#ifndef ADD_LETTUCE_CPP
#define ADD_LETTUCE_CPP

#include "../includes/AddLettuce.hpp"

std::shared_ptr<Meal> AddLettuce::executeOrder(std::shared_ptr<Meal> m) {
    if (addedToList) {
        return m;
    } else {
        addedToList = true;
        return std::make_shared<Lettuce>(m);
    }
}

#endif