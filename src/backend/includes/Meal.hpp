/**
*@file Meal.hpp Meal.cpp
*@class Meal
*@author Jaide
*@brief a meal object
*/
#ifndef MEAL_HPP
#define MEAL_HPP
#include <memory>
#include <iostream>

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

        /** 
        *@brief the prep time of the ingredient
        */
        double prep_time;

    public:
        /** 
        *@brief initialises a Meal object
        *@param name name of the meal
        *@param cost cost of the meal
        *@param prep prep time of the meal
        */
        Meal(std::string name, double cost, double prep); 

        /** 
        *@brief returns the cost of this Meal Object
        *@param none
        *@return double
        */
        double getCost();

        /** 
        *@brief returns the the prep_time of this Meal Object
        *@param none
        *@return double
        */
        double getPrepTime();

        // /** 
        // *@brief adds to total cost of the meal
        // *@param c the cost to add to the total
        // */
        // virtual void setTotalCost(double c) = 0;

        /** 
        *@brief returns the total cost of the meal
        *@param none
        *@return double
        */
        virtual double getTotalCost() = 0;

        /** 
        *@brief returns the total cost of the meal
        *@param prev the cost of the previous ingredients in the meal
        *@return double
        */
        virtual double getTotalCost(double prev) = 0;

         /** 
        *@brief returns the total prep time of the meal
        *@param none
        *@return double
        */
        virtual double getTotalPrepTime() = 0;

        /** 
        *@brief returns the total prep time of the meal
        *@param prev the total of previous ingredients in the meal
        *@return double
        */
        virtual double getTotalPrepTime(double prev) = 0;

        /** 
        *@brief returns the name of this Meal Object
        *@param none
        *@return std::string
        */
        std::string getName();

        /** 
        *@brief returns a string containing all ingredients and prices of the meal
        *@param s a string containing all previous ingredients' information
        *@param start the meal whose ingredients must be returned
        *@return std::string
        */
        virtual std::string getItemizedList(std::string s, std::shared_ptr<Meal> start) = 0;

        /** 
        *@brief returns a string containing all ingredients and prices of the meal
        *@param none
        *@return std::string
        */
        virtual std::string getItemizedList() = 0;

};

#endif