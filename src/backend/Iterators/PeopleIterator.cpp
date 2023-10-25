#include "../includes/PeopleIterator.hpp"

PeopleIterator::PeopleIterator(std::map<std::string, std::shared_ptr<People>> people)
{
    if(people.size() == 0){
        return;
    }
    else{
        this->m_people = people;
        this->current = this->m_people.begin();
    }
}

void PeopleIterator::next()
{
    if(this->size() == 0){
        return;
    }
    else{
        ++this->current;
    }
}

std::shared_ptr<Collectable> PeopleIterator::first()
{
    if(this->size() == 0){
        return nullptr;
    }
    else{
        return this->m_people.begin()->second;
    }
}

std::shared_ptr<Collectable> PeopleIterator::last()
{
    if(this->size() == 0){
        return nullptr;
    }
    else{
        return std::prev(this->m_people.end())->second;
    }
}

bool PeopleIterator::isDone()
{
    if(this->size() == 0){
        return true;
    }
    else if(this->current == std::prev(this->m_people.end())){
        return true;
    }
    else{
        return false;
    }
}

int PeopleIterator::size(){
    return this->m_people.size();
}

std::shared_ptr<Collectable> PeopleIterator::currentItem()
{
    if(this->size() == 0){
        return nullptr;
    }
    else{
        return this->current->second;
    }
}