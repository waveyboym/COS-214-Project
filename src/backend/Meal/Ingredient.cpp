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
        double value = this->getCost(); 
        std::ostringstream stream;
        stream << std::fixed << std::setprecision(2) << value;
        std::string result = stream.str();

        std::string s = this->getName() + "  R" + result + "\n";
        return meal->getItemizedList(s);
    }
    else{
        return "";
    }
}

std::string Ingredient::getItemizedList(std::string tail){
    if(meal){
        double value = this->getCost(); 
        std::ostringstream stream;
        stream << std::fixed << std::setprecision(2) << value;
        std::string result = stream.str();

        std::string mine = this->getName() + "  R" + result + "\n";
        return meal->getItemizedList(mine + tail);
    }
    else{
        return "";
    }
}