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
#include <memory>

/** 
*@brief a customer object
*/
class Customer : public People{
    //TODO: implement
    private:
        /** 
        *@brief holds the emotional state of this customer
        */
        std::shared_ptr<EmotionalState> currentEmotionalState;
    public:
        /** 
        *@brief initialises a customer object
        *@param none
        */
        Customer();
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
};

#endif