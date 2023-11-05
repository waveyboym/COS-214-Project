/**
*@file Customer.hpp Customer.cpp
*@class Customer
*@author Michael
*@implements People
*@brief a customer object
*/
#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
#include "People.hpp"
#include "Angry.hpp"
#include "Happy.hpp"
#include "Neutral.hpp"
#include "SlightlyHappy.hpp"
#include "SlightlyAngry.hpp"
#include <memory>
#include <chrono>

/** 
*@brief a customer object
*/
class Customer : public People{
    private:
        /** 
        *@brief holds the emotional state of this customer
        */
        std::shared_ptr<EmotionalState> currentEmotionalState;
        /**
        * @brief whether or not this customer is seated
        */
        bool is_seated = false;
        /**
        * @brief whether or not this customer has completed their meal
        */
        bool has_completed_meal = false;
        /**
        * @brief the time at which a customer started eating their food
        */
        std::chrono::time_point<std::chrono::system_clock> start;
        /**
        * @brief the current time which is used to check against the time a customer started eating their food
        */
        std::chrono::time_point<std::chrono::system_clock> current;
    public:
        /** 
        *@brief initialises a customer object
        *@param none
        */
        Customer();
        /** 
        *@brief constructor
        *@param customeruuid the uuid of this customer
        */
        Customer(std::string customeruuid);
        /** 
        *@brief 
        *@param none
        *@return bool
        */
        bool personAction();
        /** 
        *@brief returns the customers current emotional state as a string
        *@param none
        *@return std::string
        */
        std::string getCurrentEmotionalStateString();
        /** 
        *@brief returns the customers current emotional state as an EMOTIONAL_STATE enum
        *@param none
        *@return EMOTIONAL_STATE
        */
        EMOTIONAL_STATE getCurrentEmotionalStateEnum();
        /** 
        *@brief sets a customers emotional state
        *@param state the emotional state enum to set this customer to
        *@return void
        */
        void setEmotionalState(EMOTIONAL_STATE state);

        /** 
        *@brief whether or not this customer is seated
        *@param none
        *@return bool
        */
        bool getIsSeated();
        /** 
        *@brief sets whether or not this customer is seated
        *@param set_to the value to change this to
        *@return void
        */
        void setIsSeated(bool set_to);

        /** 
        *@brief whether or not this customer has finished their meal
        *@param none
        *@return bool
        */
        bool getHasCompletedMeal();

        /** 
        *@brief this customer will start eating their meal when this function is called
        *@param none
        *@return bool
        */
        bool startEatingMeal();

        /** 
        *@brief sets whether or not this customer has finished their meal
        *@param set_to the value to change this to
        *@return void
        */
        void setHasCompletedMeal(bool set_to);
};

#endif