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

#include <iostream>
#include <sstream>
#include <iomanip>

class Bun: public Meal{
    private:
        /** 
        *@brief total cost of the meal
        */
        double totalCost;

        double totalPrepTime;

    public:

        /** 
        *@brief initialises a Bun object
        *@param none
        */
        Bun(std::string name, double cost, double prepTime);

        /** 
        *@brief adds this Ingredient to an already existing Meal object
        *@param meal the meal for this ingredient to be added to
        */
        virtual std::string getItemizedList(std::string s);

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
        *@brief adds the input value to the total cost of the meal
        *@param c value to add to total
        */
        void setTotalCost(double c);

        double getTotalPrepTime();

        void setTotalPrepTime(double t);

};



#endif