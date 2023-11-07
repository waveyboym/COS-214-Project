#include "../includes/Meal.hpp"

Meal::Meal(std::string name, double cost, double prep){
    this->name = name;
    this->cost = cost;
    this->prep_time = prep;
}

std::string Meal::getName(){
    return this->name;
}

double Meal::getCost(){
    return this->cost;
}

double Meal::getPrepTime(){
    return this->prep_time;
}

