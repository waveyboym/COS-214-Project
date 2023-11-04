/**
*@file tableTest.cpp
*@namespace tableTest
*@class none
*@author Michael
*@brief tests the table class
*/

#include <gtest/gtest.h>
#include <algorithm>
#include "../backend/includes/SingleTable.hpp"
#include "../backend/includes/JoinedTable.hpp"

namespace singleTableTest{
    TEST(SingleTable_test, INIT_SINGLE_TABLE)
    {
        std::shared_ptr<SingleTable> ST = std::make_shared<SingleTable>();

        ASSERT_NE(ST, nullptr);
    }

    TEST(SingleTable_test, SINGLE_TABLE_EMPTY_AVAILABILITY)
    {
        std::shared_ptr<SingleTable> ST = std::make_shared<SingleTable>();

        ASSERT_NE(ST, nullptr);

        EXPECT_EQ(ST->isTableAvailable(), true);
    }

    TEST(SingleTable_test, SINGLE_TABLE_SEAT_CUSTOMER)
    {
        std::shared_ptr<SingleTable> ST = std::make_shared<SingleTable>();

        ASSERT_NE(ST, nullptr);

        std::shared_ptr<Customer> A = std::make_shared<Customer>();
        std::shared_ptr<Customer> B = std::make_shared<Customer>();
        std::shared_ptr<Customer> C = std::make_shared<Customer>();
        std::shared_ptr<Customer> D = std::make_shared<Customer>();

        ST->seatCustomer(A);
        ST->seatCustomer(B);
        ST->seatCustomer(C);
        ST->seatCustomer(D);

        EXPECT_EQ(ST->isSeatedHere(C), true);
    }

    TEST(SingleTable_test, SINGLE_TABLE_NOT_EMPTY_AVAILABILITY)
    {
        std::shared_ptr<SingleTable> ST = std::make_shared<SingleTable>();

        ASSERT_NE(ST, nullptr);

        std::shared_ptr<Customer> A = std::make_shared<Customer>();
        std::shared_ptr<Customer> B = std::make_shared<Customer>();
        std::shared_ptr<Customer> C = std::make_shared<Customer>();
        std::shared_ptr<Customer> D = std::make_shared<Customer>();

        ST->seatCustomer(A);
        ST->seatCustomer(B);
        ST->seatCustomer(C);
        ST->seatCustomer(D);

        EXPECT_EQ(ST->isTableAvailable(), false);
    }

    TEST(SingleTable_test, SINGLE_TABLE_UNSEAT_CUSTOMER)
    {
        std::shared_ptr<SingleTable> ST = std::make_shared<SingleTable>();

        ASSERT_NE(ST, nullptr);

        std::shared_ptr<Customer> A = std::make_shared<Customer>();
        std::shared_ptr<Customer> B = std::make_shared<Customer>();
        std::shared_ptr<Customer> C = std::make_shared<Customer>();
        std::shared_ptr<Customer> D = std::make_shared<Customer>();

        ST->seatCustomer(A);
        ST->seatCustomer(B);
        ST->seatCustomer(C);
        ST->seatCustomer(D);

        ST->unseatCustomer(C);

        EXPECT_EQ(ST->isSeatedHere(C), false);
    }

    TEST(SingleTable_test, SINGLE_TABLE_GET_ALL_SEATED_CUSTOMERS)
    {
        std::shared_ptr<SingleTable> ST = std::make_shared<SingleTable>();

        ASSERT_NE(ST, nullptr);

        std::shared_ptr<Customer> A = std::make_shared<Customer>();
        std::shared_ptr<Customer> B = std::make_shared<Customer>();
        std::shared_ptr<Customer> C = std::make_shared<Customer>();
        std::shared_ptr<Customer> D = std::make_shared<Customer>();

        ST->seatCustomer(A);
        ST->seatCustomer(B);
        ST->seatCustomer(C);
        ST->seatCustomer(D);

        std::list<std::shared_ptr<Customer>> cust_list = ST->getAllSeatedCustomers();
        std::list<std::shared_ptr<Customer>>::iterator it = cust_list.begin();
        EXPECT_EQ((*it), A);
        ++it;
        EXPECT_EQ((*it), B);
        ++it;
        EXPECT_EQ((*it), C);
        ++it;
        EXPECT_EQ((*it), D);
    }
}

