/**
*@file MainBill.hpp MainBill.cpp
*@class MainBill
*@author Michael
*@implements Bill
*@brief a MainBill class which is a leaf class of Bill
*/
#ifndef MAIN_BILL_HPP
#define MAIN_BILL_HPP
#include "Bill.hpp"
#include "Meal.hpp"
#include "SubBill.hpp"
#include <string>
#include <memory>
#include <vector>

/** 
*@brief a MainBill class which is a leaf class of Bill
*/
class MainBill : public Bill{
    private:
        /** 
        *@brief a list of all bills for the customer
        */
        std::vector<std::shared_ptr<Bill>> bills;
    public:
        /** 
        *@brief default constructor
        *@param none
        */
        MainBill();
        /** 
        *@brief parameterised constructor
        *@param meal meal object
        *@param split number of sub bills to split it into
        */
        MainBill(std::shared_ptr<Meal> meal, int split);
        /** 
        *@brief returns a string representation of the bill
        *@param none
        *@return std::string
        */
        std::string toString();
        /** 
        *@brief returns the bill total
        *@param none
        *@return double
        */
        double getTotal();
        /** 
        *@brief attaches the passed in bill to this bill
        *@param bill bill to attach to this bill
        *@return void
        */
        void attachBill(std::shared_ptr<Bill> bill);
        /** 
        *@brief gets all bills that are attached to this bill
        *@note this excludes this bill though
        *@param none
        *@return std::vector<std::shared_ptr<Bill>>
        */
        std::vector<std::shared_ptr<Bill>> getAllBills();
};

#endif