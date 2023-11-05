#include "../includes/AddTomatoSauce.hpp"

std::shared_ptr<Meal> AddTomatoSauce::executeOrder(std::shared_ptr<Meal> m)
{
    if(addedToList){
        return m;
    }else{
        addedToList = true;
        return std::make_shared<TomatoSauce>(m);
    }
}