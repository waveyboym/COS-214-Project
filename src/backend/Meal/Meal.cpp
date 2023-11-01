#include "../includes/Meal.hpp"

Meal::Meal(std::string name, double cost): name(name), cost(cost){
}

std::string Meal::getName(){
    return this->name;
}

double Meal::getCost(){
    return this->cost;
}

