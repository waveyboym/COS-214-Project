#include "../includes/Waiter.hpp"

Waiter::Waiter(){
    
}

Waiter::Waiter(std::string waiteruuid){
    this->person_uuid = waiteruuid;
}

void Waiter::joinTables(std::shared_ptr<JoinedTable> table_to_join_to, std::shared_ptr<Table> table_to_join){
    table_to_join_to->joinTable(table_to_join);
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