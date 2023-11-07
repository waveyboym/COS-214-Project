#ifndef ADD_PICKLES_CPP
#define ADD_PICKLES_CPP

#include "../includes/AddPickles.hpp"

std::shared_ptr<Meal> AddPickles::executeOrder(std::shared_ptr<Meal> m) {
    if (addedToList) {
        return m;
    } else {
        addedToList = true;
        return std::make_shared<Pickles>(m);
    }
}

#endif