/**
*@file mealTest.cpp
*@namespace mealTest
*@class none
*@author Jaden
*@brief tests the meal class
*/

#include <gtest/gtest.h>
#include <algorithm>
#include "../backend/includes/Meal.hpp"
#include "../backend/includes/Ingredient.hpp"
#include "../backend/includes/ConcreteIngredients.hpp"
#include "../backend/includes/Bun.hpp"
#include "../backend/includes/ConcreteBuns.hpp"

namespace mealTest{
    TEST(Meal_test, INIT_MEAL_JUST_BUNS){
        std::shared_ptr<Meal> NB = std::make_shared<NoBun>();
        std::shared_ptr<Meal> PB = std::make_shared<PlainBun>();
        std::shared_ptr<Meal> WB = std::make_shared<WholewheatBun>();

        ASSERT_NE(NB, nullptr);
        ASSERT_NE(PB, nullptr);
        ASSERT_NE(WB, nullptr);
    }

    TEST(Meal_test, INIT_MEAL_WITH_SINGLE_PATTY){
        std::shared_ptr<Meal> BP = std::make_shared<NoBun>();
        BP = std::make_shared<BeefPatty>(BP);

        std::shared_ptr<Meal> CP = std::make_shared<NoBun>();
        BP = std::make_shared<ChickenPatty>(CP);

        std::shared_ptr<Meal> VP = std::make_shared<NoBun>();
        BP = std::make_shared<VeggiePatty>(VP);        

        ASSERT_NE(BP, nullptr);
        ASSERT_NE(CP, nullptr);
        ASSERT_NE(VP, nullptr);
    }

    TEST(Meal_test, INIT_MEAL_WITH_SINGLE_TOPPING){
        std::shared_ptr<Meal> P = std::make_shared<NoBun>();
        P = std::make_shared<Pickles>(P);

        std::shared_ptr<Meal> O = std::make_shared<NoBun>();
        O = std::make_shared<Onion>(O);

        std::shared_ptr<Meal> CO = std::make_shared<NoBun>();
        CO = std::make_shared<CaramelizedOnion>(CO);

        std::shared_ptr<Meal> T = std::make_shared<NoBun>();
        T = std::make_shared<Pickles>(T);

        std::shared_ptr<Meal> C = std::make_shared<NoBun>();
        C = std::make_shared<Cheese>(C);

        std::shared_ptr<Meal> L = std::make_shared<NoBun>();
        L = std::make_shared<Lettuce>(L);

        std::shared_ptr<Meal> PA = std::make_shared<NoBun>();
        PA = std::make_shared<Pineapple>(PA);

        ASSERT_NE(P, nullptr);
        ASSERT_NE(O, nullptr);
        ASSERT_NE(CO, nullptr);
        ASSERT_NE(T, nullptr);
        ASSERT_NE(C, nullptr);
        ASSERT_NE(L, nullptr);
        ASSERT_NE(PA, nullptr);
    }

    TEST(Meal_test, INIT_MEAL_WITH_SINGLE_SIDE_DISH){
        std::shared_ptr<Meal> F = std::make_shared<NoBun>();
        F = std::make_shared<Fries>(F);

        std::shared_ptr<Meal> S = std::make_shared<NoBun>();
        S = std::make_shared<Salad>(S);

        ASSERT_NE(F, nullptr);
        ASSERT_NE(S, nullptr);
    }

    TEST(Meal_test, INIT_MEAL_WITH_SINGLE_SAUCE){
        std::shared_ptr<Meal> TS = std::make_shared<NoBun>();
        TS = std::make_shared<TomatoSauce>(TS);

        std::shared_ptr<Meal> BS = std::make_shared<NoBun>();
        BS = std::make_shared<BBQSauce>(BS);

        std::shared_ptr<Meal> M = std::make_shared<NoBun>();
        M = std::make_shared<Mayo>(M);

        ASSERT_NE(TS, nullptr);
        ASSERT_NE(BS, nullptr);
        ASSERT_NE(M, nullptr);
    }

    TEST(Meal_test, INIT_MEAL_WITH_SINGLE_DRINK){
        std::shared_ptr<Meal> W = std::make_shared<NoBun>();
        W = std::make_shared<Water>(W);

        std::shared_ptr<Meal> CD = std::make_shared<NoBun>();
        CD = std::make_shared<ColdDrink>(CD);

        std::shared_ptr<Meal> J = std::make_shared<NoBun>();
        J = std::make_shared<Juice>(J);

        ASSERT_NE(W, nullptr);
        ASSERT_NE(CD, nullptr);
        ASSERT_NE(J, nullptr);
    }

