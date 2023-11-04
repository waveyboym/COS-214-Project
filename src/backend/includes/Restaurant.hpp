/**
*@file Restaurant.hpp Restaurant.cpp
*@class Restaurant
*@author Michael, Carey, Jaden, Linda, Nicholas
*@brief implements the facade pattern and uses various classes to run the restaurant
*@note for any function that starts with FRONTEND, you are not allowed to edit it if you are not working on frontend
*/
#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP
#include "ConcreteMaitreD.hpp"
#include "Waiter.hpp"
#include "Customer.hpp"
#include "SingleTable.hpp"
#include "JoinedTable.hpp"
#include "Waiter.hpp"
#include "CustomerIterator.hpp"
#include "json.hpp"
#include "uuid.h"
#include "color.hpp"
#include <memory>
#include <vector>
#include <cstdlib>
#include <iostream>

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
        *@brief list of all single tables in the restaurant
        */
        std::list<std::shared_ptr<SingleTable>> single_tables;
        /**
        *@brief list of all joined tables in the restaurant
        */
        std::list<std::shared_ptr<JoinedTable>> joined_tables;

        /**
        *@brief constructor
        *@param none
        */
        Restaurant();
        /**
         * @brief generates unique uid
         * @param none
         * @return std::string
        */
        std::string generateUUID();

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
        *@brief progresses the simulation by one step. Each mini-step in this function has a certain chance of occurring
        *@param none
        *@return void
        */
        void progressByOneStep();

        /**
         * @brief a random amount of customers between 0 and 10 will enter the restaurant
         * @param random_number number which will be modded to determine how many customers between 0 and 10 will enter
         * @return void
        */
        void customersEnterRestaurant(int random_number);

        /**
         * @brief a random amount of customers between 0 and 10 will be seated in the restaurant
         * @param random_number number which will be modded to determine how many customers between 0 and 10 will be seated
         * @return void
        */
        void seatAnyCustomer(int random_number);

        /**
         * @brief all customers who have finished their orders will be unseated and removed from the map
         * @param none
         * @return void
        */
       void unseatFinishedCustomers();

        /**
         * @brief the first free waiter will be assigned a table by the maitre'd in the restaurant
         * @param none
         * @return void
        */
        void assignOneFreeWaiter();

        /**
         * @brief all free waiters will be assigned to a table each by the maitre'd in the restaurant
         * @param none
         * @return void
        */
        void assignAllFreeWaiters();

        
        /*****************************************************************************************************************************


        DEBUG/TESTING METHODS


        *******************************************************************************************************************************/
        /**
         * @brief set all customers' hasCompletedMeal variables to the input value
         * @param none
         * @return void
        */
        void DEBUG_setAllCustomers_hasCompletedMeal(bool inp);








        /*****************************************************************************************************************************


        FRONT END CODE, ONLY EDIT BELOW THIS SECTION IF YOU ARE WORKING ON FRONTEND



        *******************************************************************************************************************************/

        /**
        *@brief processes this customers order and returns a response
        *@param req_obj contains the incoming request
        *@return std::string
        */
        std::string FRONTEND_processCustomerOrder(json req_obj);
        /**
        *@brief processes this customers emotions and returns a response
        *@param req_obj contains the incoming request
        *@return std::string
        */
        std::string FRONTEND_processCustomersEmotion(json req_obj);
        /**
        *@brief processes this customers update check and returns a response
        *@param req_obj contains the incoming request
        *@return std::string
        */
        std::string FRONTEND_processUpdateCheck(json req_obj);
                /**
        *@brief returns all necessary data for a manager as a json object
        *@param req_obj contains the incoming request
        *@return std::string
        */
        std::string FRONTEND_processManagerGetAll(json req_obj);

        /**
        *@brief checks out the customer by requesting a bill and returning that as a json object
        *@param req_obj contains the incoming request
        *@return std::string
        */
        std::string FRONTEND_processCheckOutCustomer(json req_obj);

        /**
        *@brief processes the customers changing rating for the restaurant
        *@param req_obj contains the incoming request
        *@return std::string
        */
        std::string FRONTEND_processCustomerRating(json req_obj);

        /**
        *@brief processes the customers request to pay a bill and leave the restaurant
        *@param req_obj contains the incoming request
        *@return std::string
        */
        std::string FRONTEND_processCustomerPayBill(json req_obj);

};

#endif