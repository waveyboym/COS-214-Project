#include "AddChickenBurgerPatty.hpp"

std::shared_ptr<Meal> AddChickenBurgerPatty::executeOrder(
    std::shared_ptr<Meal> m) {
    if (addedToList) {
        return m;
    } else {
        addedToList = true;
        return std::make_shared<ChickenPatty>(m);
    }
}