/**
*@file SingleTableIterator.hpp SingleTableIterator.cpp
*@class SingleTableIterator
*@implements RestaurantIterator
*@author Michael
*@brief traverses through a list of SingleTable objects
*/
#ifndef SINGLE_TABLE_ITERATOR_HPP
#define SINGLE_TABLE_ITERATOR_HPP
#include "RestaurantIterator.hpp"
#include "SingleTable.hpp"

/**
*@brief traverses through a list of SingleTable objects
*/
class SingleTableIterator : public RestaurantIterator{
    private:
        /** 
        *@brief the list to traverse through
        */
        std::list<std::shared_ptr<SingleTable>> m_tables;
        /** 
        *@brief the current item being pointed to in the list
        */
        std::list<std::shared_ptr<SingleTable>>::iterator current;

    public:
        /** 
        *@brief initialises the list to traverse through
        *@note does nothing if the list is empty
        *@param tables the list to iterate through
        */
        SingleTableIterator(std::list<std::shared_ptr<SingleTable>>& tables);
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