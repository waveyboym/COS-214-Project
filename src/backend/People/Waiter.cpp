#include "../includes/Waiter.hpp"

Waiter::Waiter(){

}

Waiter::Waiter(std::string waiteruuid){
    this->person_uuid = waiteruuid;
}

bool Waiter::personAction(){
    return false;
}

bool Waiter::isAssignedATable(){
    return this->is_assigned_table;
}

void Waiter::setIsAssignedATable(bool set_to){
    this->is_assigned_table = set_to;
}

int Waiter::getAssignedTableID(){
    return this->assigned_table_id;
}

void Waiter::assignID(int set_to){
    this->assigned_table_id = set_to;
}

void Waiter::assignTable(std::shared_ptr<Table> set_to){
    this->my_table = set_to;
}

void Waiter::getUpdate(std::vector<std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>>> new_meals){

    std::list<std::shared_ptr<Customer>> my_customers = this->my_table.get()->getAllSeatedCustomers();

    for(int i = 0; i < new_meals.size(); i++){

        std::shared_ptr<Customer> customer = new_meals.at(i).second;
        
        for (auto current_my_customer : my_customers) {
            if(current_my_customer == customer){
                std::cout << "Waiter " << this->getUUID() << " delivered Meal to customer " << customer.get()->getUUID() << std::endl;
            }
        }
        
    }

}

std::pair<std::vector<std::shared_ptr<Order>>, std::shared_ptr<Customer>> Waiter::getOrder(){
    std::pair<std::vector<std::shared_ptr<Order>>, std::shared_ptr<Customer>> temp = this->order.front();
    this->order.erase(this->order.begin());
    return temp;
}

void Waiter::takeOrder(std::shared_ptr<Customer> customer){
    std::pair<std::vector<std::shared_ptr<Order>>, std::shared_ptr<Customer>> temp;
    temp.first = customer->getOrder();
    temp.second = customer;
    this->order.push_back(temp);
}

std::shared_ptr<Table> Waiter::getTable(){
    return my_table;
}