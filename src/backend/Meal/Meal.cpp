#include "../includes/Meal.hpp"

Meal::Meal(std::string name, double cost, double prepTime){
    this->name = name;
    this->cost = cost;
    this->prepTime = prepTime;
}

std::string Meal::getName(){
    return this->name;
}

double Meal::getCost(){
    return this->cost;
}

double Meal::getPrepTime(){
    return this->prepTime;
}

