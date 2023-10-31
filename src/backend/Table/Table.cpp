#include "../includes/Table.hpp"

void Table::nill() {
    // Implementation for the nill function
}

bool Table::isAssignedAWaiter() {
    return this->assigned_a_waiter;
}

void Table::setIsAssignedAWaiter(bool set_to) {
    this->assigned_a_waiter = set_to;
}

int Table::getTableID() {
    return this->table_id;
}

void Table::setID(int set_to) {
    this->table_id = set_to;
}

std::string Table::getAssignedWaiterID() {
    return this->waiter_uuid;
}

void Table::setWaiterID(std::string set_to) {
    this->waiter_uuid = set_to;
}

void Table::setReservedBy(std::shared_ptr<Customer> ReservedBy) {
    this->ReservedBy = ReservedBy;
}

 std::shared_ptr<Customer> Table::getReservedBy() {
    return ReservedBy;
}

