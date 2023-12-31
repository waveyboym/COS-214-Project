#include "../includes/ConcreteMaitreD.hpp"

ConcreteMaitreD::ConcreteMaitreD(){

}

bool ConcreteMaitreD::notifyPerson(std::shared_ptr<People> person){
    return true;
}

bool ConcreteMaitreD::unseatCustomer(std::list<std::shared_ptr<SingleTable>>& restaurant_single_tables, std::list<std::shared_ptr<JoinedTable>>& restaurant_joined_tables, std::shared_ptr<Customer> customer_to_unseat, std::map<std::string, std::shared_ptr<Waiter>>& waiters){
    std::shared_ptr<SingleTableIterator> s_t_i = std::make_shared<SingleTableIterator>(restaurant_single_tables);
    std::shared_ptr<JoinedTableIterator> j_t_i = std::make_shared<JoinedTableIterator>(restaurant_joined_tables);
    while(!s_t_i->isDone()){
        std::shared_ptr<Table> table = std::dynamic_pointer_cast<Table>(s_t_i->currentItem());
        if(table != nullptr && table->isSeatedHere(customer_to_unseat)){
            table->unseatCustomer(customer_to_unseat);
            customer_to_unseat->setIsSeated(false);
            if(table->isTableAvailable() && waiters.size() > 0 && waiters.find(table->getAssignedWaiterID()) != waiters.end()){
                table->setIsAssignedAWaiter(false);
                waiters[table->getAssignedWaiterID()]->setIsAssignedATable(false);
            }
            return true;
        }
        s_t_i->next();
    }
    
    while(!j_t_i->isDone()){
        std::shared_ptr<Table> table = std::dynamic_pointer_cast<Table>(j_t_i->currentItem());
        if(table != nullptr && table->isSeatedHere(customer_to_unseat)){
            table->unseatCustomer(customer_to_unseat);
            if(table->isTableAvailable() && waiters.size() > 0 && waiters.find(table->getAssignedWaiterID()) != waiters.end()){
                table->setIsAssignedAWaiter(false);
                waiters[table->getAssignedWaiterID()]->setIsAssignedATable(false);
            }
            return true;
        }
        j_t_i->next();
    }

    return false;
}

bool ConcreteMaitreD::seatCustomer(std::list<std::shared_ptr<SingleTable>>& restaurant_single_tables, std::list<std::shared_ptr<JoinedTable>>& restaurant_joined_tables, std::shared_ptr<Customer> customer_to_seat){
    std::shared_ptr<SingleTableIterator> s_t_i = std::make_shared<SingleTableIterator>(restaurant_single_tables);
    std::shared_ptr<JoinedTableIterator> j_t_i = std::make_shared<JoinedTableIterator>(restaurant_joined_tables);

    while(!s_t_i->isDone()){
        std::shared_ptr<Table> table = std::dynamic_pointer_cast<Table>(s_t_i->currentItem());
        if(table != nullptr && table->isTableAvailable()){
            table->seatCustomer(customer_to_seat);
            customer_to_seat->setIsSeated(true);
            return true;
        }
        s_t_i->next();
    }

    while(!j_t_i->isDone()){
        std::shared_ptr<Table> table = std::dynamic_pointer_cast<Table>(j_t_i->currentItem());
        if(table != nullptr && table->isTableAvailable()){
            table->seatCustomer(customer_to_seat);
            return true;
        }
        j_t_i->next();
    }

    return false;
}

std::list<std::shared_ptr<Table>> ConcreteMaitreD::availableTables(std::list<std::shared_ptr<SingleTable>>& restaurant_single_tables, std::list<std::shared_ptr<JoinedTable>>& restaurant_joined_tables){
    std::list<std::shared_ptr<Table>> table_list;

    std::shared_ptr<SingleTableIterator> s_t_i = std::make_shared<SingleTableIterator>(restaurant_single_tables);
    std::shared_ptr<JoinedTableIterator> j_t_i = std::make_shared<JoinedTableIterator>(restaurant_joined_tables);

    while(!s_t_i->isDone()){
        std::shared_ptr<Table> table = std::dynamic_pointer_cast<Table>(s_t_i->currentItem());
        if(table != nullptr && table->isTableAvailable()){
            table_list.push_back(table);
        }
        s_t_i->next();
    }

    while(!j_t_i->isDone()){
        std::shared_ptr<Table> table = std::dynamic_pointer_cast<Table>(j_t_i->currentItem());
        if(table != nullptr && table->isTableAvailable()){
            table_list.push_back(table);
        }
        j_t_i->next();
    }

    return table_list;
}

bool ConcreteMaitreD::assignWaiterToTable(std::list<std::shared_ptr<SingleTable>>& restaurant_single_tables, std::list<std::shared_ptr<JoinedTable>>& restaurant_joined_tables, std::shared_ptr<Waiter> waiter){
    std::shared_ptr<SingleTableIterator> s_t_i = std::make_shared<SingleTableIterator>(restaurant_single_tables);
    std::shared_ptr<JoinedTableIterator> j_t_i = std::make_shared<JoinedTableIterator>(restaurant_joined_tables);

    while(!s_t_i->isDone()){
        std::shared_ptr<Table> table = std::dynamic_pointer_cast<Table>(s_t_i->currentItem());
        if(table != nullptr && !table->isAssignedAWaiter() && !waiter->isAssignedATable() && !table->isTableAvailable()){
            //assign the waiter the table
            waiter->assignID(table->getTableID());
            waiter->assignTable(table);
            waiter->setIsAssignedATable(true);
            
            table->setWaiterID(waiter->getUUID());
            table->setIsAssignedAWaiter(true);
            return true;
        }
        s_t_i->next();
    }

    while(!j_t_i->isDone()){
        std::shared_ptr<Table> table = std::dynamic_pointer_cast<Table>(j_t_i->currentItem());
        if(table != nullptr && !table->isAssignedAWaiter() && !waiter->isAssignedATable() && !table->isTableAvailable()){
            //assign the waiter the table
            waiter->assignID(table->getTableID());
            waiter->assignTable(table);
            waiter->setIsAssignedATable(true);

            table->setWaiterID(waiter->getUUID());
            table->setIsAssignedAWaiter(true);
            return true;
        }
        j_t_i->next();
    }

    return false;
}