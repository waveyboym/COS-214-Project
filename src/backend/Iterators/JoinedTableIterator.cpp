#include "../includes/JoinedTableIterator.hpp"

JoinedTableIterator::JoinedTableIterator(std::list<std::shared_ptr<JoinedTable>>& tables)
{
    if(tables.size() == 0){
        return;
    }
    else{
        this->m_tables = tables;
        this->current = this->m_tables.begin();
    }
}

void JoinedTableIterator::next()
{
    if(this->size() == 0){
        return;
    }
    else{
        if(this->current == this->m_tables.end()){
            return;
        }
        else{
            ++this->current;
        }
    }
}

std::shared_ptr<Collectable> JoinedTableIterator::first()
{
    if(this->size() == 0){
        return nullptr;
    }
    else{
        return *this->m_tables.begin();
    }
}

std::shared_ptr<Collectable> JoinedTableIterator::last()
{
    if(this->size() == 0){
        return nullptr;
    }
    else{
        return this->m_tables.back();
    }
}

bool JoinedTableIterator::isDone()
{
    if(this->size() == 0){
        return true;
    }
    else if(this->current == this->m_tables.end()){
        return true;
    }
    else{
        return false;
    }
}

int JoinedTableIterator::size(){
    return this->m_tables.size();
}

std::shared_ptr<Collectable> JoinedTableIterator::currentItem()
{
    if(this->size() == 0){
        return nullptr;
    }
    else if(this->current == this->m_tables.end()){
        return this->m_tables.back();
    }
    else{ 
        return *this->current;
    }
}