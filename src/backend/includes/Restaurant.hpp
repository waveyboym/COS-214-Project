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
#include "../includes/json.hpp"
#include <memory>
#include <vector>

using json = nlohmann::json;

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
        /**
        *@brief constructor
        *@param none
        */
        Restaurant();

    public:
        /**
        *@brief destructor
        */
        ~Restaurant();
        /**
        *@brief constructor
        *@note this function is deleted so it can never be accessed. If you use this function and try to compile, your code will not compile
        */
        Restaurant(Restaurant const&) = delete;
        /**
        *@brief equals operator
        *@note this function is deleted so it can never be accessed. If you use this function and try to compile, your code will not compile
        */
        Restaurant& operator=(Restaurant const&) = delete;
        /**
        *@brief gets an instance of this restaurant and returns it as a shared pointer
        *@note if no restaurant instance exists, one is created and returned, otherwise the existing instance is returned
        */
        static std::shared_ptr<Restaurant> instance();
        /**
        *@brief processes this customers order and returns a response
        *@param req_obj contains the incoming request
        *@return std::string
        */
        std::string processCustomerOrder(json req_obj);
        /**
        *@brief processes this customers emotions and returns a response
        *@param req_obj contains the incoming request
        *@return std::string
        */
        std::string processCustomersEmotion(json req_obj);
        /**
        *@brief processes this customers update check and returns a response
        *@param req_obj contains the incoming request
        *@return std::string
        */
        std::string processUpdateCheck(json req_obj);
                /**
        *@brief returns all necessary data for a manager as a json object
        *@param req_obj contains the incoming request
        *@return std::string
        */
        std::string processManagerGetAll(json req_obj);

        /**
        *@brief checks out the customer by requesting a bill and returning that as a json object
        *@param req_obj contains the incoming request
        *@return std::string
        */
        std::string processCheckOutCustomer(json req_obj);

        /**
        *@brief processes the customers changing rating for the restaurant
        *@param req_obj contains the incoming request
        *@return std::string
        */
        std::string processCustomerRating(json req_obj);

        /**
        *@brief processes the customers request to pay a bill and leave the restaurant
        *@param req_obj contains the incoming request
        *@return std::string
        */
        std::string processCustomerPayBill(json req_obj);
};

#endif