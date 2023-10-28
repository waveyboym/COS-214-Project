#include "../includes/SingleTableIterator.hpp"

SingleTableIterator::SingleTableIterator(std::list<std::shared_ptr<SingleTable>> tables)
{
    if(tables.size() == 0){
        return;
    }
    else{
        this->m_tables = tables;
        this->current = this->m_tables.begin();
    }
}

void SingleTableIterator::next()
{
    if(this->size() == 0){
        return;
    }
    else{
        ++this->current;
    }
}

std::shared_ptr<Collectable> SingleTableIterator::first()
{
    if(this->size() == 0){
        return nullptr;
    }
    else{
        return *this->m_tables.begin();
    }
}

std::shared_ptr<Collectable> SingleTableIterator::last()
{
    if(this->size() == 0){
        return nullptr;
    }
    else{
        return this->m_tables.back();
    }
}

bool SingleTableIterator::isDone()
{
    if(this->size() == 0){
        return true;
    }
    else if(*this->current == this->m_tables.back()){
        return true;
    }
    else{
        return false;
    }
}

int SingleTableIterator::size(){
    return this->m_tables.size();
}

std::shared_ptr<Collectable> SingleTableIterator::currentItem()
{
    if(this->size() == 0){
        return nullptr;
    }
    else{ 
        return *this->current;
    }
}