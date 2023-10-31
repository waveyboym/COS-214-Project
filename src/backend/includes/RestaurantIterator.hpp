/**
*@file RestaurantIterator.hpp RestaurantIterator.cpp
*@class RestaurantIterator
*@implements Collectable
*@author Michael
*@brief an interator interface that all concrete iterators must inherit from
*/
#ifndef RESTAURANT_ITERATOR_HPP
#define RESTAURANT_ITERATOR_HPP
#include "Collectable.hpp"
#include <memory>
#include <vector>
#include <map>
#include <string>

/** 
*@brief an interator interface that all concrete iterators must inherit from
*/
class RestaurantIterator{
    public: 
        /** 
        *@brief iterates by one step to the next element
        *@note does nothing if the list is empty
        *@param none
        *@return void
        */
        virtual void next() = 0;
        /** 
        *@brief returns the first element
        *@note returns nullptr if the list is empty
        *@param none
        *@return std::shared_ptr<Collectable>
        */
        virtual std::shared_ptr<Collectable> first() = 0;
        /** 
        *@brief returns the last element
        *@note returns nullptr if the list is empty
        *@param none
        *@return std::shared_ptr<Collectable>
        */
        virtual std::shared_ptr<Collectable> last() = 0;
        /** 
        *@brief checks if the entire list has been traversed
        *@note returns true if the list is empty
        *@param none
        *@return bool
        */
        virtual bool isDone() = 0;
        /** 
        *@brief gets the size of the list
        *@param none
        *@return int
        */
        virtual int size() = 0;
        /** 
        *@brief returns the current item in the iterator list
        *@note returns nullptr if the list is empty
        *@param none
        *@return std::shared_ptr<Collectable>
        */
        virtual std::shared_ptr<Collectable> currentItem() = 0; 
};

#endif