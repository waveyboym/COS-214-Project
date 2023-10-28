#include "../includes/SingleTable.hpp"

SingleTable::SingleTable(){

}

bool SingleTable::isSeatedHere(std::shared_ptr<Customer> customer){
    std::list<std::shared_ptr<Customer>>::iterator it;

    for (it = this->customer_list.begin(); it != this->customer_list.end() && *it != customer; ++it);

    if(*it == customer){
        return true;
    }
    else{
        return false;
    }
}

void SingleTable::seatCustomer(std::shared_ptr<Customer> customer){
    this->customer_list.push_back(customer);
}

void SingleTable::unseatCustomer(std::shared_ptr<Customer> customer){
    std::list<std::shared_ptr<Customer>>::iterator it;

    for (it = this->customer_list.begin(); it != this->customer_list.end() && *it != customer; ++it);

    this->customer_list.erase(it);
}

std::list<std::shared_ptr<Customer>> SingleTable::getAllSeatedCustomers(){
    return this->customer_list;
}