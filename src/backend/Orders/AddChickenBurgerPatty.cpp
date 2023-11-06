#ifndef ADD_CHICKEN_PATTY_CPP
#define ADD_CHICKEN_PATTY_CPP

#include "../includes/AddChickenBurgerPatty.hpp"

std::shared_ptr<Meal> AddChickenBurgerPatty::executeOrder(
    std::shared_ptr<Meal> m) {
    if (addedToList) {
        return m;
    } else {
        addedToList = true;
        return std::make_shared<ChickenPatty>(m);
    }
}

#endif