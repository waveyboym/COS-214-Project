#include "AddFries.hpp"

std::shared_ptr<Meal> AddFries::executeOrder(std::shared_ptr<Meal> m){
    if(addedToList){
        return m;
    }else{
        addedToList = true;
        return std::make_shared<Fries>(m);
    }
}