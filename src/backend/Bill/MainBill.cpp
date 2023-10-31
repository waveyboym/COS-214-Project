#include "../includes/MainBill.hpp"

MainBill::MainBill(){

}

std::string MainBill::toString(){
    std::string to_return = "[";

    for(int i = 0; i < this->bills.size(); ++i){
        if(i != this->bills.size() - 1){
            to_return += this->bills[i]->toString() + ",";
        }
        else{
            to_return += this->bills[i]->toString();
        }
    }

    to_return += "]";

    return to_return;
}

int MainBill::getTotal(){
    int to_return = 0;

    for(int i = 0; i < this->bills.size(); ++i){
        to_return += this->bills[i]->getTotal();
    }

    return to_return;
}

void MainBill::attachBill(std::shared_ptr<Bill> bill){
    this->bills.push_back(bill);
}

std::vector<std::shared_ptr<Bill>> MainBill::getAllBills(){
    return this->bills;
}