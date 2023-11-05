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
// #include "AbstractChef.hpp"

#include "AddBBQSauce.hpp"
#include "AddBeefBurgerPatty.hpp"
#include "AddCaramelizedOnion.hpp"
#include "AddCheese.hpp"
#include "AddChickenBurgerPatty.hpp"
#include "AddColdDrink.hpp"
#include "AddFries.hpp"
#include "AddJuice.hpp"
#include "AddLettuce.hpp"
#include "AddMayo.hpp"
#include "AddNoBun.hpp"
#include "AddNormalBun.hpp"
#include "AddOnion.hpp"
#include "AddPickles.hpp"
#include "AddPineapple.hpp"
#include "AddTomato.hpp"
#include "AddVeggieBurgerPatty.hpp"
#include "AddWater.hpp"
#include "AddWholeWheatBun.hpp"

#include "ConcreteIngredients.hpp"
#include "ConcreteBuns.hpp"

#include <vector>
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
        /**
        * @brief Customer's order
        */
        std::vector<std::shared_ptr<Order>> order;
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
        *@brief set Customer's order
        *@param none
        *@return void 
        */
        void setOrder();

        /**
        *@brief set Customer's order
        *@param none
        *@return std::shared_ptr<Order>
        */
        std::vector<std::shared_ptr<Order>> getOrder() const;
};

#endif