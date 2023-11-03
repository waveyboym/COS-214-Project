#include "AddPickles.hpp"

std::shared_ptr<Meal> AddPickles::executeOrder(std::shared_ptr<Meal> m) {
    if (addedToList) {
        return m;
    } else {
        addedToList = true;
        return std::make_shared<Pickles>(m);
    }
}