/**
*@file iteratorTest.cpp
*@namespace iteratorTest
*@class none
*@author Michael
*@brief tests the iterator design pattern and their functions
*/

#include <gtest/gtest.h>
#include "../backend/includes/BillIterator.hpp"
#include "../backend/includes/TableIterator.hpp"
#include "../backend/includes/CustomerIterator.hpp"

namespace BILL_ITERATOR_TEST{

    TEST(BillIterator_test, INIT_BILL_ITERATOR)
    {
        std::vector<std::shared_ptr<Bill>> bills;
        std::shared_ptr<BillIterator> BI = std::make_shared<BillIterator>(bills);

        ASSERT_NE(BI, nullptr);
        EXPECT_EQ(BI->size(), 0);
    }

    TEST(BillIterator_test, NULL_CURRENT_ITEM_BILL_ITERATOR)
    {
        std::vector<std::shared_ptr<Bill>> bills;
        std::shared_ptr<BillIterator> BI = std::make_shared<BillIterator>(bills);

        ASSERT_NE(BI, nullptr);
        EXPECT_EQ(BI->size(), 0);
        EXPECT_EQ(BI->currentItem(), nullptr);
    }

    TEST(BillIterator_test, NULL_FIRST_ITEM_BILL_ITERATOR)
    {
        std::vector<std::shared_ptr<Bill>> bills;
        std::shared_ptr<BillIterator> BI = std::make_shared<BillIterator>(bills);

        ASSERT_NE(BI, nullptr);
        EXPECT_EQ(BI->size(), 0);
        EXPECT_EQ(BI->currentItem(), nullptr);
        EXPECT_EQ(BI->first(), nullptr);
    }

    TEST(BillIterator_test, NULL_LAST_ITEM_BILL_ITERATOR)
    {
        std::vector<std::shared_ptr<Bill>> bills;
        std::shared_ptr<BillIterator> BI = std::make_shared<BillIterator>(bills);

        ASSERT_NE(BI, nullptr);
        EXPECT_EQ(BI->size(), 0);
        EXPECT_EQ(BI->currentItem(), nullptr);
        EXPECT_EQ(BI->first(), nullptr);
        EXPECT_EQ(BI->last(), nullptr);
    }

    TEST(BillIterator_test, NULL_ISDONE_BILL_ITERATOR)
    {
        std::vector<std::shared_ptr<Bill>> bills;
        std::shared_ptr<BillIterator> BI = std::make_shared<BillIterator>(bills);

        ASSERT_NE(BI, nullptr);
        EXPECT_EQ(BI->size(), 0);
        EXPECT_EQ(BI->currentItem(), nullptr);
        EXPECT_EQ(BI->first(), nullptr);
        EXPECT_EQ(BI->last(), nullptr);
        EXPECT_EQ(BI->isDone(), true);
    }

    TEST(BillIterator_test, SIZE_BILL_ITERATOR)
    {
        std::vector<std::shared_ptr<Bill>> bills;

        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        
        std::shared_ptr<BillIterator> BI = std::make_shared<BillIterator>(bills);

        ASSERT_NE(BI, nullptr);
        EXPECT_EQ(BI->size(), 7);
    }

    TEST(BillIterator_test, FIRST_IS_CURRENT_BEFORE_BILL_ITERATOR)
    {
        std::vector<std::shared_ptr<Bill>> bills;

        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        
        std::shared_ptr<BillIterator> BI = std::make_shared<BillIterator>(bills);

        ASSERT_NE(BI, nullptr);
        EXPECT_EQ(BI->size(), 7);
        EXPECT_EQ(BI->first(), BI->currentItem());
    }
    
    TEST(BillIterator_test, ITERATE_BILL_ITERATOR)
    {
        std::vector<std::shared_ptr<Bill>> bills;

        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        
        std::shared_ptr<BillIterator> BI = std::make_shared<BillIterator>(bills);

        ASSERT_NE(BI, nullptr);
        EXPECT_EQ(BI->size(), 7);
        EXPECT_EQ(BI->first(), BI->currentItem());

        while(!BI->isDone()){
            BI->next();
        }
        
        EXPECT_EQ(BI->last(), BI->currentItem());
    }

