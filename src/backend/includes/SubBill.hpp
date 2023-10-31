/**
*@file SubBill.hpp SubBill.cpp
*@class SubBill
*@author Michael
*@implements Bill
*@brief a SubBill class which is a leaf class of Bill
*/
#ifndef SUB_BILL_HPP
#define SUB_BILL_HPP
#include "Bill.hpp"
#include <string>

/** 
*@brief a SubBill class which is a leaf class of Bill
*/
class SubBill : public Bill{
    private:
        /** 
        *@brief total amount for this bill
        */
        int total;
    public:
        /** 
        *@brief constructor
        *@param none
        */
        SubBill();
        /** 
        *@brief returns a string representation of the bill
        *@param none
        *@return std::string
        */
        std::string toString();
        /** 
        *@brief returns the bill total
        *@param none
        *@return int
        */
        int getTotal();
        /** 
        *@brief sets bill total
        *@param total bill total to set
        *@return void
        */
        void setBillTotal(int total_);
};

#endif