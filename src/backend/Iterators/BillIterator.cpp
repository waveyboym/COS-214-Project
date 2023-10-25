#include "../includes/BillIterator.hpp"

BillIterator::BillIterator(std::vector<std::shared_ptr<Bill>> bills)
{
    if(bills.size() == 0){
        return;
    }
    else{
        this->m_bills = bills;
        this->current = this->m_bills.begin();
    }
}

void BillIterator::next()
{
    if(this->size() == 0){
        return;
    }
    else{
        ++this->current;
    }
}

std::shared_ptr<Collectable> BillIterator::first()
{
    if(this->size() == 0){
        return nullptr;
    }
    else{
        return *this->m_bills.begin();
    }
}

std::shared_ptr<Collectable> BillIterator::last()
{
    if(this->size() == 0){
        return nullptr;
    }
    else{
        return this->m_bills.back();
    }
}

bool BillIterator::isDone()
{
    if(this->size() == 0){
        return true;
    }
    else if(*this->current == this->m_bills.back()){
        return true;
    }
    else{
        return false;
    }
}

int BillIterator::size(){
    return this->m_bills.size();
}

std::shared_ptr<Collectable> BillIterator::currentItem()
{
    if(this->size() == 0){
        return nullptr;
    }
    else{
        return *this->current;
    }
}