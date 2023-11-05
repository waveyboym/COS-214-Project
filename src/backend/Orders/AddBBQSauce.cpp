#include "../includes/AddBBQSauce.hpp"

AddBBQSauce::AddBBQSauce():Order(){}

std::shared_ptr<Meal> AddBBQSauce::executeOrder(std::shared_ptr<Meal> m){
    if(addedToList){
        return m;
    }else{
        addedToList = true;
        return std::make_shared<BBQSauce>(m);
    }
}