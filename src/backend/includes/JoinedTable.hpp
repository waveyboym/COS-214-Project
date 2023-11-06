/**
*@file JoinedTable.hpp JoinedTable.cpp
*@class JoinedTable
*@author Michael
*@implements Table
*@brief a JoinedTable class which is a composite class of Table
*/
#ifndef JOINED_TABLE_HPP
#define JOINED_TABLE_HPP
#include "Table.hpp"

/** 
*@brief an JoinedTable class which is a composite class of Table
*/
class JoinedTable : public Table{
    private:
        /** 
        *@brief a list of tables that are joined together to this joined table
        */ 
        std::list<std::shared_ptr<Table>> table_list;

        /** 
        *@brief a list containing all customers seated at this joined table
        */ 
        std::list<std::shared_ptr<Customer>> customer_list;

    public:
        /** 
        *@brief constructor
        *@param none
        */ 
        JoinedTable();

        /** 
        *@brief constructor
        *@param tableid id of this table
        */ 
        JoinedTable(int tableid);

        /** 
        *@brief seats a customer at this table
        *@param customer a customer to seat at this table
        *@return void
        */ 
        void seatCustomer(std::shared_ptr<Customer> customer);

        /** 
        *@brief unseats a customer from this table
        *@param customer a customer to unseat from this table
        *@return void
        */ 
        void unseatCustomer(std::shared_ptr<Customer> customer);

        /** 
        *@brief checks if the passed in customer is seated at this table
        *@param customer a customer to check if they are seated at this table
        *@return bool
        */ 
        bool isSeatedHere(std::shared_ptr<Customer> customer);

        /** 
        *@brief gets all customers seated at this table
        *@param none
        *@return std::list<std::shared_ptr<Customer>>
        */ 
        std::list<std::shared_ptr<Customer>> getAllSeatedCustomers();

        /** 
        *@brief join the passed in table to this table
        *@param table a table to join to this table
        *@return void
        */ 
        void joinTable(std::shared_ptr<Table> table);

        /** 
        *@brief unjoins the passed in table from this table
        *@param table a table to un-join from this table
        *@return void
        */ 
        void unjoinTable(std::shared_ptr<Table> table);

        /** 
        *@brief checks if the passed in table is joined to this table
        *@param table a table to check if it is joined to this table
        *@return bool
        */ 
        bool isThisTableJoined(std::shared_ptr<Table> table);

        /** 
        *@brief gets all tables that are joined to this table
        *@param none
        *@return std::list<std::shared_ptr<Table>>
        */ 
        std::list<std::shared_ptr<Table>> getAllJoinedTables();

        /** 
        *@brief checks if this table is occupied
        *@param none
        *@return bool
        */ 
        bool isTableAvailable();
};

#endif