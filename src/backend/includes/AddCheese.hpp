#ifndef ADDCHEESE_HPP
#define ADDCHEESE_HPP

#include "Order.hpp"

class AddCheese : public Order{
    public:
      bool executeOrder();
};

#endif