/**
*@file Bun.hpp Bun.cpp
*@class Bun
*@author Jaide
*@brief Abstract Bun from the Meal class
        acts as the concrete component - therefore all meals must have a bun
*/
#ifndef BUN_HPP
#define BUN_HPP
#include "Meal.hpp"

/*
*@brief Abstract Bun from the Meal class
        acts as the concrete component - therefore all meals must have a bun
*/
class Bun: public Meal{
    private:

    public:

        /** 
        *@brief initialises a Bun object
        *@param none
        */
        Bun(std::string name, double cost, double prep);

        /** 
        *@brief adds this Ingredient to an already existing Meal object
        *@param meal the meal for this ingredient to be added to
        */
        virtual std::string getItemizedList(std::string s, std::shared_ptr<Meal> start);

        /** 
        *@brief returns a string containing all ingredients and prices of the meal
        *@param none
        *@return std::string
        */
        virtual std::string getItemizedList();
        
        /** 
        *@brief returns the total cost of the meal
        *@param none
        *@return double
        */
        virtual double getTotalCost();

        /** 
        *@brief returns the total cost of the meal
        *@param none
        *@return double
        */
        virtual double getTotalCost(double prev);

        /** 
        *@brief returns the total prep time of the meal
        *@param none
        *@return double
        */
        virtual double getTotalPrepTime();

        /** 
        *@brief returns the total prep time of the meal
        *@param prev the total of previous ingredients in the meal
        *@return double
        */
        virtual double getTotalPrepTime(double prev);

};



#endif