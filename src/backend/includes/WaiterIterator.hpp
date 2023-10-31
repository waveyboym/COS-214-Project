/**
*@file WaiterIterator.hpp WaiterIterator.cpp
*@class WaiterIterator
*@implements RestaurantIterator
*@author Michael
*@brief traverses through a map of Waiter objects
*/
#ifndef WAITER_ITERATOR_HPP
#define WAITER_ITERATOR_HPP
#include "RestaurantIterator.hpp"
#include "Waiter.hpp"

/**
*@brief traverses through a map of Waiter objects
*/
class WaiterIterator : public RestaurantIterator{
    private:
        /** 
        *@brief the list to traverse through
        */
        std::map<std::string, std::shared_ptr<Waiter>> m_waiters;
        /** 
        *@brief the current item being pointed to in the list
        */
        std::map<std::string, std::shared_ptr<Waiter>>::iterator current;

    public:
        /** 
        *@brief initialises the list to traverse through
        *@note does nothing if the list is empty
        *@param waiters the list to iterate through
        */
        WaiterIterator(std::map<std::string, std::shared_ptr<Waiter>>& waiters);
        /** 
        *@brief iterates by one step to the next element
        *@note does nothing if the list is empty
        *@param none
        *@return void
        */
        void next();
        /** 
        *@brief returns the first element
        *@note returns nullptr if the list is empty
        *@param none
        *@return std::shared_ptr<Collectable>
        */
        std::shared_ptr<Collectable> first();
        /** 
        *@brief returns the last element
        *@note returns nullptr if the list is empty
        *@param none
        *@return std::shared_ptr<Collectable>
        */
        std::shared_ptr<Collectable> last();
        /** 
        *@brief checks if the entire list has been traversed
        *@note returns true if the list is empty
        *@param none
        *@return bool
        */
        bool isDone();
        /** 
        *@brief gets the size of the list
        *@param none
        *@return int
        */
        int size();
        /** 
        *@brief returns the current item in the iterator list
        *@note returns nullptr if the list is empty
        *@param none
        *@return std::shared_ptr<Collectable>
        */
        std::shared_ptr<Collectable> currentItem(); 
};

#endif