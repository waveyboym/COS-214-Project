#include "../includes/Bun.hpp"

Bun::Bun(std::string name, double cost): Meal(name, cost){}

std::string Bun::getItemizedList(std::string tail){
        std::string out = this->getName() + "R" + std::to_string(this->getCost()) + "\n";
        out += tail;
        out += "\nTotal: R" + std::to_string(this->getTotalCost());
        return out;
}

std::string Bun::getItemizedList(){
        std::string out = this->getName() + "R" + std::to_string(this->getCost()) + "\n";
        out += "\nTotal: R" + std::to_string(this->getTotalCost());
        return out;
}

double Bun::getTotalCost(){
        return this->totalCost;
}

void Bun::setTotalCost(double c){
        this->totalCost += c;
}