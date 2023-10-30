/**
*@file maitreDTest.cpp
*@namespace maitreDTest
*@class none
*@author Michael
*@brief tests the ConcreteMaitreD class
*/

#include <gtest/gtest.h>
#include "../backend/includes/ConcreteMaitreD.hpp"

namespace  maitreDTest{

    TEST(maitreD_Test, INIT_MAITRE_D)
    {
        std::shared_ptr<ConcreteMaitreD> CMD = std::make_shared<ConcreteMaitreD>();

        ASSERT_NE(CMD, nullptr);
    }

    TEST(maitreD_Test, MAITRE_D_SEAT_CUSTOMER_SINGLE_TABLE)
    {
        std::shared_ptr<ConcreteMaitreD> CMD = std::make_shared<ConcreteMaitreD>();

        ASSERT_NE(CMD, nullptr);

        std::shared_ptr<Customer> A = std::make_shared<Customer>("1");

        std::list<std::shared_ptr<SingleTable>> single_tables;
        std::list<std::shared_ptr<JoinedTable>> joined_tables;

        single_tables.push_back(std::make_shared<SingleTable>(0));

        EXPECT_EQ(CMD->seatCustomer(single_tables, joined_tables, A), true);

        std::shared_ptr<SingleTableIterator> s_t_i = std::make_shared<SingleTableIterator>(single_tables);

        std::shared_ptr<Table> table = std::dynamic_pointer_cast<Table>(s_t_i->currentItem());

        ASSERT_NE(table, nullptr);

        EXPECT_EQ(table->isSeatedHere(A), true);
    }

    TEST(maitreD_Test, MAITRE_D_SEAT_CUSTOMER_JOINED_TABLE)
    {
        std::shared_ptr<ConcreteMaitreD> CMD = std::make_shared<ConcreteMaitreD>();

        ASSERT_NE(CMD, nullptr);

        std::shared_ptr<Customer> A = std::make_shared<Customer>("1");
        std::shared_ptr<Customer> B = std::make_shared<Customer>("2");

        std::list<std::shared_ptr<SingleTable>> single_tables;
        std::list<std::shared_ptr<JoinedTable>> joined_tables;

        single_tables.push_back(std::make_shared<SingleTable>(0));
        joined_tables.push_back(std::make_shared<JoinedTable>(1));

        EXPECT_EQ(CMD->seatCustomer(single_tables, joined_tables, A), true);
        EXPECT_EQ(CMD->seatCustomer(single_tables, joined_tables, B), true);

        std::shared_ptr<SingleTableIterator> s_t_i = std::make_shared<SingleTableIterator>(single_tables);
        std::shared_ptr<JoinedTableIterator> j_t_i = std::make_shared<JoinedTableIterator>(joined_tables);

        std::shared_ptr<Table> table1 = std::dynamic_pointer_cast<Table>(s_t_i->currentItem());
        std::shared_ptr<Table> table2 = std::dynamic_pointer_cast<Table>(j_t_i->currentItem());

        ASSERT_NE(table1, nullptr);
        ASSERT_NE(table2, nullptr);

        EXPECT_EQ(table1->isSeatedHere(A), true);
        EXPECT_EQ(table1->isSeatedHere(B), false);
        EXPECT_EQ(table2->isSeatedHere(B), true);
    }

    TEST(maitreD_Test, MAITRE_D_SEAT_CUSTOMER_FULL_TABLES)
    {
        std::shared_ptr<ConcreteMaitreD> CMD = std::make_shared<ConcreteMaitreD>();

        ASSERT_NE(CMD, nullptr);

        std::shared_ptr<Customer> A = std::make_shared<Customer>("1");
        std::shared_ptr<Customer> B = std::make_shared<Customer>("2");
        std::shared_ptr<Customer> C = std::make_shared<Customer>("3");

        std::list<std::shared_ptr<SingleTable>> single_tables;
        std::list<std::shared_ptr<JoinedTable>> joined_tables;

        single_tables.push_back(std::make_shared<SingleTable>(0));
        joined_tables.push_back(std::make_shared<JoinedTable>(1));

        EXPECT_EQ(CMD->seatCustomer(single_tables, joined_tables, A), true);
        EXPECT_EQ(CMD->seatCustomer(single_tables, joined_tables, B), true);
        EXPECT_EQ(CMD->seatCustomer(single_tables, joined_tables, C), false);
    }
}