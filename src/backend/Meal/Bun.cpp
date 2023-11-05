#include "../includes/Bun.hpp"

Bun::Bun(std::string name, double cost, double prepTime): Meal(name, cost, prepTime){
        this->setTotalCost(cost);
        this->setTotalPrepTime(prepTime);
}

std::string Bun::getItemizedList(std::string tail){
        double value = this->getCost(); 
        std::ostringstream stream;
        stream << std::fixed << std::setprecision(2) << value;
        std::string result = stream.str();

        std::string out = this->getName() + "  R" + result + "\n";
        out += tail;

        value = this->getTotalCost(); 
        std::ostringstream stream2;
        stream2 << std::fixed << std::setprecision(2) << value;
        result = stream2.str();
        
        out += "\nTotal: R" + result;
        return out;
}

std::string Bun::getItemizedList(){
        double value = this->getCost(); 
        std::ostringstream stream;
        stream << std::fixed << std::setprecision(2) << value;
        std::string result = stream.str();

        std::string out = this->getName() + "  R" + result + "\n";

        value = this->getTotalCost(); 
        std::ostringstream stream2;
        stream2 << std::fixed << std::setprecision(2) << value;
        result = stream2.str();

        out += "\nTotal: R" + result;
        return out;
}

double Bun::getTotalCost(){
        return this->totalCost;
}

void Bun::setTotalCost(double c){
        this->totalCost += c;
}

double Bun::getTotalPrepTime(){
        return this->totalPrepTime;
}

void Bun::setTotalPrepTime(double t){
        this->totalPrepTime += t;
}