namespace joinedTableTest{
    TEST(JoinedTable_test, INIT_JOINED_TABLE)
    {
        std::shared_ptr<JoinedTable> JT = std::make_shared<JoinedTable>();

        ASSERT_NE(JT, nullptr);
    }

    TEST(SingleTable_test, JOINED_TABLE_EMPTY_AVAILABILITY)
    {
        std::shared_ptr<JoinedTable> JT = std::make_shared<JoinedTable>();

        ASSERT_NE(JT, nullptr);

        EXPECT_EQ(JT->isTableAvailable(), true);
    }

    TEST(JoinedTable_test, JOINED_TABLE_SEAT_CUSTOMER)
    {
        std::shared_ptr<JoinedTable> JT = std::make_shared<JoinedTable>();

        ASSERT_NE(JT, nullptr);

        std::shared_ptr<Customer> A = std::make_shared<Customer>();
        std::shared_ptr<Customer> B = std::make_shared<Customer>();
        std::shared_ptr<Customer> C = std::make_shared<Customer>();
        std::shared_ptr<Customer> D = std::make_shared<Customer>();

        JT->seatCustomer(A);
        JT->seatCustomer(B);
        JT->seatCustomer(C);
        JT->seatCustomer(D);

        EXPECT_EQ(JT->isSeatedHere(C), true);
    }
    
    TEST(JoinedTable_test, JOINED_TABLE_UNSEAT_CUSTOMER)
    {
        std::shared_ptr<JoinedTable> JT = std::make_shared<JoinedTable>();

        ASSERT_NE(JT, nullptr);

        std::shared_ptr<Customer> A = std::make_shared<Customer>();
        std::shared_ptr<Customer> B = std::make_shared<Customer>();
        std::shared_ptr<Customer> C = std::make_shared<Customer>();
        std::shared_ptr<Customer> D = std::make_shared<Customer>();

        JT->seatCustomer(A);
        JT->seatCustomer(B);
        JT->seatCustomer(C);
        JT->seatCustomer(D);

        JT->unseatCustomer(C);

        EXPECT_EQ(JT->isSeatedHere(C), false);
    }

    TEST(SingleTable_test, JOINED_TABLE_NOT_EMPTY_AVAILABILITY)
    {
        std::shared_ptr<JoinedTable> JT = std::make_shared<JoinedTable>();

        ASSERT_NE(JT, nullptr);

        std::shared_ptr<Customer> A = std::make_shared<Customer>();
        std::shared_ptr<Customer> B = std::make_shared<Customer>();
        std::shared_ptr<Customer> C = std::make_shared<Customer>();
        std::shared_ptr<Customer> D = std::make_shared<Customer>();

        JT->seatCustomer(A);
        JT->seatCustomer(B);
        JT->seatCustomer(C);
        JT->seatCustomer(D);

        EXPECT_EQ(JT->isTableAvailable(), false);
    }

    TEST(SingleTable_test, JOINED_JOINED_TABLE_NOT_EMPTY_AVAILABILITY)
    {
        std::shared_ptr<JoinedTable> JT1 = std::make_shared<JoinedTable>();
        std::shared_ptr<JoinedTable> JT2 = std::make_shared<JoinedTable>();

        ASSERT_NE(JT1, nullptr);
        ASSERT_NE(JT2, nullptr);

        std::shared_ptr<Customer> E = std::make_shared<Customer>();
        std::shared_ptr<Customer> F = std::make_shared<Customer>();
        std::shared_ptr<Customer> G = std::make_shared<Customer>();
        std::shared_ptr<Customer> H = std::make_shared<Customer>();

        JT2->seatCustomer(E);
        JT2->seatCustomer(F);
        JT2->seatCustomer(G);
        JT2->seatCustomer(H);

        JT1->joinTable(JT2);

        EXPECT_EQ(JT1->isTableAvailable(), false);
    }

