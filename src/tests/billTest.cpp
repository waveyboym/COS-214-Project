/**
*@file billTest.cpp
*@namespace billTest
*@class none
*@author Michael
*@brief tests the bill classes
*/

#include <gtest/gtest.h>
#include <algorithm>
#include "../backend/includes/MainBill.hpp"
#include "../backend/includes/SubBill.hpp"

namespace subBillTest{
    TEST(SubBill_test, INIT_SUB_BILL)
    {
        std::shared_ptr<SubBill> SB = std::make_shared<SubBill>();

        ASSERT_NE(SB, nullptr);
    }

    TEST(SubBill_test, SUB_BILL_SET_BILL)
    {
        std::shared_ptr<SubBill> SB = std::make_shared<SubBill>();

        ASSERT_NE(SB, nullptr);

        SB->setBillTotal(23);
        EXPECT_EQ(SB->getTotal(), 23);
        SB->setBillTotal(56);
        EXPECT_EQ(SB->getTotal(), 56);
        SB->setBillTotal(2383);
        EXPECT_EQ(SB->getTotal(), 2383);
    }

    TEST(SubBill_test, SUB_BILL_TO_STRING)
    {
        std::shared_ptr<SubBill> SB = std::make_shared<SubBill>();

        ASSERT_NE(SB, nullptr);

        SB->setBillTotal(23);
        EXPECT_EQ(SB->toString(), "23");
        SB->setBillTotal(56);
        EXPECT_EQ(SB->toString(), "56");
        SB->setBillTotal(2383);
        EXPECT_EQ(SB->toString(), "2383");
    }
}

namespace mainBillTest{
    TEST(MainBill_test, INIT_MAIN_BILL)
    {
        std::shared_ptr<MainBill> MB = std::make_shared<MainBill>();

        ASSERT_NE(MB, nullptr);
    }

    TEST(MainBill_test, MAIN_BILL_NO_BILL_TO_STRING)
    {
        std::shared_ptr<MainBill> MB = std::make_shared<MainBill>();

        ASSERT_NE(MB, nullptr);

        EXPECT_EQ(MB->toString(), "[]");
    }

    TEST(MainBill_test, MAIN_BILL_NO_BILL_TOTAL)
    {
        std::shared_ptr<MainBill> MB = std::make_shared<MainBill>();

        ASSERT_NE(MB, nullptr);

        EXPECT_EQ(MB->getTotal(), 0);
    }

    TEST(MainBill_test, MAIN_BILL_NO_BILL_GET_ALL_BILLS)
    {
        std::shared_ptr<MainBill> MB = std::make_shared<MainBill>();

        ASSERT_NE(MB, nullptr);

        EXPECT_EQ(MB->getAllBills().size(), 0);
    }

    TEST(MainBill_test, MAIN_BILL_ATTACH_GET_SIZE)
    {
        std::shared_ptr<MainBill> MB = std::make_shared<MainBill>();

        ASSERT_NE(MB, nullptr);

        std::shared_ptr<SubBill> SB = std::make_shared<SubBill>();
        SB->setBillTotal(23);

        MB->attachBill(SB);

        EXPECT_EQ(MB->getAllBills().size(), 1);
    }

    TEST(MainBill_test, MAIN_BILL_ATTACH_TO_STRING)
    {
        std::shared_ptr<MainBill> MB = std::make_shared<MainBill>();

        ASSERT_NE(MB, nullptr);

        std::shared_ptr<SubBill> SB = std::make_shared<SubBill>();
        SB->setBillTotal(23);

        MB->attachBill(SB);

        EXPECT_EQ(MB->toString(), "[23]");
    }

    TEST(MainBill_test, MAIN_BILL_ATTACH_GET_TOTAL)
    {
        std::shared_ptr<MainBill> MB = std::make_shared<MainBill>();

        ASSERT_NE(MB, nullptr);

        std::shared_ptr<SubBill> SB = std::make_shared<SubBill>();
        SB->setBillTotal(23);

        MB->attachBill(SB);

        EXPECT_EQ(MB->getTotal(), 23);
    }

