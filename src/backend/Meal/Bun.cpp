#include "../includes/Bun.hpp"
#include <sstream>

Bun::Bun(std::string name, double cost, double prepTime): Meal(name, cost, prepTime){
        this->setTotalCost(cost);
        this->setTotalPrepTime(prepTime);
}

std::string Bun::getItemizedList(std::string tail){

        
        std::ostringstream o;
        o.precision(2);
        o << std::fixed << this->getCost();
        std::string price = std::move(o).str();

        std::ostringstream o2;
        o2.precision(2);
        o2 << std::fixed << this->getTotalCost();
        std::string price_t = std::move(o2).str();
        
        std::string out = this->getName() + "  R" + price + "\n";
        out += tail;
        out += "\nTotal: R" + price_t;
        return out;
        
}

std::string Bun::getItemizedList(){

        std::ostringstream o;
        o.precision(2);
        o << std::fixed << this->getCost();
        std::string price = std::move(o).str();

        std::ostringstream o2;
        o2.precision(2);
        o2 << std::fixed << this->getTotalCost();
        std::string price_t = std::move(o2).str();

        std::string out = this->getName() + "  R" + price + "\n";
        out += "\nTotal: R" + price_t;

        return out;
}

double Bun::getTotalCost(){
        return this->total_cost;
}

void Bun::setTotalCost(double c){
        this->total_cost += c;
}