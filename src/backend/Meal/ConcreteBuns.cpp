#include "../includes/ConcreteBuns.hpp"

NoBun::NoBun(): Bun("no bun", 0, 0.0){};
std::string NoBun::getItemizedList(){
    return "\nTotal: R" + std::to_string(this->getTotalCost());
}
std::string NoBun::getItemizedList(std::string tail){
    return "tail + \nTotal: R" + std::to_string(this->getTotalCost());
}

PlainBun::PlainBun() : Bun("Plain bun", 10, 3.2){}

WholewheatBun::WholewheatBun(): Bun("Wholewheat Bun", 15.13, 6.4){}