    TEST(JoinedTable_test, JOINED_TABLE_GET_ALL_SEATED_CUSTOMERS)
    {
        std::shared_ptr<JoinedTable> JT = std::make_shared<JoinedTable>();

        ASSERT_NE(JT, nullptr);

        std::shared_ptr<Customer> A = std::make_shared<Customer>();
        std::shared_ptr<Customer> B = std::make_shared<Customer>();
        std::shared_ptr<Customer> C = std::make_shared<Customer>();
        std::shared_ptr<Customer> D = std::make_shared<Customer>();

        JT->seatCustomer(A);
        JT->seatCustomer(B);
        JT->seatCustomer(C);
        JT->seatCustomer(D);

        std::list<std::shared_ptr<Customer>> cust_list = JT->getAllSeatedCustomers();
        std::list<std::shared_ptr<Customer>>::iterator it = cust_list.begin();
        EXPECT_EQ((*it), A);
        ++it;
        EXPECT_EQ((*it), B);
        ++it;
        EXPECT_EQ((*it), C);
        ++it;
        EXPECT_EQ((*it), D);
    }

    TEST(JoinedTable_test, JOINED_TABLE_JOIN_TABLE)
    {
        std::shared_ptr<JoinedTable> JT1 = std::make_shared<JoinedTable>();
        std::shared_ptr<JoinedTable> JT2 = std::make_shared<JoinedTable>();

        ASSERT_NE(JT1, nullptr);
        ASSERT_NE(JT2, nullptr);

        std::shared_ptr<Customer> A = std::make_shared<Customer>();
        std::shared_ptr<Customer> B = std::make_shared<Customer>();
        std::shared_ptr<Customer> C = std::make_shared<Customer>();
        std::shared_ptr<Customer> D = std::make_shared<Customer>();

        JT1->seatCustomer(A);
        JT1->seatCustomer(B);
        JT1->seatCustomer(C);
        JT1->seatCustomer(D);

        std::shared_ptr<Customer> E = std::make_shared<Customer>();
        std::shared_ptr<Customer> F = std::make_shared<Customer>();
        std::shared_ptr<Customer> G = std::make_shared<Customer>();
        std::shared_ptr<Customer> H = std::make_shared<Customer>();

        JT2->seatCustomer(E);
        JT2->seatCustomer(F);
        JT2->seatCustomer(G);
        JT2->seatCustomer(H);

        JT1->joinTable(JT2);
        EXPECT_EQ(JT1->isThisTableJoined(JT2), false);
        EXPECT_EQ(JT1->isSeatedHere(G), false);
    }

    TEST(JoinedTable_test, JOINED_TABLE_UNJOIN_TABLE)
    {
        std::shared_ptr<JoinedTable> JT1 = std::make_shared<JoinedTable>();
        std::shared_ptr<JoinedTable> JT2 = std::make_shared<JoinedTable>();

        ASSERT_NE(JT1, nullptr);
        ASSERT_NE(JT2, nullptr);

        std::shared_ptr<Customer> A = std::make_shared<Customer>();
        std::shared_ptr<Customer> B = std::make_shared<Customer>();
        std::shared_ptr<Customer> C = std::make_shared<Customer>();
        std::shared_ptr<Customer> D = std::make_shared<Customer>();

        JT1->seatCustomer(A);
        JT1->seatCustomer(B);
        JT1->seatCustomer(C);
        JT1->seatCustomer(D);

        std::shared_ptr<Customer> E = std::make_shared<Customer>();
        std::shared_ptr<Customer> F = std::make_shared<Customer>();
        std::shared_ptr<Customer> G = std::make_shared<Customer>();
        std::shared_ptr<Customer> H = std::make_shared<Customer>();

        JT2->seatCustomer(E);
        JT2->seatCustomer(F);
        JT2->seatCustomer(G);
        JT2->seatCustomer(H);

        JT1->joinTable(JT2);
        JT1->unjoinTable(JT2);
        EXPECT_EQ(JT1->isThisTableJoined(JT2), false);
        EXPECT_EQ(JT1->isSeatedHere(G), false);
    }

