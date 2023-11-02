#ifndef ADDWHOLEWHEATBUN_HPP
#define ADDWHOLEWHEATBUN_HPP

#include "Order.hpp"

class AddWholeWheatBun : public Order {
public:
    std::shared_ptr<Meal> executeOrder(std::shared_ptr<Meal> m);
};

#endif