#include "../includes/Ingredient.hpp"
#include <sstream>

Ingredient::Ingredient(std::string name, double cost, std::shared_ptr<Meal> m): Meal(name, cost), meal(m){
    //this->meal->setTotalCost(cost);
}

double Ingredient::getTotalCost(){
    if(meal){
        return meal->getTotalCost(this->getCost());
    }
    else{
        return 0;
    }
}

double Ingredient::getTotalCost(double prev){
    if(meal){
        return meal->getTotalCost(prev + this->getCost());
    }
    else{
        return 0;
    }
}

// void Ingredient::setTotalCost(double c){
//     if(meal){
//         meal->setTotalCost(c);
//     }
// }

std::string Ingredient::getItemizedList(){
    
    std::ostringstream out;
    out.precision(2);
    out << std::fixed << this->getCost();
    std::string price = std::move(out).str();

    if(meal){
        std::string s = this->getName() + "  R" + price + "\n";
        std::shared_ptr<Meal> start = std::make_shared<Ingredient>(this->getName(), this->getCost(), this->meal);
        return meal->getItemizedList(s, start);
    }
    else{
        return "";
    }
}

std::string Ingredient::getItemizedList(std::string tail, std::shared_ptr<Meal> start){
    
    std::ostringstream out;
    out.precision(2);
    out << std::fixed << this->getCost();
    std::string price = std::move(out).str();
    
    if(meal){
        std::string mine = this->getName() + "  R" + price + "\n";
        return meal->getItemizedList(mine + tail, start);
    }
    else{
        return "";
    }
}