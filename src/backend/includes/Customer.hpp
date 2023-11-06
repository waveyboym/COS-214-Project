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
#include <chrono>
#include <vector>

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
        * @brief whether or not this customer has started eating their meal
        */
        bool has_started_eating_meal = false;
        /**
        *@brief whether or not this customer has decided what to order 
        */
        bool has_decided = false;
        /**
        *@brief whether or not this customer has ordered 
        */
        bool has_ordered = false;
        /**
        * @brief the time at which a customer started eating their food
        */
        std::chrono::time_point<std::chrono::system_clock> start;
        /**
        * @brief the current time which is used to check against the time a customer started eating their food
        */
        std::chrono::time_point<std::chrono::system_clock> current;
        /**
        * @brief Customer's order
        */
        std::vector<std::shared_ptr<Order>> order;
        /**
        *@brief whether or not this customer is a frontend customer
        */
        bool is_a_frontend_customer = false;
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
        *@brief whether or not this customer has decided what to order 
        *@param none
        *@return bool
        */
        bool getHasDecided();
        /**
        *@brief whether or not this customer has decided what to order 
        *@param none
        *@return bool
        */
        bool getHasOrdered();
        /**
        *@brief sets has_ordered to true after ordering
        *@param none
        *@return void
        */
        void Ordered();
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

        /**
        *@brief set the frontend Customer's order
        *@param none
        *@return void 
        */
        void setFrontendOrder(std::vector<std::string> order_list);

        /**
        *@brief sets this customer as a frontend customer
        *@param set_to
        *@return void 
        */
        void setIsAFrontendCustomer(bool set_to);

        /**
        *@brief returns whether or not this is a frontend customer
        *@param none
        *@return void 
        */
        bool isAFrontendCustomer();
};

#endif