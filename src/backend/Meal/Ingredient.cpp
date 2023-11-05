#include "../includes/Ingredient.hpp"
#include <sstream>

Ingredient::Ingredient(std::string name, double cost, double prepTime, std::shared_ptr<Meal> m): Meal(name, cost, prepTime), meal(m){
    this->meal->setTotalCost(cost);
    this->meal->setTotalPrepTime(prepTime);
}

double Ingredient::getTotalCost(){
    if(meal){
        return meal->getTotalCost();
    }
    else{
        return 0;
    }
}

void Ingredient::setTotalCost(double c){
    if(meal){
        meal->setTotalCost(c);
    }
}

double Ingredient::getTotalPrepTime(){
    if(meal){
        return meal->getTotalPrepTime();
    }
    else{
        return 0;
    }
}

void Ingredient::setTotalPrepTime(double t){
    if(meal){
        meal->setTotalPrepTime(t);
    }
}

std::string Ingredient::getItemizedList(){
    
    std::ostringstream out;
    out.precision(2);
    out << std::fixed << this->getCost();
    std::string price = std::move(out).str();

    if(meal){
        std::string s = this->getName() + "  R" + price + "\n";

        return meal->getItemizedList(s);
    }
    else{
        return "";
    }
}

std::string Ingredient::getItemizedList(std::string tail){
    
    std::ostringstream out;
    out.precision(2);
    out << std::fixed << this->getCost();
    std::string price = std::move(out).str();
    
    if(meal){
        std::string mine = this->getName() + "  R" + price + "\n";

        return meal->getItemizedList(mine + tail);
    }
    else{
        return "";
    }
}