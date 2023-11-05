#include "../includes/Bun.hpp"
#include <sstream>

Bun::Bun(std::string name, double cost): Meal(name, cost){
        //this->setTotalCost(cost);
}

std::string Bun::getItemizedList(std::string tail, std::shared_ptr<Meal> start){
        
        std::ostringstream o;
        o.precision(2);
        o << std::fixed << this->getCost();
        std::string price = std::move(o).str();

        std::ostringstream o2;
        o2.precision(2);
        o2 << std::fixed << start->getTotalCost();
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
        return this->getCost();
}

double Bun::getTotalCost(double prev){
        return (this->getCost() + prev);
}

// void Bun::setTotalCost(double c){
//         this->total_cost += c;
// }