    TEST(JoinedTable_test, JOINED_TABLE_UNSEAT_CUSTOMER_FROM_JOINED_TABLE)
    {
        std::shared_ptr<JoinedTable> JT1 = std::make_shared<JoinedTable>();
        std::shared_ptr<JoinedTable> JT2 = std::make_shared<JoinedTable>();

        ASSERT_NE(JT1, nullptr);
        ASSERT_NE(JT2, nullptr);

        std::shared_ptr<Customer> A = std::make_shared<Customer>();
        std::shared_ptr<Customer> B = std::make_shared<Customer>();
        std::shared_ptr<Customer> C = std::make_shared<Customer>();
        std::shared_ptr<Customer> D = std::make_shared<Customer>();

        JT1->seatCustomer(A);
        JT1->seatCustomer(B);
        JT1->seatCustomer(C);
        JT1->seatCustomer(D);

        std::shared_ptr<Customer> E = std::make_shared<Customer>();
        std::shared_ptr<Customer> F = std::make_shared<Customer>();
        std::shared_ptr<Customer> G = std::make_shared<Customer>();
        std::shared_ptr<Customer> H = std::make_shared<Customer>();

        JT2->seatCustomer(E);
        JT2->seatCustomer(F);
        JT2->seatCustomer(G);
        JT2->seatCustomer(H);

        JT1->joinTable(JT2);

        JT2->unseatCustomer(G);
        EXPECT_EQ(JT1->isSeatedHere(G), false);
    }

    TEST(JoinedTable_test, JOINED_JOINED_TABLE_GET_ALL_SEATED_CUSTOMERS)
    {
        std::shared_ptr<JoinedTable> JT1 = std::make_shared<JoinedTable>();
        std::shared_ptr<JoinedTable> JT2 = std::make_shared<JoinedTable>();

        ASSERT_NE(JT1, nullptr);
        ASSERT_NE(JT2, nullptr);

        std::shared_ptr<Customer> A = std::make_shared<Customer>();
        std::shared_ptr<Customer> B = std::make_shared<Customer>();
        std::shared_ptr<Customer> C = std::make_shared<Customer>();
        std::shared_ptr<Customer> D = std::make_shared<Customer>();
        std::shared_ptr<Customer> E = std::make_shared<Customer>();
        std::shared_ptr<Customer> F = std::make_shared<Customer>();
        std::shared_ptr<Customer> G = std::make_shared<Customer>();
        std::shared_ptr<Customer> H = std::make_shared<Customer>();

        JT1->joinTable(JT2);

        JT1->seatCustomer(A);
        JT1->seatCustomer(B);
        JT1->seatCustomer(C);
        JT1->seatCustomer(D);
        JT1->seatCustomer(E);
        JT1->seatCustomer(F);
        JT1->seatCustomer(G);
        JT1->seatCustomer(H);

        std::list<std::shared_ptr<Customer>> cust_list = JT1->getAllSeatedCustomers();

        EXPECT_EQ((std::find(cust_list.begin(), cust_list.end(), A) != cust_list.end()), true);
        EXPECT_EQ((std::find(cust_list.begin(), cust_list.end(), B) != cust_list.end()), true);
        EXPECT_EQ((std::find(cust_list.begin(), cust_list.end(), C) != cust_list.end()), true);
        EXPECT_EQ((std::find(cust_list.begin(), cust_list.end(), D) != cust_list.end()), true);
        EXPECT_EQ((std::find(cust_list.begin(), cust_list.end(), E) != cust_list.end()), true);
        EXPECT_EQ((std::find(cust_list.begin(), cust_list.end(), F) != cust_list.end()), true);
        EXPECT_EQ((std::find(cust_list.begin(), cust_list.end(), G) != cust_list.end()), false);
        EXPECT_EQ((std::find(cust_list.begin(), cust_list.end(), H) != cust_list.end()), false);
    }

