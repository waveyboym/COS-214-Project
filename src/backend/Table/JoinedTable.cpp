#include "../includes/JoinedTable.hpp"

JoinedTable::JoinedTable() {
}

JoinedTable::JoinedTable(int tableid) {
    this->table_id = tableid;
}

void JoinedTable::seatCustomer(std::shared_ptr<Customer> customer) {
    this->customer_list.push_back(customer);
}

void JoinedTable::unseatCustomer(std::shared_ptr<Customer> customer) {
    std::list<std::shared_ptr<Customer>>::iterator it;

    for (it = this->customer_list.begin();
         it != this->customer_list.end() && *it != customer; ++it)
        ;

    if (*it == customer) {
        this->customer_list.erase(it);
    }
}

bool JoinedTable::isSeatedHere(std::shared_ptr<Customer> customer) {
    std::list<std::shared_ptr<Customer>> cust_list;
    cust_list.merge(this->customer_list);

    for (std::list<std::shared_ptr<Table>>::iterator it =
             this->table_list.begin();
         it != this->table_list.end(); ++it) {
        cust_list.merge((*it)->getAllSeatedCustomers());
    }

    std::list<std::shared_ptr<Customer>>::iterator iter;

    for (iter = cust_list.begin(); iter != cust_list.end() && *iter != customer;
         ++iter)
        ;

    if (*iter == customer) {
        return true;
    } else {
        return false;
    }
}

std::list<std::shared_ptr<Customer>> JoinedTable::getAllSeatedCustomers() {
    std::list<std::shared_ptr<Customer>> cust_list;
    cust_list.merge(this->customer_list);

    for (std::list<std::shared_ptr<Table>>::iterator it =
             this->table_list.begin();
         it != this->table_list.end(); ++it) {
        cust_list.merge((*it)->getAllSeatedCustomers());
    }

    return cust_list;
}

void JoinedTable::joinTable(std::shared_ptr<Table> table) {
    this->table_list.push_back(table);
}

void JoinedTable::unjoinTable(std::shared_ptr<Table> table) {
    std::list<std::shared_ptr<Table>>::iterator it;

    for (it = this->table_list.begin();
         it != this->table_list.end() && *it != table; ++it)
        ;

    this->table_list.erase(it);
}

bool JoinedTable::isThisTableJoined(std::shared_ptr<Table> table) {
    std::list<std::shared_ptr<Table>>::iterator it;

    for (it = this->table_list.begin();
         it != this->table_list.end() && *it != table; ++it)
        ;

    if (*it == table) {
        return true;
    } else {
        return false;
    }
}

std::list<std::shared_ptr<Table>> JoinedTable::getAllJoinedTables() {
    return this->table_list;
}

bool JoinedTable::isTableAvailable() {
    std::list<std::shared_ptr<Customer>> cust_list =
        this->getAllSeatedCustomers();

    if (cust_list.size() == 0) {
        return true;
    } else {
        return false;
    }
}
void JoinedTable::setReservedBy(std::shared_ptr<Customer> ReservedBy) {
    this->ReservedBy = ReservedBy;
}

std::shared_ptr<Customer> JoinedTable::getReservedBy() {
    return this->ReservedBy;
}
