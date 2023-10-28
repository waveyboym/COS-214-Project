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
}

namespace waiterTest{
    
}