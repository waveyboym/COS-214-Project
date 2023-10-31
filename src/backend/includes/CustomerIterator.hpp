/**
*@file CustomerIterator.hpp CustomerIterator.cpp
*@class CustomerIterator
*@implements RestaurantIterator
*@author Michael
*@brief traverses through a map of Customer objects
*/
#ifndef CUSTOMER_ITERATOR_HPP
#define CUSTOMER_ITERATOR_HPP
#include "RestaurantIterator.hpp"
#include "Customer.hpp"

/**
*@brief traverses through a map of Customer objects
*/
class CustomerIterator : public RestaurantIterator{
    private:
        /** 
        *@brief the list to traverse through
        */
        std::map<std::string, std::shared_ptr<Customer>> m_customers;
        /** 
        *@brief the current item being pointed to in the list
        */
        std::map<std::string, std::shared_ptr<Customer>>::iterator current;

    public:
        /** 
        *@brief initialises the list to traverse through
        *@note does nothing if the list is empty
        *@param customers the list to iterate through
        */
        CustomerIterator(std::map<std::string, std::shared_ptr<Customer>>& customers);
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