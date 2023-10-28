/**
*@file JoinedTableIterator.hpp JoinedTableIterator.cpp
*@class JoinedTableIterator
*@implements RestaurantIterator
*@author Michael
*@brief traverses through a list of JoinedTable objects
*/
#ifndef JOINED_TABLE_ITERATOR_HPP
#define JOINED_TABLE_ITERATOR_HPP
#include "RestaurantIterator.hpp"
#include "JoinedTable.hpp"

/**
*@brief traverses through a list of JoinedTable objects
*/
class JoinedTableIterator : public RestaurantIterator{
    private:
        /** 
        *@brief the list to traverse through
        */
        std::list<std::shared_ptr<JoinedTable>> m_tables;
        /** 
        *@brief the current item being pointed to in the list
        */
        std::list<std::shared_ptr<JoinedTable>>::iterator current;

    public:
        /** 
        *@brief initialises the list to traverse through
        *@note does nothing if the list is empty
        *@param tables the list to iterate through
        */
        JoinedTableIterator(std::list<std::shared_ptr<JoinedTable>> tables);
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