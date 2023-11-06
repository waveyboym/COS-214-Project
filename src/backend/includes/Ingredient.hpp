/**
*@file Ingredient.hpp Ingredient.cpp
*@class Ingredient
*@author Jaide
*@brief Abstract class for all Ingredient types to inherit from
*/
#ifndef INGREDIENT_HPP
#define INGREDIENT_HPP
#include "Meal.hpp"
/**
*@brief Abstract class for all Ingredient types to inherit from
*/
class Ingredient: public Meal{
    private:
        /** 
        *@brief the meal to which this ingredient belongs
        */
        std::shared_ptr<Meal> meal;
    
    public:
        /** 
        *@brief initialises an Ingredient object
        *@param name the name of the ingredient
        *@param cost the price of the ingredient
        *@param prep the prep time of the ingredient
        *@param meal the Meal object to add this ingredient to
        */
        Ingredient(std::string name, double cost, double prep, std::shared_ptr<Meal> meal);

        // /** 
        // *@brief adds this Ingredient to an already existing Meal object
        // *@param meal the meal for this ingredient to be added to
        // */
        // void setTotalCost(double c);

        /** 
        *@brief returns the total cost of the meal
        *@param none
        *@return double
        */
        double getTotalCost();

        /** 
        *@brief returns the total cost of the meal, calculated via recursive calls of this function
        *@param prev the total cost of the previous item in the list
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
        *@brief returns the total prep time of the meal, calculated via recursive calls of this function
        *@param prev the total prep time of previous item in the list
        *@return double
        */
        virtual double getTotalPrepTime(double prev);

        /** 
        *@brief returns a list of all ingredients for the meal
        *@param s the tail of the string
        *@param start the meal the ingredient is a part of
        *@return std::string
        */
        std::string getItemizedList(std::string s, std::shared_ptr<Meal> start);

        /** 
        *@brief returns a string containing all ingredients and prices of the meal
        *@param none
        *@return std::string
        */
        virtual std::string getItemizedList();

};



#endif