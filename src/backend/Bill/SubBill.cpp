#include "../includes/SubBill.hpp"

SubBill::SubBill(){
    this->total = 0;
}

std::string SubBill::toString(){
    return std::to_string(this->total);
}

int SubBill::getTotal(){
    return this->total;
}

void SubBill::setBillTotal(int total_){
    this->total = total_;
}