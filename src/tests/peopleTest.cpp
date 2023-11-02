/**
*@file peopleTest.cpp
*@namespace peopleTest
*@class none
*@author Michael
*@brief tests the waiter and customer class
*/

#include <gtest/gtest.h>
#include "../backend/includes/Waiter.hpp"
#include "../backend/includes/Customer.hpp"

namespace customerTest{

    TEST(Customer_test, INIT_CUSTOMER)
    {
        std::shared_ptr<Customer> C = std::make_shared<Customer>();

        ASSERT_NE(C, nullptr);
    }

    TEST(Customer_test, GET_EMOTIONAL_STATE_STRING_CUSTOMER)
    {
        std::shared_ptr<Customer> C = std::make_shared<Customer>();

        EXPECT_EQ(C->getCurrentEmotionalStateString(), "Neutral");
    }

    TEST(Customer_test, GET_EMOTIONAL_STATE_ENUM_CUSTOMER)
    {
        std::shared_ptr<Customer> C = std::make_shared<Customer>();

        EXPECT_EQ(C->getCurrentEmotionalStateEnum(), EMOTIONAL_STATE::NEUTRAL);
    }

    TEST(Customer_test, SWITCH_EMOTIONAL_STATE_TO_ANGRY)
    {
        std::shared_ptr<Customer> C = std::make_shared<Customer>();

        C->setEmotionalState(EMOTIONAL_STATE::ANGRY);

        EXPECT_EQ(C->getCurrentEmotionalStateString(), "Angry");
        EXPECT_EQ(C->getCurrentEmotionalStateEnum(), EMOTIONAL_STATE::ANGRY);
    }

    TEST(Customer_test, SWITCH_EMOTIONAL_STATE_TO_HAPPY)
    {
        std::shared_ptr<Customer> C = std::make_shared<Customer>();

        C->setEmotionalState(EMOTIONAL_STATE::HAPPY);

        EXPECT_EQ(C->getCurrentEmotionalStateString(), "Happy");
        EXPECT_EQ(C->getCurrentEmotionalStateEnum(), EMOTIONAL_STATE::HAPPY);
    }

    TEST(Customer_test, SWITCH_EMOTIONAL_STATE_TO_SLIGHTLY_ANGRY)
    {
        std::shared_ptr<Customer> C = std::make_shared<Customer>();

        C->setEmotionalState(EMOTIONAL_STATE::SLIGHTLY_ANGRY);

        EXPECT_EQ(C->getCurrentEmotionalStateString(), "SlightlyAngry");
        EXPECT_EQ(C->getCurrentEmotionalStateEnum(), EMOTIONAL_STATE::SLIGHTLY_ANGRY);
    }

    TEST(Customer_test, SWITCH_EMOTIONAL_STATE_TO_SLIGHTLY_HAPPY)
    {
        std::shared_ptr<Customer> C = std::make_shared<Customer>();

        C->setEmotionalState(EMOTIONAL_STATE::SLIGHTLY_HAPPY);

        EXPECT_EQ(C->getCurrentEmotionalStateString(), "SlightlyHappy");
        EXPECT_EQ(C->getCurrentEmotionalStateEnum(), EMOTIONAL_STATE::SLIGHTLY_HAPPY);
    }

    TEST(Customer_test, CUSTOMER_SET_UUID)
    {
        std::shared_ptr<Customer> C = std::make_shared<Customer>();

        ASSERT_NE(C, nullptr);

        C->setUUID("customer");

        EXPECT_EQ(C->getUUID(), "customer");
    }
}

namespace waiterTest{
    TEST(Waiter_test, INIT_WAITER)
    {
        std::shared_ptr<Waiter> W = std::make_shared<Waiter>();

        ASSERT_NE(W, nullptr);
    }

    TEST(Waiter_test, WAITER_ASSIGN_TABLE_ID)
    {
        std::shared_ptr<Waiter> W = std::make_shared<Waiter>();

        ASSERT_NE(W, nullptr);

        W->assignID(1);

        EXPECT_EQ(W->getAssignedTableID(), 1);
    }

    TEST(Waiter_test, WAITER_IS_ASSIGNED_TABLE)
    {
        std::shared_ptr<Waiter> W = std::make_shared<Waiter>();

        ASSERT_NE(W, nullptr);

        W->setIsAssignedATable(true);

        EXPECT_EQ(W->isAssignedATable(), true);
    }

    TEST(Waiter_test, WAITER_SET_UUID)
    {
        std::shared_ptr<Waiter> W = std::make_shared<Waiter>();

        ASSERT_NE(W, nullptr);

        W->setUUID("waiter");

        EXPECT_EQ(W->getUUID(), "waiter");
    }

    TEST(Waiter_test, WAITER_JOIN_TABLES)
    {
        std::shared_ptr<Waiter> W = std::make_shared<Waiter>();
        std::shared_ptr<JoinedTable> table_to_join_to = std::make_shared<JoinedTable>();
        std::shared_ptr<Table> table_to_join = std::make_shared<SingleTable>();

        ASSERT_NE(W, nullptr);
        ASSERT_NE(table_to_join_to, nullptr);
        ASSERT_NE(table_to_join, nullptr);

        W->joinTables(table_to_join_to, table_to_join);

        EXPECT_EQ(table_to_join_to->isThisTableJoined(table_to_join), true);
    }
}