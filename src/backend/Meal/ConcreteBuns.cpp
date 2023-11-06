#include "../includes/ConcreteBuns.hpp"
#include <sstream>

NoBun::NoBun(): Bun("no bun", 0, 0.0){};
std::string NoBun::getItemizedList(){
    std::ostringstream o;
        o.precision(2);
        o << std::fixed << this->getTotalCost();
        std::string price = std::move(o).str();
    return "\nTotal: R" + price;
}
std::string NoBun::getItemizedList(std::string tail){
    std::ostringstream o;
        o.precision(2);
        o << std::fixed << this->getTotalCost();
        std::string price = std::move(o).str();
    return tail + "\nTotal: R" + price;
}

PlainBun::PlainBun() : Bun("Plain bun", 10, 3.2){}

WholewheatBun::WholewheatBun(): Bun("Wholewheat Bun", 15.13, 6.4){}
