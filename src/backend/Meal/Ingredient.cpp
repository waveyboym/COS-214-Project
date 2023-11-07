#include "../includes/Ingredient.hpp"
#include <sstream>

Ingredient::Ingredient(std::string name, double cost, double prep, std::shared_ptr<Meal> m): Meal(name, cost, prep), meal(m){
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


    double Ingredient::getTotalPrepTime(){
        if(meal){
            return meal->getTotalPrepTime(this->getPrepTime());
        }
            else{
                return 0;
        }
    }


    double Ingredient::getTotalPrepTime(double prev){
        if(meal){
            return meal->getTotalPrepTime(prev + this->getPrepTime());
        }
        else{
            return 0;
        }
    }


std::string Ingredient::getItemizedList(){
    
    std::ostringstream out;
    out.precision(2);
    out << std::fixed << this->getCost();
    std::string price = std::move(out).str();

    if(meal){
        std::string s = this->getName() + "  R" + price + "\n";
        std::shared_ptr<Meal> start = std::make_shared<Ingredient>(this->getName(), this->getCost(), this->getPrepTime(), this->meal);
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