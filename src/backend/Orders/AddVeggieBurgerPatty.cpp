#ifndef ADD_VEGGIE_PATTY_CPP
#define ADD_VEGGIE_PATTY_CPP

#include "../includes/AddVeggieBurgerPatty.hpp"

std::shared_ptr<Meal> AddVeggieBurgerPatty::executeOrder(std::shared_ptr<Meal> m) {
    if (addedToList) {
        return m;
    } else {
        addedToList = true;
        return std::make_shared<VeggiePatty>(m);
    }
}

#endif