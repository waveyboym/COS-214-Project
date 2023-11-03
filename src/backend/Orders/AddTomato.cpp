#include "AddTomato.hpp"

std::shared_ptr<Meal> AddTomato::executeOrder(std::shared_ptr<Meal> m) {
    if (addedToList) {
        return m;
    } else {
        addedToList = true;
        return std::make_shared<Tomato>(m);
    }
}