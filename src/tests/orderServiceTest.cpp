/**
*@file peopleTest.cpp
*@namespace peopleTest
*@class none
*@author Jaden
*@brief tests the waiter and customer class
*/

#include <gtest/gtest.h>
#include "../backend/includes/Waiter.hpp"
#include "../backend/includes/Customer.hpp"

#include "../backend/includes/Meal.hpp"
#include "../backend/includes/Ingredient.hpp"
#include "../backend/includes/ConcreteIngredients.hpp"
#include "../backend/includes/Bun.hpp"
#include "../backend/includes/ConcreteBuns.hpp"

#include "../backend/includes/Kitchen.hpp"
#include "../backend/includes/ConcreteMaitreD.hpp"

#include "../backend/includes/AbstractChef.hpp"
#include "../backend/includes/BunChef.hpp"
#include "../backend/includes/Chef.hpp"
#include "../backend/includes/HeadChef.hpp"

namespace orderServiceTest{
    TEST(Order_Service_Test, CUSTOMER_TO_WAITER_TO_KITCHEN_TO_CUSTOMER){
        std::shared_ptr<Customer> C = std::make_shared<Customer>("012");
        std::shared_ptr<Customer> C1 = std::make_shared<Customer>();
        std::shared_ptr<Customer> C2 = std::make_shared<Customer>();

        std::shared_ptr<Waiter> W1 = std::make_shared<Waiter>("0000");
        std::shared_ptr<Waiter> W2 = std::make_shared<Waiter>("0001");
        std::shared_ptr<Waiter> W3 = std::make_shared<Waiter>("0002");

        std::vector<std::shared_ptr<Waiter>> AW = {W1, W2, W3};

        std::shared_ptr<Kitchen> K = std::make_shared<Kitchen>(AW);

        ASSERT_NE(K, nullptr);
        ASSERT_NE(W1, nullptr);
        ASSERT_NE(W2, nullptr);
        ASSERT_NE(W3, nullptr);
        ASSERT_NE(C, nullptr);

        C->setOrder();
        C1->setOrder();
        C2->setOrder();

        W1->takeOrder(C);
        W2->takeOrder(C1);
        W3->takeOrder(C2);

        K->createMeal(W3->sendOrder().first, C);
        K->createMeal(W2->sendOrder().first, C1);
        // K->createMeal(W3->getOrder(), C2);



        EXPECT_EQ(K->getCompletedMeals().begin()->first->getItemizedList(), "No Bun  R0.00\nChicken Patty  R10.99\nTomato  R2.57\nChicken Patty  R10.99\nJuice  R14.36\nCheese  R4.38\nTomato  R2.57\nFresh Red Onion  R3.12\nChicken Patty  R8.52\nMayonnaise  R2.18\n\nTotal: R59.68");
    }
}