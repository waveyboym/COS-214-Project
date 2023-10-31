#include "../includes/CustomerIterator.hpp"

CustomerIterator::CustomerIterator(std::map<std::string, std::shared_ptr<Customer>>& customers)
{
    if(customers.size() == 0){
        return;
    }
    else{
        this->m_customers = customers;
        this->current = this->m_customers.begin();
    }
}

void CustomerIterator::next()
{
    if(this->size() == 0){
        return;
    }
    else{
        if(this->current == this->m_customers.end()){
            return;
        }
        else{
            ++this->current;
        }
    }
}

std::shared_ptr<Collectable> CustomerIterator::first()
{
    if(this->size() == 0){
        return nullptr;
    }
    else{
        return this->m_customers.begin()->second;
    }
}

std::shared_ptr<Collectable> CustomerIterator::last()
{
    if(this->size() == 0){
        return nullptr;
    }
    else{
        return std::prev(this->m_customers.end())->second;
    }
}

bool CustomerIterator::isDone()
{
    if(this->size() == 0){
        return true;
    }
    else if(this->current == this->m_customers.end()){
        return true;
    }
    else{
        return false;
    }
}

int CustomerIterator::size(){
    return this->m_customers.size();
}

std::shared_ptr<Collectable> CustomerIterator::currentItem()
{
    if(this->size() == 0){
        return nullptr;
    }
    else if(this->current == this->m_customers.end()){
        return std::prev(this->m_customers.end())->second;
    }
    else{ 
        return this->current->second;
    }
}