/**
*@file Restaurant.hpp Restaurant.cpp
*@class Restaurant
*@author Michael
*@brief implements the facade pattern and uses various classes to run the restaurant
*/
#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP
#include "ConcreteMaitreD.hpp"
#include "Waiter.hpp"
#include "Customer.hpp"

/**
*@brief implements the facade pattern and uses various classes to run the restaurant
*/
class Restaurant{
    private:
        /**
        *@brief stores a map of all waiters in this restaurant along with their uuid's
        *@note this map should never be modified, that is creating new waiter objects after they have been initialised in the constructor
        */
        std::map<std::string, std::shared_ptr<Waiter>> waiters;
        /**
        *@brief stores a map of all customers in this restaurant along with their uuid's
        */
        std::map<std::string, std::shared_ptr<Customer>> customers;
        /**
        *@brief stores the singular instance of the maitre_d object
        */
        std::shared_ptr<ConcreteMaitreD> maitre_d;

    public:
        /**
        *@brief constructor
        *@param none
        */
        Restaurant();
};

#endif