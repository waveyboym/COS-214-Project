#include "../includes/Ingredient.hpp"
#include <sstream>

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