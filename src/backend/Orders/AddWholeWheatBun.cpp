#include "../includes/AddWholeWheatBun.hpp"

std::shared_ptr<Meal> AddWholeWheatBun::executeOrder(std::shared_ptr<Meal> m){
    if(addedToList){
        return m;
    }else{
        addedToList = true;
        return std::make_shared<WholewheatBun>();
    }
}