    TEST(BillIterator_test, LAST_IS_CURRENT_AFTER_BILL_ITERATOR)
    {
        std::vector<std::shared_ptr<Bill>> bills;

        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        bills.push_back(std::make_shared<Bill>());
        
        std::shared_ptr<BillIterator> BI = std::make_shared<BillIterator>(bills);

        ASSERT_NE(BI, nullptr);
        EXPECT_EQ(BI->size(), 7);
        EXPECT_EQ(BI->first(), BI->currentItem());

        while(!BI->isDone()){
            BI->next();
        }
        
        EXPECT_EQ(BI->last(), BI->currentItem());
    }

    TEST(BillIterator_test, BILL_ITERATOR_DOWNCAST)
    {
        std::vector<std::shared_ptr<Bill>> bills;
        bills.push_back(std::make_shared<Bill>());
        std::shared_ptr<BillIterator> BI = std::make_shared<BillIterator>(bills);

        ASSERT_NE(BI, nullptr);
        EXPECT_EQ(BI->size(), 1);

        std::shared_ptr<Bill> bill = std::dynamic_pointer_cast<Bill>(BI->currentItem());
        ASSERT_NE(bill, nullptr);
        std::shared_ptr<Table> table = std::dynamic_pointer_cast<Table>(BI->currentItem());
        EXPECT_EQ(table, nullptr);
        std::shared_ptr<Customer> customer = std::dynamic_pointer_cast<Customer>(BI->currentItem());
        EXPECT_EQ(customer, nullptr);
    }
}

namespace CUSTOMER_ITERATOR_TEST{

    TEST(CustomerIterator_test, INIT_PEOPLE_ITERATOR)
    {
        std::map<std::string, std::shared_ptr<Customer>> customers;
        std::shared_ptr<CustomerIterator> PI = std::make_shared<CustomerIterator>(customers);

        ASSERT_NE(PI, nullptr);
        EXPECT_EQ(PI->size(), 0);
    }

    TEST(CustomerIterator_test, NULL_CURRENT_ITEM_PEOPLE_ITERATOR)
    {
        std::map<std::string, std::shared_ptr<Customer>> customers;
        std::shared_ptr<CustomerIterator> PI = std::make_shared<CustomerIterator>(customers);

        ASSERT_NE(PI, nullptr);
        EXPECT_EQ(PI->size(), 0);
        EXPECT_EQ(PI->currentItem(), nullptr);
    }

    TEST(CustomerIterator_test, NULL_FIRST_ITEM_PEOPLE_ITERATOR)
    {
        std::map<std::string, std::shared_ptr<Customer>> customers;
        std::shared_ptr<CustomerIterator> PI = std::make_shared<CustomerIterator>(customers);

        ASSERT_NE(PI, nullptr);
        EXPECT_EQ(PI->size(), 0);
        EXPECT_EQ(PI->currentItem(), nullptr);
        EXPECT_EQ(PI->first(), nullptr);
    }

    TEST(CustomerIterator_test, NULL_LAST_ITEM_PEOPLE_ITERATOR)
    {
        std::map<std::string, std::shared_ptr<Customer>> customers;
        std::shared_ptr<CustomerIterator> PI = std::make_shared<CustomerIterator>(customers);

        ASSERT_NE(PI, nullptr);
        EXPECT_EQ(PI->size(), 0);
        EXPECT_EQ(PI->currentItem(), nullptr);
        EXPECT_EQ(PI->first(), nullptr);
        EXPECT_EQ(PI->last(), nullptr);
    }

    TEST(CustomerIterator_test, NULL_ISDONE_PEOPLE_ITERATOR)
    {
        std::map<std::string, std::shared_ptr<Customer>> customers;
        std::shared_ptr<CustomerIterator> PI = std::make_shared<CustomerIterator>(customers);

        ASSERT_NE(PI, nullptr);
        EXPECT_EQ(PI->size(), 0);
        EXPECT_EQ(PI->currentItem(), nullptr);
        EXPECT_EQ(PI->first(), nullptr);
        EXPECT_EQ(PI->last(), nullptr);
        EXPECT_EQ(PI->isDone(), true);
    }
    
