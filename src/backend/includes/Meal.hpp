/**
*@file Meal.hpp Meal.cpp
*@class Meal
*@author Jaide
*@brief a meal object
*/
#ifndef MEAL_HPP
#define MEAL_HPP
#include <memory>

/** 
*@brief a meal object
*/
class Meal{
    private:
        /** 
        *@brief cost of the ingredient
        */
        double cost;
        /** 
        *@brief name of the ingredient
        */
        std::string name;


    public:
        /** 
        *@brief initialises a Meal object
        *@param none
        */
        Meal(std::string name, double cost); 

        /** 
        *@brief returns the cost of this Meal Object
        *@param none
        *@return double
        */
        double getCost();

        /** 
        *@brief adds to total cost of the meal
        *@param c the cost to add to the total
        */
        virtual void setTotalCost(double c) = 0;

        /** 
        *@brief returns the total cost of the meal
        *@param none
        *@return double
        */
        virtual double getTotalCost() = 0;

        /** 
        *@brief returns the name of this Meal Object
        *@param none
        *@return std::string
        */
        std::string getName();

        /** 
        *@brief returns a string containing all ingredients and prices of the meal
        *@param s a string containing all previous ingredients' information
        *@return std::string
        */
        virtual std::string getItemizedList(std::string s) = 0;

        /** 
        *@brief returns a string containing all ingredients and prices of the meal
        *@param none
        *@return std::string
        */
        virtual std::string getItemizedList() = 0;

};

#endif