#ifndef RESTAURANT_ITERATOR_HPP
#define RESTAURANT_ITERATOR_HPP

class RestaurantIterator{
    void next();
    std::shared_ptr<RestuarantCollection> first();
    std::shared_ptr<RestaurantColection> last();
    bool isDone();
    std::shared_ptr<RestaurantCollection> current_item(); 
};

#endif