    TEST(CustomerIterator_test, SIZE_PEOPLE_ITERATOR)
    {
        std::map<std::string, std::shared_ptr<Customer>> customers;

        customers.insert({ "33", std::make_shared<Customer>()});
        customers.insert({ "39", std::make_shared<Customer>()});
        customers.insert({ "25", std::make_shared<Customer>()});
        customers.insert({ "19", std::make_shared<Customer>()});
        customers.insert({ "40", std::make_shared<Customer>()});
        customers.insert({ "30", std::make_shared<Customer>()});
        customers.insert({ "86", std::make_shared<Customer>()});
        customers.insert({ "63", std::make_shared<Customer>()});
        customers.insert({ "58", std::make_shared<Customer>()});
        customers.insert({ "29", std::make_shared<Customer>()});
        customers.insert({ "59", std::make_shared<Customer>()});
        customers.insert({ "57", std::make_shared<Customer>()});
        customers.insert({ "96", std::make_shared<Customer>()});
        customers.insert({ "28", std::make_shared<Customer>()});
        
        
        std::shared_ptr<CustomerIterator> PI = std::make_shared<CustomerIterator>(customers);

        ASSERT_NE(PI, nullptr);
        EXPECT_EQ(PI->size(), 14);
    }

    TEST(CustomerIterator_test, FIRST_IS_CURRENT_BEFORE_PEOPLE_ITERATOR)
    {
        std::map<std::string, std::shared_ptr<Customer>> customers;

        customers.insert({ "33", std::make_shared<Customer>()});
        customers.insert({ "39", std::make_shared<Customer>()});
        customers.insert({ "25", std::make_shared<Customer>()});
        customers.insert({ "19", std::make_shared<Customer>()});
        customers.insert({ "40", std::make_shared<Customer>()});
        customers.insert({ "30", std::make_shared<Customer>()});
        customers.insert({ "86", std::make_shared<Customer>()});
        customers.insert({ "63", std::make_shared<Customer>()});
        customers.insert({ "58", std::make_shared<Customer>()});
        customers.insert({ "29", std::make_shared<Customer>()});
        customers.insert({ "59", std::make_shared<Customer>()});
        customers.insert({ "57", std::make_shared<Customer>()});
        customers.insert({ "96", std::make_shared<Customer>()});
        customers.insert({ "28", std::make_shared<Customer>()});
        
        
        std::shared_ptr<CustomerIterator> PI = std::make_shared<CustomerIterator>(customers);

        ASSERT_NE(PI, nullptr);
        EXPECT_EQ(PI->size(), 14);
        EXPECT_EQ(PI->first(), PI->currentItem());
    }

    TEST(CustomerIterator_test, ITERATE_PEOPLE_ITERATOR)
    {
        std::map<std::string, std::shared_ptr<Customer>> customers;

        customers.insert({ "33", std::make_shared<Customer>()});
        customers.insert({ "39", std::make_shared<Customer>()});
        customers.insert({ "25", std::make_shared<Customer>()});
        customers.insert({ "19", std::make_shared<Customer>()});
        customers.insert({ "40", std::make_shared<Customer>()});
        customers.insert({ "30", std::make_shared<Customer>()});
        customers.insert({ "86", std::make_shared<Customer>()});
        customers.insert({ "63", std::make_shared<Customer>()});
        customers.insert({ "58", std::make_shared<Customer>()});
        customers.insert({ "29", std::make_shared<Customer>()});
        customers.insert({ "59", std::make_shared<Customer>()});
        customers.insert({ "57", std::make_shared<Customer>()});
        customers.insert({ "96", std::make_shared<Customer>()});
        customers.insert({ "28", std::make_shared<Customer>()});
        
        
        std::shared_ptr<CustomerIterator> PI = std::make_shared<CustomerIterator>(customers);

        ASSERT_NE(PI, nullptr);
        EXPECT_EQ(PI->size(), 14);
        EXPECT_EQ(PI->first(), PI->currentItem());

        while(!PI->isDone()){
            PI->next();
        }
    }

