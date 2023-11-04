#include "../includes/Meal.hpp"

Meal::Meal(std::string name, double cost){
    this->name = name;
    this->cost = cost;
}

std::string Meal::getName(){
    return this->name;
}

double Meal::getCost(){
    return this->cost;
}