    TEST(MainBill_test, MAIN_BILL_ATTACH_BILLS_GET_SIZE)
    {
        std::shared_ptr<MainBill> MB = std::make_shared<MainBill>();

        ASSERT_NE(MB, nullptr);

        std::shared_ptr<SubBill> SB1 = std::make_shared<SubBill>();
        std::shared_ptr<SubBill> SB2 = std::make_shared<SubBill>();
        std::shared_ptr<SubBill> SB3 = std::make_shared<SubBill>();
        std::shared_ptr<SubBill> SB4 = std::make_shared<SubBill>();

        SB1->setBillTotal(23);
        SB2->setBillTotal(243);
        SB3->setBillTotal(483);
        SB4->setBillTotal(3538);

        MB->attachBill(SB1);
        MB->attachBill(SB2);
        MB->attachBill(SB3);
        MB->attachBill(SB4);

        EXPECT_EQ(MB->getAllBills().size(), 4);
    }

    TEST(MainBill_test, MAIN_BILL_ATTACH_BILLS_TO_STRING)
    {
        std::shared_ptr<MainBill> MB = std::make_shared<MainBill>();

        ASSERT_NE(MB, nullptr);

        std::shared_ptr<SubBill> SB1 = std::make_shared<SubBill>();
        std::shared_ptr<SubBill> SB2 = std::make_shared<SubBill>();
        std::shared_ptr<SubBill> SB3 = std::make_shared<SubBill>();
        std::shared_ptr<SubBill> SB4 = std::make_shared<SubBill>();

        SB1->setBillTotal(23);
        SB2->setBillTotal(243);
        SB3->setBillTotal(483);
        SB4->setBillTotal(3538);

        MB->attachBill(SB1);
        MB->attachBill(SB2);
        MB->attachBill(SB3);
        MB->attachBill(SB4);

        EXPECT_EQ(MB->toString(), "[23,243,483,3538]");
    }

    TEST(MainBill_test, MAIN_BILL_ATTACH_BILLS_GET_TOTAL)
    {
        std::shared_ptr<MainBill> MB = std::make_shared<MainBill>();

        ASSERT_NE(MB, nullptr);

        std::shared_ptr<SubBill> SB1 = std::make_shared<SubBill>();
        std::shared_ptr<SubBill> SB2 = std::make_shared<SubBill>();
        std::shared_ptr<SubBill> SB3 = std::make_shared<SubBill>();
        std::shared_ptr<SubBill> SB4 = std::make_shared<SubBill>();

        SB1->setBillTotal(23);
        SB2->setBillTotal(243);
        SB3->setBillTotal(483);
        SB4->setBillTotal(3538);

        MB->attachBill(SB1);
        MB->attachBill(SB2);
        MB->attachBill(SB3);
        MB->attachBill(SB4);

        EXPECT_EQ(MB->getTotal(), 4287);
    }

    TEST(MainBill_test, MAIN_BILL_GET_ALL_BILLS)
    {
        std::shared_ptr<MainBill> MB = std::make_shared<MainBill>();

        ASSERT_NE(MB, nullptr);

        std::shared_ptr<SubBill> SB1 = std::make_shared<SubBill>();
        std::shared_ptr<SubBill> SB2 = std::make_shared<SubBill>();
        std::shared_ptr<SubBill> SB3 = std::make_shared<SubBill>();
        std::shared_ptr<SubBill> SB4 = std::make_shared<SubBill>();

        SB1->setBillTotal(23);
        SB2->setBillTotal(243);
        SB3->setBillTotal(483);
        SB4->setBillTotal(3538);

        MB->attachBill(SB1);
        MB->attachBill(SB2);
        MB->attachBill(SB3);
        MB->attachBill(SB4);

        std::vector<std::shared_ptr<Bill>> bills = MB->getAllBills();
        std::vector<std::shared_ptr<Bill>>::iterator it = bills.begin();

        EXPECT_EQ((*it), SB1);
        ++it;
        EXPECT_EQ((*it), SB2);
        ++it;
        EXPECT_EQ((*it), SB3);
        ++it;
        EXPECT_EQ((*it), SB4);
    }
}