    TEST(CustomerIterator_test, LAST_IS_CURRENT_AFTER_PEOPLE_ITERATOR)
    {
        std::map<std::string, std::shared_ptr<Customer>> customers;

        customers.insert({ "33", std::make_shared<Customer>()});
        customers.insert({ "39", std::make_shared<Customer>()});
        customers.insert({ "25", std::make_shared<Customer>()});
        customers.insert({ "19", std::make_shared<Customer>()});
        customers.insert({ "40", std::make_shared<Customer>()});
        customers.insert({ "30", std::make_shared<Customer>()});
        customers.insert({ "86", std::make_shared<Customer>()});
        customers.insert({ "63", std::make_shared<Customer>()});
        customers.insert({ "58", std::make_shared<Customer>()});
        customers.insert({ "29", std::make_shared<Customer>()});
        customers.insert({ "59", std::make_shared<Customer>()});
        customers.insert({ "57", std::make_shared<Customer>()});
        customers.insert({ "96", std::make_shared<Customer>()});
        customers.insert({ "28", std::make_shared<Customer>()});
        
        
        std::shared_ptr<CustomerIterator> PI = std::make_shared<CustomerIterator>(customers);

        ASSERT_NE(PI, nullptr);
        EXPECT_EQ(PI->size(), 14);
        EXPECT_EQ(PI->first(), PI->currentItem());

        while(!PI->isDone()){
            PI->next();
        }

        EXPECT_EQ(PI->last(), PI->currentItem());
    }

    TEST(CustomerIterator_test, PEOPLE_ITERATOR_DOWNCAST)
    {
        std::map<std::string, std::shared_ptr<Customer>> customers;
        customers.insert({ "33", std::make_shared<Customer>()});
        std::shared_ptr<CustomerIterator> PI = std::make_shared<CustomerIterator>(customers);

        ASSERT_NE(PI, nullptr);
        EXPECT_EQ(PI->size(), 1);

        std::shared_ptr<Customer> customer = std::dynamic_pointer_cast<Customer>(PI->currentItem());
        ASSERT_NE(customer, nullptr);
        std::shared_ptr<Bill> bill = std::dynamic_pointer_cast<Bill>(PI->currentItem());
        EXPECT_EQ(bill, nullptr);
        std::shared_ptr<Table> table = std::dynamic_pointer_cast<Table>(PI->currentItem());
        EXPECT_EQ(table, nullptr);
    }
}

namespace TABLE_ITERATOR_TEST
{
    
    TEST(TableIterator_test, INIT_TABLE_ITERATOR)
    {
        std::vector<std::shared_ptr<Table>> tables;
        std::shared_ptr<TableIterator> TI = std::make_shared<TableIterator>(tables);

        ASSERT_NE(TI, nullptr);
        EXPECT_EQ(TI->size(), 0);
    }

    TEST(TableIterator_test, NULL_CURRENT_ITEM_TABLE_ITERATOR)
    {
        std::vector<std::shared_ptr<Table>> tables;
        std::shared_ptr<TableIterator> TI = std::make_shared<TableIterator>(tables);

        ASSERT_NE(TI, nullptr);
        EXPECT_EQ(TI->size(), 0);
        EXPECT_EQ(TI->currentItem(), nullptr);
    }

    TEST(TableIterator_test, NULL_FIRST_ITEM_TABLE_ITERATOR)
    {
        std::vector<std::shared_ptr<Table>> tables;
        std::shared_ptr<TableIterator> TI = std::make_shared<TableIterator>(tables);

        ASSERT_NE(TI, nullptr);
        EXPECT_EQ(TI->size(), 0);
        EXPECT_EQ(TI->currentItem(), nullptr);
        EXPECT_EQ(TI->first(), nullptr);
    }

    TEST(TableIterator_test, NULL_LAST_ITEM_TABLE_ITERATOR)
    {
        std::vector<std::shared_ptr<Table>> tables;
        std::shared_ptr<TableIterator> TI = std::make_shared<TableIterator>(tables);

        ASSERT_NE(TI, nullptr);
        EXPECT_EQ(TI->size(), 0);
        EXPECT_EQ(TI->currentItem(), nullptr);
        EXPECT_EQ(TI->first(), nullptr);
        EXPECT_EQ(TI->last(), nullptr);
    }

