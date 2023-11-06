#include "../includes/MainBill.hpp"

MainBill::MainBill(){

}

MainBill::MainBill(std::shared_ptr<Meal> meal, int split){
    double total = meal->getTotalCost();
    double subtotal = round((total / split)*100)/100.0;
    for (int i=0; i < split; i++){
        std::shared_ptr<SubBill> sub = std::make_shared<SubBill>();
        sub->setBillTotal(subtotal);
        attachBill(sub);
    }
    
}

std::string MainBill::toString(){
    std::string to_return = "[";

    for(int i = 0; i < this->bills.size(); ++i){
        if(i != this->bills.size() - 1){
            std::string str = this->bills[i]->toString();
            str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
            str.erase ( str.find_last_not_of('.') + 1, std::string::npos );
            
            to_return += str + ",";
        }
        else{
            to_return += this->bills[i]->toString();
        }
    }

    to_return += "]";

    return to_return;
}

double MainBill::getTotal(){
    double to_return = 0;

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