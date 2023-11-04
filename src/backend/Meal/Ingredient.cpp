#include "../includes/Ingredient.hpp"

Ingredient::Ingredient(std::string name, double cost, std::shared_ptr<Meal> m): Meal(name, cost), meal(m){
    this->meal->setTotalCost(cost);
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

std::string Ingredient::getItemizedList(){
    if(meal){
        std::string s = this->getName() + "  R" + std::to_string(this->getCost()) + "\n";
        return meal->getItemizedList(s);
    }
    else{
        return "";
    }
}

std::string Ingredient::getItemizedList(std::string tail){
    if(meal){
        std::string mine = this->getName() + "  R" + std::to_string(this->getCost()) + "\n";
        return meal->getItemizedList(mine + tail);
    }
    else{
        return "";
    }
}