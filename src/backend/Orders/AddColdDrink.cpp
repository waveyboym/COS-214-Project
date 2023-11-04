#include "../includes/AddColdDrink.hpp"

std::shared_ptr<Meal> AddColdDrink::executeOrder(std::shared_ptr<Meal> m) {
    if (addedToList) {
        return m;
    } else {
        addedToList = true;
        return std::make_shared<ColdDrink>(m);
    }
}