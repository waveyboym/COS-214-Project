#include "../includes/TableIterator.hpp"

TableIterator::TableIterator(std::vector<std::shared_ptr<Table>> tables)
{
    if(tables.size() == 0){
        return;
    }
    else{
        this->m_tables = tables;
        this->current = this->m_tables.begin();
    }
}

void TableIterator::next()
{
    if(this->size() == 0){
        return;
    }
    else{
        ++this->current;
    }
}

std::shared_ptr<Collectable> TableIterator::first()
{
    if(this->size() == 0){
        return nullptr;
    }
    else{
        return *this->m_tables.begin();
    }
}

std::shared_ptr<Collectable> TableIterator::last()
{
    if(this->size() == 0){
        return nullptr;
    }
    else{
        return this->m_tables.back();
    }
}

bool TableIterator::isDone()
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

int TableIterator::size(){
    return this->m_tables.size();
}

std::shared_ptr<Collectable> TableIterator::currentItem()
{
    if(this->size() == 0){
        return nullptr;
    }
    else{ 
        return *this->current;
    }
}