    TEST(JoinedTable_test, OCCUPIED_TABLES_JOIN_TABLES_GET_ALL_SEATED_CUSTOMERS)
    {
        std::shared_ptr<JoinedTable> JT1 = std::make_shared<JoinedTable>();
        std::shared_ptr<JoinedTable> JT2 = std::make_shared<JoinedTable>();

        ASSERT_NE(JT1, nullptr);
        ASSERT_NE(JT2, nullptr);

        std::shared_ptr<Customer> A = std::make_shared<Customer>();
        std::shared_ptr<Customer> B = std::make_shared<Customer>();
        std::shared_ptr<Customer> C = std::make_shared<Customer>();
        std::shared_ptr<Customer> D = std::make_shared<Customer>();

        JT1->seatCustomer(A);
        JT1->seatCustomer(B);
        JT1->seatCustomer(C);
        JT1->seatCustomer(D);

        std::shared_ptr<Customer> E = std::make_shared<Customer>();
        std::shared_ptr<Customer> F = std::make_shared<Customer>();
        std::shared_ptr<Customer> G = std::make_shared<Customer>();
        std::shared_ptr<Customer> H = std::make_shared<Customer>();

        JT2->seatCustomer(E);
        JT2->seatCustomer(F);
        JT2->seatCustomer(G);
        JT2->seatCustomer(H);

        JT1->joinTable(JT2);

        std::list<std::shared_ptr<Customer>> cust_list = JT1->getAllSeatedCustomers();
        std::list<std::shared_ptr<Customer>> cust_list2 = JT2->getAllSeatedCustomers();

        EXPECT_EQ((std::find(cust_list.begin(), cust_list.end(), A) != cust_list.end()), true);
        EXPECT_EQ((std::find(cust_list.begin(), cust_list.end(), B) != cust_list.end()), true);
        EXPECT_EQ((std::find(cust_list.begin(), cust_list.end(), C) != cust_list.end()), true);
        EXPECT_EQ((std::find(cust_list.begin(), cust_list.end(), D) != cust_list.end()), true);
        
        EXPECT_EQ((std::find(cust_list.begin(), cust_list.end(), E) != cust_list.end()), false);
        EXPECT_EQ((std::find(cust_list.begin(), cust_list.end(), F) != cust_list.end()), false);
        EXPECT_EQ((std::find(cust_list.begin(), cust_list.end(), G) != cust_list.end()), false);
        EXPECT_EQ((std::find(cust_list.begin(), cust_list.end(), H) != cust_list.end()), false);

        EXPECT_EQ((std::find(cust_list2.begin(), cust_list2.end(), A) != cust_list2.end()), false);
        EXPECT_EQ((std::find(cust_list2.begin(), cust_list2.end(), B) != cust_list2.end()), false);
        EXPECT_EQ((std::find(cust_list2.begin(), cust_list2.end(), C) != cust_list2.end()), false);
        EXPECT_EQ((std::find(cust_list2.begin(), cust_list2.end(), D) != cust_list2.end()), false);

        EXPECT_EQ((std::find(cust_list2.begin(), cust_list2.end(), E) != cust_list2.end()), true);
        EXPECT_EQ((std::find(cust_list2.begin(), cust_list2.end(), F) != cust_list2.end()), true);
        EXPECT_EQ((std::find(cust_list2.begin(), cust_list2.end(), G) != cust_list2.end()), true);
        EXPECT_EQ((std::find(cust_list2.begin(), cust_list2.end(), H) != cust_list2.end()), true);
    }
}