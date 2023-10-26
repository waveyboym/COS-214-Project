#include "../includes/WaiterIterator.hpp"

WaiterIterator::WaiterIterator(std::map<std::string, std::shared_ptr<Waiter>> waiters)
{
    if(waiters.size() == 0){
        return;
    }
    else{
        this->m_waiters = waiters;
        this->current = this->m_waiters.begin();
    }
}

void WaiterIterator::next()
{
    if(this->size() == 0){
        return;
    }
    else{
        ++this->current;
    }
}

std::shared_ptr<Collectable> WaiterIterator::first()
{
    if(this->size() == 0){
        return nullptr;
    }
    else{
        return this->m_waiters.begin()->second;
    }
}

std::shared_ptr<Collectable> WaiterIterator::last()
{
    if(this->size() == 0){
        return nullptr;
    }
    else{
        return std::prev(this->m_waiters.end())->second;
    }
}

bool WaiterIterator::isDone()
{
    if(this->size() == 0){
        return true;
    }
    else if(this->current == std::prev(this->m_waiters.end())){
        return true;
    }
    else{
        return false;
    }
}

int WaiterIterator::size(){
    return this->m_waiters.size();
}

std::shared_ptr<Collectable> WaiterIterator::currentItem()
{
    if(this->size() == 0){
        return nullptr;
    }
    else{
        return this->current->second;
    }
}