    TEST(Meal_test, INIT_MEAL_WITH_MULTIPLE_INGREDIENTS){
        std::shared_ptr<Meal> M = std::make_shared<PlainBun>();
        M = std::make_shared<Water>(M);
        M = std::make_shared<Lettuce>(M);
        M = std::make_shared<BeefPatty>(M);
        M = std::make_shared<Cheese>(M);
        M = std::make_shared<Fries>(M);

        ASSERT_NE(M, nullptr);
    }

    TEST(Meal_test, INIT_MEAL_WITH_ALL_INGREDIENTS){
        std::shared_ptr<Meal> M = std::make_shared<PlainBun>();

        M = std::make_shared<BeefPatty>(M);
        M = std::make_shared<ChickenPatty>(M);
        M = std::make_shared<VeggiePatty>(M);

        M = std::make_shared<Pickles>(M);
        M = std::make_shared<Onion>(M);
        M = std::make_shared<CaramelizedOnion>(M);
        M = std::make_shared<Tomato>(M);
        M = std::make_shared<Cheese>(M);
        M = std::make_shared<Lettuce>(M);
        M = std::make_shared<Pineapple>(M);

        M = std::make_shared<Fries>(M);
        M = std::make_shared<Salad>(M);

        M = std::make_shared<TomatoSauce>(M);
        M = std::make_shared<BBQSauce>(M);
        M = std::make_shared<Mayo>(M);

        M = std::make_shared<Water>(M);
        M = std::make_shared<ColdDrink>(M);
        M = std::make_shared<Juice>(M);

        ASSERT_NE(M, nullptr);
    }

    TEST(Meal_test, GET_TOTAL_COST_JUST_BUN){
        std::shared_ptr<Meal> NB = std::make_shared<NoBun>();
        std::shared_ptr<Meal> PB = std::make_shared<PlainBun>();
        std::shared_ptr<Meal> WB = std::make_shared<WholewheatBun>();

        ASSERT_NE(NB, nullptr);
        ASSERT_NE(PB, nullptr);
        ASSERT_NE(WB, nullptr);

        EXPECT_EQ(NB->getTotalCost(), 0);
        EXPECT_EQ(PB->getTotalCost(), 10);
        EXPECT_EQ(WB->getTotalCost(), 15.13);
    }

    TEST(Meal_test, GET_TOTAL_COST_WITH_INGREDIENTS){
        std::shared_ptr<Meal> PB = std::make_shared<PlainBun>();
        PB = std::make_shared<BeefPatty>(PB);
        PB = std::make_shared<Fries>(PB);
        PB = std::make_shared<Tomato>(PB);
        

        ASSERT_NE(PB, nullptr);
        EXPECT_EQ(PB->getTotalCost(), 32.82);
    }

    //These tests make calls to functions that don't exist
    
    //TEST(Meal_test, SET_TOTAL_COST_JUST_BUN){
    //    std::shared_ptr<Meal> PB = std::make_shared<PlainBun>();
    //    ASSERT_NE(PB, nullptr);
//
    //    PB->setTotalCost(12);
//
    //    EXPECT_EQ(PB->getTotalCost(), 22);
    //}
//
    //TEST(Meal_test, SET_TOTAL_COST_WITH_INGREDIENTS){
    //    std::shared_ptr<Meal> PB = std::make_shared<PlainBun>();
    //    PB = std::make_shared<BeefPatty>(PB);
    //    PB = std::make_shared<Fries>(PB);
    //    PB = std::make_shared<Tomato>(PB);
    //    ASSERT_NE(PB, nullptr);
//
    //    PB->setTotalCost(12);
//
    //    EXPECT_EQ(PB->getTotalCost(), 44.82);
    //}

    TEST(Meal_test, GET_ITEMISED_LIST_JUST_BUN){
        std::shared_ptr<Meal> PB = std::make_shared<PlainBun>();
        ASSERT_NE(PB, nullptr);
        EXPECT_EQ(PB->getItemizedList(), "Plain bun  R10.00\n\nTotal: R10.00");
    }

    TEST(Meal_test, GET_ITEMISED_LIST_WITH_INGREDIENTS){
        std::shared_ptr<Meal> PB = std::make_shared<PlainBun>();
        PB = std::make_shared<BeefPatty>(PB);
        PB = std::make_shared<Fries>(PB);
        PB = std::make_shared<Tomato>(PB);
        ASSERT_NE(PB, nullptr);
        EXPECT_EQ(PB->getItemizedList(), "Plain bun  R10.00\nBeef Patty  R10.00\nFries  R10.25\nTomato  R2.57\n\nTotal: R32.82");
    }
}