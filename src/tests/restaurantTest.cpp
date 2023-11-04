/**
*@file restaurantTest.cpp
*@namespace restaurantTest
*@class none
*@author Michael, Nicholas
*@brief tests the restaurant class
*/

#include <gtest/gtest.h>
#include "../backend/includes/Restaurant.hpp"

namespace restaurantTest{

    TEST(Restaurant_test, INIT_RESTAURANT)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);
    }

    TEST(Restaurant_test, CUSTOMER_ENTERS_RESTAURANT)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        R->customersEnterRestaurant(1);
    }

    TEST(Restaurant_test, CUSTOMERS_ENTER_RESTAURANT)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        R->customersEnterRestaurant(9);
    }

    TEST(Restaurant_test, CUSTOMER_GETS_SEATED_RESTAURANT)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        R->customersEnterRestaurant(1);
        R->seatAnyCustomer(1);
    }

    TEST(Restaurant_test, CUSTOMERS_GET_SEATED_RESTAURANT)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        R->customersEnterRestaurant(9);
        R->seatAnyCustomer(9);
    }

    TEST(Restaurant_test, CUSTOMERS_GET_UNSEATED_WHEN_DONE)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        R->customersEnterRestaurant(9);
        R->seatAnyCustomer(9);
        R->DEBUG_setAllCustomers_hasCompletedMeal(true);
        R->unseatFinishedCustomers();
    }

    TEST(Restaurant_test, RESTAURANT_PROCESS_CUSTOMER_ORDERS)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        json req_obj = json::parse(
            "{"
                "\"token\":\"e8t38hohe8wotohq903\","
                "\"player\":\"customer\","
                "\"command\":\"create_order\","
                "\"order\":["
                    "{\"name\":\"burger\",\"price\":23},"
                    "{\"name\":\"fries\",\"price\":223},"
                    "{\"name\":\"pizza\",\"price\":533}"
                "]"
            "}");

        EXPECT_EQ(R->FRONTEND_processCustomerOrder(req_obj), "burger,fries,pizza");
    }

    TEST(Restaurant_test, RESTAURANT_PROCESS_CUSTOMER_EMOTION)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        json req_obj = json::parse(
            "{"
                "\"token\":\"e8t38hohe8wotohq903\","
                "\"player\":\"customer\","
                "\"command\":\"change_emotional_state\","
                "\"emotional_state\":\"happy\""
            "}");

        EXPECT_EQ(R->FRONTEND_processCustomersEmotion(req_obj), "happy");
    }

    TEST(Restaurant_test, RESTAURANT_PROCESS_CUSTOMER_UPDATE_CHECK)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        json req_obj = json::parse(
            "{"
                "\"token\":\"e8t38hohe8wotohq903\","
                "\"player\":\"customer\","
                "\"command\":\"update_check\""
            "}");

        EXPECT_EQ(R->FRONTEND_processUpdateCheck(req_obj), "e8t38hohe8wotohq903");
    }

    TEST(Restaurant_test, RESTAURANT_PROCESS_MANAGER_GET_ALL)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        json req_obj = json::parse(
            "{"
                "\"token\":\"e8t38hohe8wotohq903\","
                "\"player\":\"manager\","
                "\"command\":\"get_all\""
            "}");

        EXPECT_EQ(R->FRONTEND_processManagerGetAll(req_obj), "{}");
    }

    TEST(Restaurant_test, RESTAURANT_PROCESS_CUSTOMER_CHECKOUT)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        json req_obj = json::parse(
            "{"
                "\"token\":\"e8t38hohe8wotohq903\","
                "\"player\":\"customer\","
                "\"command\":\"checkout_customer\""
            "}");

        EXPECT_EQ(R->FRONTEND_processCheckOutCustomer(req_obj), "{\"status\":\"success\",\"player\":\"customer\",\"bill\":2000}");
    }

    TEST(Restaurant_test, RESTAURANT_PROCESS_CUSTOMER_RATING)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        json req_obj = json::parse(
            "{"
                "\"token\":\"e8t38hohe8wotohq903\","
                "\"player\":\"customer\","
                "\"command\":\"rate\","
                "\"rating\":5"
            "}");

        EXPECT_EQ(R->FRONTEND_processCustomerRating(req_obj), "rate");
    }

    TEST(Restaurant_test, RESTAURANT_PROCESS_CUSTOMER_PAYING_BILL)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        json req_obj = json::parse(
            "{"
                "\"token\":\"e8t38hohe8wotohq903\","
                "\"player\":\"customer\","
                "\"command\":\"pay_bill\","
                "\"amount\":2000"
            "}");

        EXPECT_EQ(R->FRONTEND_processCustomerPayBill(req_obj), "pay_bill");
    }

    TEST(Restaurant_test, RESTAURANT_ASSIGN_ONE_FREE_WAITER_TABLE)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        R->customersEnterRestaurant(9);
        R->seatAnyCustomer(9);

        R->assignOneFreeWaiter();
        R->assignOneFreeWaiter();
        R->assignOneFreeWaiter();
    }

    TEST(Restaurant_test, RESTAURANT_ASSIGN_ALL_FREE_WAITERS_TABLE)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        R->customersEnterRestaurant(9);
        R->seatAnyCustomer(9);

        R->assignAllFreeWaiters();
    }

}