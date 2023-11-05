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

namespace restaurantFrontEndTest{

    TEST(RestaurantFrontend_test, INIT_RESTAURANT)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);
    }

    TEST(RestaurantFrontend_test, PRINT_RESTAURANT_TABLE_WAITERS)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        std::cout << R->FRONTEND_getTableObjects("waiters") << std::endl;
    }

    TEST(RestaurantFrontend_test, PRINT_RESTAURANT_TABLE_CUSTOMERS)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        std::cout << R->FRONTEND_getTableObjects("customers") << std::endl;
    }

    TEST(RestaurantFrontend_test, PRINT_RESTAURANT_TABLE_TABLES)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        std::cout << R->FRONTEND_getTableObjects("table") << std::endl;
    }

    TEST(RestaurantFrontend_test, PRINT_RESTAURANT_GET_ALL)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        json req_obj = json::parse("{}");

        std::cout << R->FRONTEND_processManagerGetAll(req_obj) << std::endl;
    }

    TEST(RestaurantFrontend_test, PRINT_RESTAURANT_GET_TABLES_TABLE_WAITERS)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        json req_obj = json::parse(
            "{"
                "\"update_table\":\"waiters\""
            "}");

        std::cout << R->FRONTEND_processManagerGetTable(req_obj) << std::endl;
    }

    TEST(RestaurantFrontend_test, PRINT_RESTAURANT_GET_TABLES_TABLE_CUSTOMERS)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        json req_obj = json::parse(
            "{"
                "\"update_table\":\"customers\""
            "}");

        std::cout << R->FRONTEND_processManagerGetTable(req_obj) << std::endl;
    }

    TEST(RestaurantFrontend_test, PRINT_RESTAURANT_GET_TABLES_TABLE_TABLES)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        json req_obj = json::parse(
            "{"
                "\"update_table\":\"table\""
            "}");

        std::cout << R->FRONTEND_processManagerGetTable(req_obj) << std::endl;
    }

    TEST(RestaurantFrontend_test, ENTER_RESTAURANT)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        json req_obj = json::parse(
            "{"
                "\"token\":\"ugyfurd48-7ft8yetfu7-t87l7k\""
            "}");

        EXPECT_EQ(R->FRONTEND_processCustomerRestaurantEntry(req_obj), "{\"status\":\"success\",\"player\":\"customer\",\"command\":\"add_token\",\"message\":\"successfully added customer token\"}");
    }

    TEST(RestaurantFrontend_test, EXIT_RESTAURANT)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        json req_obj = json::parse(
            "{"
                "\"token\":\"ugyfurd48-7ft8yetfu7-t87l7k\""
            "}");

        EXPECT_EQ(R->FRONTEND_processCustomerRestaurantEntry(req_obj), "{\"status\":\"success\",\"player\":\"customer\",\"command\":\"add_token\",\"message\":\"successfully added customer token\"}");
        EXPECT_EQ(R->FRONTEND_processCustomerRestaurantExit(req_obj), "{\"status\":\"success\",\"player\":\"customer\",\"command\":\"exit_restaurant\",\"message\":\"exited\"}");
    }

    TEST(RestaurantFrontend_test, REQUEST_SEAT_RESTAURANT)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        json req_obj = json::parse(
            "{"
                "\"token\":\"ugyfurd48-7ft8yetfu7-t87l7k\""
            "}");

        EXPECT_EQ(R->FRONTEND_processCustomerRestaurantEntry(req_obj), "{\"status\":\"success\",\"player\":\"customer\",\"command\":\"add_token\",\"message\":\"successfully added customer token\"}");
        EXPECT_EQ(R->FRONTEND_processCustomerRequestSeat(req_obj), "{\"status\":\"success\",\"player\":\"customer\",\"command\":\"seat_request\",\"message\":\"seated\"}");
    }

    TEST(RestaurantFrontend_test, REQUEST_UNSEAT_RESTAURANT)
    {
        std::shared_ptr<Restaurant> R = Restaurant::instance();

        ASSERT_NE(R, nullptr);

        json req_obj = json::parse(
            "{"
                "\"token\":\"ugyfurd48-7ft8yetfu7-t87l7k\""
            "}");

        EXPECT_EQ(R->FRONTEND_processCustomerRestaurantEntry(req_obj), "{\"status\":\"success\",\"player\":\"customer\",\"command\":\"add_token\",\"message\":\"successfully added customer token\"}");
        EXPECT_EQ(R->FRONTEND_processCustomerRequestSeat(req_obj), "{\"status\":\"success\",\"player\":\"customer\",\"command\":\"seat_request\",\"message\":\"seated\"}");
        EXPECT_EQ(R->FRONTEND_processCustomerRequestUnSeat(req_obj), "{\"status\":\"success\",\"player\":\"customer\",\"command\":\"unseat_request\",\"message\":\"unseated\"}");
    }
    
}