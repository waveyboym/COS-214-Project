#include "../includes/AddSalad.hpp"

std::shared_ptr<Meal> AddSalad::executeOrder(std::shared_ptr<Meal> m) {
    if (addedToList) {
        return m;
    } else {
        addedToList = true;
        return std::make_shared<Salad>(m);
    }
}