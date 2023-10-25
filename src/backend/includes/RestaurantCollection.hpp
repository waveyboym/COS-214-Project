#ifndef RESTAURANT_COLLECTION_HPP
#define RESTAURANT_COLLECTION_HPP
#include "RestaurantIterator.hpp"
#include <memory>

class RestaurantCollection{
    public:
        virtual std::shared_ptr<RestaurantIterator> createRestaurantIterator() = 0;
};

#endif