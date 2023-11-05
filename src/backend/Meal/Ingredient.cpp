#include "../includes/Ingredient.hpp"

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