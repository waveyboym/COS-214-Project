#include "../includes/AddWater.hpp"

std::shared_ptr<Meal> AddWater::executeOrder(std::shared_ptr<Meal> m) {
    if (addedToList) {
        return m;
    } else {
        addedToList = true;
        return std::make_shared<Water>(m);
    }
}