    TEST(TableIterator_test, NULL_ISDONE_TABLE_ITERATOR)
    {
        std::vector<std::shared_ptr<Table>> tables;
        std::shared_ptr<TableIterator> TI = std::make_shared<TableIterator>(tables);

        ASSERT_NE(TI, nullptr);
        EXPECT_EQ(TI->size(), 0);
        EXPECT_EQ(TI->currentItem(), nullptr);
        EXPECT_EQ(TI->first(), nullptr);
        EXPECT_EQ(TI->last(), nullptr);
        EXPECT_EQ(TI->isDone(), true);
    }

    TEST(TableIterator_test, SIZE_TABLE_ITERATOR)
    {
        std::vector<std::shared_ptr<Table>> tables;

        tables.push_back(std::make_shared<Table>());
        tables.push_back(std::make_shared<Table>());
        tables.push_back(std::make_shared<Table>());
        tables.push_back(std::make_shared<Table>());
        
        std::shared_ptr<TableIterator> TI = std::make_shared<TableIterator>(tables);

        ASSERT_NE(TI, nullptr);
        EXPECT_EQ(TI->size(), 4);
    }

    TEST(TableIterator_test, FIRST_IS_CURRENT_BEFORE_TABLE_ITERATOR)
    {
        std::vector<std::shared_ptr<Table>> tables;

        tables.push_back(std::make_shared<Table>());
        tables.push_back(std::make_shared<Table>());
        tables.push_back(std::make_shared<Table>());
        tables.push_back(std::make_shared<Table>());
        
        std::shared_ptr<TableIterator> TI = std::make_shared<TableIterator>(tables);

        ASSERT_NE(TI, nullptr);
        EXPECT_EQ(TI->size(), 4);
        EXPECT_EQ(TI->first(), TI->currentItem());
    }

    TEST(TableIterator_test, ITERATE_TABLE_ITERATOR)
    {
        std::vector<std::shared_ptr<Table>> tables;

        tables.push_back(std::make_shared<Table>());
        tables.push_back(std::make_shared<Table>());
        tables.push_back(std::make_shared<Table>());
        tables.push_back(std::make_shared<Table>());
        
        std::shared_ptr<TableIterator> TI = std::make_shared<TableIterator>(tables);

        ASSERT_NE(TI, nullptr);
        EXPECT_EQ(TI->size(), 4);
        EXPECT_EQ(TI->first(), TI->currentItem());

        while(!TI->isDone()){
            TI->next();
        }
    }

    TEST(TableIterator_test, LAST_IS_CURRENT_AFTER_TABLE_ITERATOR)
    {
        std::vector<std::shared_ptr<Table>> tables;

        tables.push_back(std::make_shared<Table>());
        tables.push_back(std::make_shared<Table>());
        tables.push_back(std::make_shared<Table>());
        tables.push_back(std::make_shared<Table>());
        
        std::shared_ptr<TableIterator> TI = std::make_shared<TableIterator>(tables);

        ASSERT_NE(TI, nullptr);
        EXPECT_EQ(TI->size(), 4);
        EXPECT_EQ(TI->first(), TI->currentItem());

        while(!TI->isDone()){
            TI->next();
        }

        EXPECT_EQ(TI->last(), TI->currentItem());
    }

    TEST(TableIterator_test, TABLE_ITERATOR_DOWNCAST)
    {
        std::vector<std::shared_ptr<Table>> tables;
        tables.push_back(std::make_shared<Table>());
        std::shared_ptr<TableIterator> TI = std::make_shared<TableIterator>(tables);

        ASSERT_NE(TI, nullptr);
        EXPECT_EQ(TI->size(), 1);

        std::shared_ptr<Table> table = std::dynamic_pointer_cast<Table>(TI->currentItem());
        ASSERT_NE(table, nullptr);
        std::shared_ptr<Bill> bill = std::dynamic_pointer_cast<Bill>(TI->currentItem());
        EXPECT_EQ(bill, nullptr);
        std::shared_ptr<Customer> customer = std::dynamic_pointer_cast<Customer>(TI->currentItem());
        EXPECT_EQ(customer, nullptr);
    }
}