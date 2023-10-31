/**
*@file iteratorTest.cpp
*@namespace iteratorTest
*@class none
*@author Michael
*@brief tests the iterator design pattern and their functions
*/

#include <gtest/gtest.h>
#include "../backend/includes/BillIterator.hpp"
#include "../backend/includes/SingleTableIterator.hpp"
#include "../backend/includes/JoinedTableIterator.hpp"
#include "../backend/includes/CustomerIterator.hpp"
#include "../backend/includes/WaiterIterator.hpp"
#include "../backend/includes/SubBill.hpp"
#include "../backend/includes/MainBill.hpp"

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

        bills.push_back(std::make_shared<SubBill>());
        bills.push_back(std::make_shared<SubBill>());
        bills.push_back(std::make_shared<SubBill>());
        bills.push_back(std::make_shared<SubBill>());
        bills.push_back(std::make_shared<SubBill>());
        bills.push_back(std::make_shared<SubBill>());
        bills.push_back(std::make_shared<SubBill>());
        
        std::shared_ptr<BillIterator> BI = std::make_shared<BillIterator>(bills);

        ASSERT_NE(BI, nullptr);
        EXPECT_EQ(BI->size(), 7);
    }

    TEST(BillIterator_test, FIRST_IS_CURRENT_BEFORE_BILL_ITERATOR)
    {
        std::vector<std::shared_ptr<Bill>> bills;

        bills.push_back(std::make_shared<SubBill>());
        bills.push_back(std::make_shared<SubBill>());
        bills.push_back(std::make_shared<SubBill>());
        bills.push_back(std::make_shared<SubBill>());
        bills.push_back(std::make_shared<SubBill>());
        bills.push_back(std::make_shared<SubBill>());
        bills.push_back(std::make_shared<SubBill>());
        
        std::shared_ptr<BillIterator> BI = std::make_shared<BillIterator>(bills);

        ASSERT_NE(BI, nullptr);
        EXPECT_EQ(BI->size(), 7);
        EXPECT_EQ(BI->first(), BI->currentItem());
    }
    
    TEST(BillIterator_test, ITERATE_BILL_ITERATOR)
    {
        std::vector<std::shared_ptr<Bill>> bills;

        bills.push_back(std::make_shared<SubBill>());
        bills.push_back(std::make_shared<MainBill>());
        bills.push_back(std::make_shared<MainBill>());
        bills.push_back(std::make_shared<MainBill>());
        bills.push_back(std::make_shared<MainBill>());
        bills.push_back(std::make_shared<MainBill>());
        bills.push_back(std::make_shared<MainBill>());
        
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

        bills.push_back(std::make_shared<MainBill>());
        bills.push_back(std::make_shared<MainBill>());
        bills.push_back(std::make_shared<MainBill>());
        bills.push_back(std::make_shared<MainBill>());
        bills.push_back(std::make_shared<MainBill>());
        bills.push_back(std::make_shared<MainBill>());
        bills.push_back(std::make_shared<MainBill>());
        
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
        bills.push_back(std::make_shared<MainBill>());
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

namespace SINGLE_TABLE_ITERATOR_TEST
{
    
    TEST(SingleTableIterator_test, INIT_TABLE_ITERATOR)
    {
        std::list<std::shared_ptr<SingleTable>> tables;
        std::shared_ptr<SingleTableIterator> STI = std::make_shared<SingleTableIterator>(tables);

        ASSERT_NE(STI, nullptr);
        EXPECT_EQ(STI->size(), 0);
    }

    TEST(SingleTableIterator_test, NULL_CURRENT_ITEM_TABLE_ITERATOR)
    {
        std::list<std::shared_ptr<SingleTable>> tables;
        std::shared_ptr<SingleTableIterator> STI = std::make_shared<SingleTableIterator>(tables);

        ASSERT_NE(STI, nullptr);
        EXPECT_EQ(STI->size(), 0);
        EXPECT_EQ(STI->currentItem(), nullptr);
    }

    TEST(SingleTableIterator_test, NULL_FIRST_ITEM_TABLE_ITERATOR)
    {
        std::list<std::shared_ptr<SingleTable>> tables;
        std::shared_ptr<SingleTableIterator> STI = std::make_shared<SingleTableIterator>(tables);

        ASSERT_NE(STI, nullptr);
        EXPECT_EQ(STI->size(), 0);
        EXPECT_EQ(STI->currentItem(), nullptr);
        EXPECT_EQ(STI->first(), nullptr);
    }

    TEST(SingleTableIterator_test, NULL_LAST_ITEM_TABLE_ITERATOR)
    {
        std::list<std::shared_ptr<SingleTable>> tables;
        std::shared_ptr<SingleTableIterator> STI = std::make_shared<SingleTableIterator>(tables);

        ASSERT_NE(STI, nullptr);
        EXPECT_EQ(STI->size(), 0);
        EXPECT_EQ(STI->currentItem(), nullptr);
        EXPECT_EQ(STI->first(), nullptr);
        EXPECT_EQ(STI->last(), nullptr);
    }

    TEST(SingleTableIterator_test, NULL_ISDONE_TABLE_ITERATOR)
    {
        std::list<std::shared_ptr<SingleTable>> tables;
        std::shared_ptr<SingleTableIterator> STI = std::make_shared<SingleTableIterator>(tables);

        ASSERT_NE(STI, nullptr);
        EXPECT_EQ(STI->size(), 0);
        EXPECT_EQ(STI->currentItem(), nullptr);
        EXPECT_EQ(STI->first(), nullptr);
        EXPECT_EQ(STI->last(), nullptr);
        EXPECT_EQ(STI->isDone(), true);
    }

    TEST(SingleTableIterator_test, SIZE_TABLE_ITERATOR)
    {
        std::list<std::shared_ptr<SingleTable>> tables;

        tables.push_back(std::make_shared<SingleTable>());
        tables.push_back(std::make_shared<SingleTable>());
        tables.push_back(std::make_shared<SingleTable>());
        tables.push_back(std::make_shared<SingleTable>());
        std::shared_ptr<SingleTableIterator> STI = std::make_shared<SingleTableIterator>(tables);

        ASSERT_NE(STI, nullptr);
        EXPECT_EQ(STI->size(), 4);
    }

    TEST(SingleTableIterator_test, FIRST_IS_CURRENT_BEFORE_TABLE_ITERATOR)
    {
        std::list<std::shared_ptr<SingleTable>> tables;

        tables.push_back(std::make_shared<SingleTable>());
        tables.push_back(std::make_shared<SingleTable>());
        tables.push_back(std::make_shared<SingleTable>());
        tables.push_back(std::make_shared<SingleTable>());
        
        std::shared_ptr<SingleTableIterator> STI = std::make_shared<SingleTableIterator>(tables);

        ASSERT_NE(STI, nullptr);
        EXPECT_EQ(STI->size(), 4);
        EXPECT_EQ(STI->first(), STI->currentItem());
    }

    TEST(SingleTableIterator_test, ITERATE_TABLE_ITERATOR)
    {
        std::list<std::shared_ptr<SingleTable>> tables;

        tables.push_back(std::make_shared<SingleTable>());
        tables.push_back(std::make_shared<SingleTable>());
        tables.push_back(std::make_shared<SingleTable>());
        tables.push_back(std::make_shared<SingleTable>());
        
        std::shared_ptr<SingleTableIterator> STI = std::make_shared<SingleTableIterator>(tables);

        ASSERT_NE(STI, nullptr);
        EXPECT_EQ(STI->size(), 4);
        EXPECT_EQ(STI->first(), STI->currentItem());

        while(!STI->isDone()){
            STI->next();
        }
    }

    TEST(SingleTableIterator_test, LAST_IS_CURRENT_AFTER_TABLE_ITERATOR)
    {
        std::list<std::shared_ptr<SingleTable>> tables;

        tables.push_back(std::make_shared<SingleTable>());
        tables.push_back(std::make_shared<SingleTable>());
        tables.push_back(std::make_shared<SingleTable>());
        tables.push_back(std::make_shared<SingleTable>());
        
        std::shared_ptr<SingleTableIterator> STI = std::make_shared<SingleTableIterator>(tables);

        ASSERT_NE(STI, nullptr);
        EXPECT_EQ(STI->size(), 4);
        EXPECT_EQ(STI->first(), STI->currentItem());

        while(!STI->isDone()){
            STI->next();
        }

        EXPECT_EQ(STI->last(), STI->currentItem());
    }

    TEST(SingleTableIterator_test, TABLE_ITERATOR_DOWNCAST)
    {
        std::list<std::shared_ptr<SingleTable>> tables;
        tables.push_back(std::make_shared<SingleTable>());
        std::shared_ptr<SingleTableIterator> STI = std::make_shared<SingleTableIterator>(tables);

        ASSERT_NE(STI, nullptr);
        EXPECT_EQ(STI->size(), 1);

        std::shared_ptr<SingleTable> table = std::dynamic_pointer_cast<SingleTable>(STI->currentItem());
        ASSERT_NE(table, nullptr);
        std::shared_ptr<Bill> bill = std::dynamic_pointer_cast<Bill>(STI->currentItem());
        EXPECT_EQ(bill, nullptr);
        std::shared_ptr<Customer> customer = std::dynamic_pointer_cast<Customer>(STI->currentItem());
        EXPECT_EQ(customer, nullptr);
    }
}

namespace JOINED_TABLE_ITERATOR_TEST
{
    
    TEST(JoinedTableIterator_test, INIT_TABLE_ITERATOR)
    {
        std::list<std::shared_ptr<JoinedTable>> tables;
        std::shared_ptr<JoinedTableIterator> JTI = std::make_shared<JoinedTableIterator>(tables);

        ASSERT_NE(JTI, nullptr);
        EXPECT_EQ(JTI->size(), 0);
    }

    TEST(JoinedTableIterator_test, NULL_CURRENT_ITEM_TABLE_ITERATOR)
    {
        std::list<std::shared_ptr<JoinedTable>> tables;
        std::shared_ptr<JoinedTableIterator> JTI = std::make_shared<JoinedTableIterator>(tables);

        ASSERT_NE(JTI, nullptr);
        EXPECT_EQ(JTI->size(), 0);
        EXPECT_EQ(JTI->currentItem(), nullptr);
    }

    TEST(JoinedTableIterator_test, NULL_FIRST_ITEM_TABLE_ITERATOR)
    {
        std::list<std::shared_ptr<JoinedTable>> tables;
        std::shared_ptr<JoinedTableIterator> JTI = std::make_shared<JoinedTableIterator>(tables);

        ASSERT_NE(JTI, nullptr);
        EXPECT_EQ(JTI->size(), 0);
        EXPECT_EQ(JTI->currentItem(), nullptr);
        EXPECT_EQ(JTI->first(), nullptr);
    }

    TEST(JoinedTableIterator_test, NULL_LAST_ITEM_TABLE_ITERATOR)
    {
        std::list<std::shared_ptr<JoinedTable>> tables;
        std::shared_ptr<JoinedTableIterator> JTI = std::make_shared<JoinedTableIterator>(tables);

        ASSERT_NE(JTI, nullptr);
        EXPECT_EQ(JTI->size(), 0);
        EXPECT_EQ(JTI->currentItem(), nullptr);
        EXPECT_EQ(JTI->first(), nullptr);
        EXPECT_EQ(JTI->last(), nullptr);
    }

    TEST(JoinedTableIterator_test, NULL_ISDONE_TABLE_ITERATOR)
    {
        std::list<std::shared_ptr<JoinedTable>> tables;
        std::shared_ptr<JoinedTableIterator> JTI = std::make_shared<JoinedTableIterator>(tables);

        ASSERT_NE(JTI, nullptr);
        EXPECT_EQ(JTI->size(), 0);
        EXPECT_EQ(JTI->currentItem(), nullptr);
        EXPECT_EQ(JTI->first(), nullptr);
        EXPECT_EQ(JTI->last(), nullptr);
        EXPECT_EQ(JTI->isDone(), true);
    }

    TEST(JoinedTableIterator_test, SIZE_TABLE_ITERATOR)
    {
        std::list<std::shared_ptr<JoinedTable>> tables;

        tables.push_back(std::make_shared<JoinedTable>());
        tables.push_back(std::make_shared<JoinedTable>());
        tables.push_back(std::make_shared<JoinedTable>());
        tables.push_back(std::make_shared<JoinedTable>());
        
        std::shared_ptr<JoinedTableIterator> JTI = std::make_shared<JoinedTableIterator>(tables);

        ASSERT_NE(JTI, nullptr);
        EXPECT_EQ(JTI->size(), 4);
    }

    TEST(JoinedTableIterator_test, FIRST_IS_CURRENT_BEFORE_TABLE_ITERATOR)
    {
        std::list<std::shared_ptr<JoinedTable>> tables;

        tables.push_back(std::make_shared<JoinedTable>());
        tables.push_back(std::make_shared<JoinedTable>());
        tables.push_back(std::make_shared<JoinedTable>());
        tables.push_back(std::make_shared<JoinedTable>());
        
        std::shared_ptr<JoinedTableIterator> JTI = std::make_shared<JoinedTableIterator>(tables);

        ASSERT_NE(JTI, nullptr);
        EXPECT_EQ(JTI->size(), 4);
        EXPECT_EQ(JTI->first(), JTI->currentItem());
    }

    TEST(JoinedTableIterator_test, ITERATE_TABLE_ITERATOR)
    {
        std::list<std::shared_ptr<JoinedTable>> tables;

        tables.push_back(std::make_shared<JoinedTable>());
        tables.push_back(std::make_shared<JoinedTable>());
        tables.push_back(std::make_shared<JoinedTable>());
        tables.push_back(std::make_shared<JoinedTable>());
        
        std::shared_ptr<JoinedTableIterator> JTI = std::make_shared<JoinedTableIterator>(tables);

        ASSERT_NE(JTI, nullptr);
        EXPECT_EQ(JTI->size(), 4);
        EXPECT_EQ(JTI->first(), JTI->currentItem());

        while(!JTI->isDone()){
            JTI->next();
        }
    }

    TEST(JoinedTableIterator_test, LAST_IS_CURRENT_AFTER_TABLE_ITERATOR)
    {
        std::list<std::shared_ptr<JoinedTable>> tables;

        tables.push_back(std::make_shared<JoinedTable>());
        tables.push_back(std::make_shared<JoinedTable>());
        tables.push_back(std::make_shared<JoinedTable>());
        tables.push_back(std::make_shared<JoinedTable>());
        
        std::shared_ptr<JoinedTableIterator> JTI = std::make_shared<JoinedTableIterator>(tables);

        ASSERT_NE(JTI, nullptr);
        EXPECT_EQ(JTI->size(), 4);
        EXPECT_EQ(JTI->first(), JTI->currentItem());

        while(!JTI->isDone()){
            JTI->next();
        }

        EXPECT_EQ(JTI->last(), JTI->currentItem());
    }

    TEST(JoinedTableIterator_test, TABLE_ITERATOR_DOWNCAST)
    {
        std::list<std::shared_ptr<JoinedTable>> tables;
        tables.push_back(std::make_shared<JoinedTable>());
        std::shared_ptr<JoinedTableIterator> JTI = std::make_shared<JoinedTableIterator>(tables);

        ASSERT_NE(JTI, nullptr);
        EXPECT_EQ(JTI->size(), 1);

        std::shared_ptr<JoinedTable> table = std::dynamic_pointer_cast<JoinedTable>(JTI->currentItem());
        ASSERT_NE(table, nullptr);
        std::shared_ptr<Bill> bill = std::dynamic_pointer_cast<Bill>(JTI->currentItem());
        EXPECT_EQ(bill, nullptr);
        std::shared_ptr<Customer> customer = std::dynamic_pointer_cast<Customer>(JTI->currentItem());
        EXPECT_EQ(customer, nullptr);
    }
}

namespace WAITER_ITERATOR_TEST{

    TEST(WaiterIterator_test, INIT_PEOPLE_ITERATOR)
    {
        std::map<std::string, std::shared_ptr<Waiter>> waiters;
        std::shared_ptr<WaiterIterator> PI = std::make_shared<WaiterIterator>(waiters);

        ASSERT_NE(PI, nullptr);
        EXPECT_EQ(PI->size(), 0);
    }

    TEST(WaiterIterator_test, NULL_CURRENT_ITEM_PEOPLE_ITERATOR)
    {
        std::map<std::string, std::shared_ptr<Waiter>> waiters;
        std::shared_ptr<WaiterIterator> PI = std::make_shared<WaiterIterator>(waiters);

        ASSERT_NE(PI, nullptr);
        EXPECT_EQ(PI->size(), 0);
        EXPECT_EQ(PI->currentItem(), nullptr);
    }

    TEST(WaiterIterator_test, NULL_FIRST_ITEM_PEOPLE_ITERATOR)
    {
        std::map<std::string, std::shared_ptr<Waiter>> waiters;
        std::shared_ptr<WaiterIterator> PI = std::make_shared<WaiterIterator>(waiters);

        ASSERT_NE(PI, nullptr);
        EXPECT_EQ(PI->size(), 0);
        EXPECT_EQ(PI->currentItem(), nullptr);
        EXPECT_EQ(PI->first(), nullptr);
    }

    TEST(WaiterIterator_test, NULL_LAST_ITEM_PEOPLE_ITERATOR)
    {
        std::map<std::string, std::shared_ptr<Waiter>> waiters;
        std::shared_ptr<WaiterIterator> PI = std::make_shared<WaiterIterator>(waiters);

        ASSERT_NE(PI, nullptr);
        EXPECT_EQ(PI->size(), 0);
        EXPECT_EQ(PI->currentItem(), nullptr);
        EXPECT_EQ(PI->first(), nullptr);
        EXPECT_EQ(PI->last(), nullptr);
    }

    TEST(WaiterIterator_test, NULL_ISDONE_PEOPLE_ITERATOR)
    {
        std::map<std::string, std::shared_ptr<Waiter>> waiters;
        std::shared_ptr<WaiterIterator> PI = std::make_shared<WaiterIterator>(waiters);

        ASSERT_NE(PI, nullptr);
        EXPECT_EQ(PI->size(), 0);
        EXPECT_EQ(PI->currentItem(), nullptr);
        EXPECT_EQ(PI->first(), nullptr);
        EXPECT_EQ(PI->last(), nullptr);
        EXPECT_EQ(PI->isDone(), true);
    }
    
    TEST(WaiterIterator_test, SIZE_PEOPLE_ITERATOR)
    {
        std::map<std::string, std::shared_ptr<Waiter>> waiters;

        waiters.insert({ "33", std::make_shared<Waiter>()});
        waiters.insert({ "39", std::make_shared<Waiter>()});
        waiters.insert({ "25", std::make_shared<Waiter>()});
        waiters.insert({ "19", std::make_shared<Waiter>()});
        waiters.insert({ "40", std::make_shared<Waiter>()});
        waiters.insert({ "30", std::make_shared<Waiter>()});
        waiters.insert({ "86", std::make_shared<Waiter>()});
        waiters.insert({ "63", std::make_shared<Waiter>()});
        waiters.insert({ "58", std::make_shared<Waiter>()});
        waiters.insert({ "29", std::make_shared<Waiter>()});
        waiters.insert({ "59", std::make_shared<Waiter>()});
        waiters.insert({ "57", std::make_shared<Waiter>()});
        waiters.insert({ "96", std::make_shared<Waiter>()});
        waiters.insert({ "28", std::make_shared<Waiter>()});
        
        
        std::shared_ptr<WaiterIterator> PI = std::make_shared<WaiterIterator>(waiters);

        ASSERT_NE(PI, nullptr);
        EXPECT_EQ(PI->size(), 14);
    }

    TEST(WaiterIterator_test, FIRST_IS_CURRENT_BEFORE_PEOPLE_ITERATOR)
    {
        std::map<std::string, std::shared_ptr<Waiter>> waiters;

        waiters.insert({ "33", std::make_shared<Waiter>()});
        waiters.insert({ "39", std::make_shared<Waiter>()});
        waiters.insert({ "25", std::make_shared<Waiter>()});
        waiters.insert({ "19", std::make_shared<Waiter>()});
        waiters.insert({ "40", std::make_shared<Waiter>()});
        waiters.insert({ "30", std::make_shared<Waiter>()});
        waiters.insert({ "86", std::make_shared<Waiter>()});
        waiters.insert({ "63", std::make_shared<Waiter>()});
        waiters.insert({ "58", std::make_shared<Waiter>()});
        waiters.insert({ "29", std::make_shared<Waiter>()});
        waiters.insert({ "59", std::make_shared<Waiter>()});
        waiters.insert({ "57", std::make_shared<Waiter>()});
        waiters.insert({ "96", std::make_shared<Waiter>()});
        waiters.insert({ "28", std::make_shared<Waiter>()});
        
        
        std::shared_ptr<WaiterIterator> PI = std::make_shared<WaiterIterator>(waiters);

        ASSERT_NE(PI, nullptr);
        EXPECT_EQ(PI->size(), 14);
        EXPECT_EQ(PI->first(), PI->currentItem());
    }

    TEST(WaiterIterator_test, ITERATE_PEOPLE_ITERATOR)
    {
        std::map<std::string, std::shared_ptr<Waiter>> waiters;

        waiters.insert({ "33", std::make_shared<Waiter>()});
        waiters.insert({ "39", std::make_shared<Waiter>()});
        waiters.insert({ "25", std::make_shared<Waiter>()});
        waiters.insert({ "19", std::make_shared<Waiter>()});
        waiters.insert({ "40", std::make_shared<Waiter>()});
        waiters.insert({ "30", std::make_shared<Waiter>()});
        waiters.insert({ "86", std::make_shared<Waiter>()});
        waiters.insert({ "63", std::make_shared<Waiter>()});
        waiters.insert({ "58", std::make_shared<Waiter>()});
        waiters.insert({ "29", std::make_shared<Waiter>()});
        waiters.insert({ "59", std::make_shared<Waiter>()});
        waiters.insert({ "57", std::make_shared<Waiter>()});
        waiters.insert({ "96", std::make_shared<Waiter>()});
        waiters.insert({ "28", std::make_shared<Waiter>()});
        
        
        std::shared_ptr<WaiterIterator> PI = std::make_shared<WaiterIterator>(waiters);

        ASSERT_NE(PI, nullptr);
        EXPECT_EQ(PI->size(), 14);
        EXPECT_EQ(PI->first(), PI->currentItem());

        while(!PI->isDone()){
            PI->next();
        }
    }

    TEST(WaiterIterator_test, LAST_IS_CURRENT_AFTER_PEOPLE_ITERATOR)
    {
        std::map<std::string, std::shared_ptr<Waiter>> waiters;

        waiters.insert({ "33", std::make_shared<Waiter>()});
        waiters.insert({ "39", std::make_shared<Waiter>()});
        waiters.insert({ "25", std::make_shared<Waiter>()});
        waiters.insert({ "19", std::make_shared<Waiter>()});
        waiters.insert({ "40", std::make_shared<Waiter>()});
        waiters.insert({ "30", std::make_shared<Waiter>()});
        waiters.insert({ "86", std::make_shared<Waiter>()});
        waiters.insert({ "63", std::make_shared<Waiter>()});
        waiters.insert({ "58", std::make_shared<Waiter>()});
        waiters.insert({ "29", std::make_shared<Waiter>()});
        waiters.insert({ "59", std::make_shared<Waiter>()});
        waiters.insert({ "57", std::make_shared<Waiter>()});
        waiters.insert({ "96", std::make_shared<Waiter>()});
        waiters.insert({ "28", std::make_shared<Waiter>()});
        
        
        std::shared_ptr<WaiterIterator> PI = std::make_shared<WaiterIterator>(waiters);

        ASSERT_NE(PI, nullptr);
        EXPECT_EQ(PI->size(), 14);
        EXPECT_EQ(PI->first(), PI->currentItem());

        while(!PI->isDone()){
            PI->next();
        }

        EXPECT_EQ(PI->last(), PI->currentItem());
    }

    TEST(WaiterIterator_test, PEOPLE_ITERATOR_DOWNCAST)
    {
        std::map<std::string, std::shared_ptr<Waiter>> waiters;
        waiters.insert({ "33", std::make_shared<Waiter>()});
        std::shared_ptr<WaiterIterator> PI = std::make_shared<WaiterIterator>(waiters);

        ASSERT_NE(PI, nullptr);
        EXPECT_EQ(PI->size(), 1);

        std::shared_ptr<Waiter> customer = std::dynamic_pointer_cast<Waiter>(PI->currentItem());
        ASSERT_NE(customer, nullptr);
        std::shared_ptr<Bill> bill = std::dynamic_pointer_cast<Bill>(PI->currentItem());
        EXPECT_EQ(bill, nullptr);
        std::shared_ptr<Table> table = std::dynamic_pointer_cast<Table>(PI->currentItem());
        EXPECT_EQ(table, nullptr);
    }
}
