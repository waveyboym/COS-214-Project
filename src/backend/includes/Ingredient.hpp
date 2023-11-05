/**
*@file Ingredient.hpp Ingredient.cpp
*@class Ingredient
*@author Jaide
*@brief Abstract class for all Ingredient types to inherit from
*/
#ifndef INGREDIENT_HPP
#define INGREDIENT_HPP
#include "Meal.hpp"

#include <iostream>
#include <sstream>
#include <iomanip>

class Ingredient: public Meal{
    private:
        std::shared_ptr<Meal> meal;
    
    public:
        /** 
        *@brief initialises an Ingredient object
        *@param meal the Meal object to add this ingredient to
        */
        Ingredient(std::string name, double cost, double prepTime, std::shared_ptr<Meal> meal);

        /** 
        *@brief adds this Ingredient to an already existing Meal object
        *@param meal the meal for this ingredient to be added to
        */
        void setTotalCost(double c);

        /** 
        *@brief returns the total cost of the meal
        *@param none
        *@return double
        */
        double getTotalCost();

        void setTotalPrepTime(double t);

        double getTotalPrepTime();

        /** 
        *@brief adds this Ingredient to an already existing Meal object
        *@param meal the meal for this ingredient to be added to
        */
        std::string getItemizedList(std::string s);

        /** 
        *@brief returns a string containing all ingredients and prices of the meal
        *@param none
        *@return std::string
        */
        virtual std::string getItemizedList();

};



#endif