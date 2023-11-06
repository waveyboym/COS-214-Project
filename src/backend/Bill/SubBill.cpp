#include "../includes/SubBill.hpp"

SubBill::SubBill(){
    this->total = 0;
}

std::string SubBill::toString(){
    std::string str = std::to_string(this->total);
    str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
    str.erase ( str.find_last_not_of('.') + 1, std::string::npos );
    
    return str;
}

double SubBill::getTotal(){
    return this->total;
}

void SubBill::setBillTotal(double total_){
    this->total = round((total_)*100)/100.0;
}