/**
*@file kitchenTest.cpp
*@namespace kitchenTest
*@class none
*@author Jaide
*@brief tests the Kitchen classes
*/

#include <gtest/gtest.h>

#include "../backend/includes/Kitchen.hpp"
#include "../backend/includes/ConcreteMaitreD.hpp"

#include "../backend/includes/AbstractChef.hpp"
#include "../backend/includes/BunChef.hpp"
#include "../backend/includes/Chef.hpp"
#include "../backend/includes/HeadChef.hpp"

//#include "../backend/includes/AddBBQSauce.hpp"
//#include "../backend/includes/AddNormalBun.hpp"

#include "../backend/Orders/AddBBQSauce.cpp"
#include "../backend/Orders/AddBeefBurgerPatty.cpp"
#include "../backend/Orders/AddCaramelizedOnion.cpp"
#include "../backend/Orders/AddCheese.cpp"
#include "../backend/Orders/AddChickenBurgerPatty.cpp"
#include "../backend/Orders/AddColdDrink.cpp"
#include "../backend/Orders/AddFries.cpp"
#include "../backend/Orders/AddJuice.cpp"
#include "../backend/Orders/AddLettuce.cpp"
#include "../backend/Orders/AddMayo.cpp"
#include "../backend/Orders/AddNoBun.cpp"
#include "../backend/Orders/AddNormalBun.cpp"
#include "../backend/Orders/AddNoBun.cpp"
#include "../backend/Orders/AddOnion.cpp"
#include "../backend/Orders/AddPickles.cpp"
#include "../backend/Orders/AddPineapple.cpp"
#include "../backend/Orders/AddTomato.cpp"
#include "../backend/Orders/AddVeggieBurgerPatty.cpp"
#include "../backend/Orders/AddWater.cpp"
#include "../backend/Orders/AddWholeWheatBun.cpp"


namespace chainTest{

    TEST(Chain_test, INIT_CHAIN)
    {
        std::shared_ptr<AbstractChef> chain = std::make_shared<BunChef>();
        (*chain).add(std::make_shared<Chef>());
        (*chain).add(std::make_shared<HeadChef>());

        ASSERT_NE(chain, nullptr);
    }

    TEST(Chain_test, CHAIN_MAKE_MEAL)
    {
        std::shared_ptr<AbstractChef> chain = std::make_shared<BunChef>();
        (*chain).add(std::make_shared<Chef>());
        (*chain).add(std::make_shared<HeadChef>());

        ASSERT_NE(chain, nullptr);
        std::shared_ptr<Customer> C = std::make_shared<Customer>("1");

        std::shared_ptr<Order> O1 = std::make_shared<AddWholeWheatBun>();
        std::shared_ptr<Order> O2 = std::make_shared<AddBBQSauce>();
        std::shared_ptr<Order> O3 = std::make_shared<AddBBQSauce>();
        
        std::vector<std::shared_ptr<Order>> order_list = {O1, O2, O3};

        std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>> output = (*chain).makeOrder(order_list, C,nullptr);
        ASSERT_NE(output.first, nullptr);
        ASSERT_NE(output.second, nullptr);
        EXPECT_EQ(output.first.get()->getItemizedList(), "Wholewheat Bun  R15.13\nBarbecue Sauce  R2.14\nBarbecue Sauce  R2.14\n\nTotal: R19.41");
        EXPECT_EQ(output.second, C);

    }

    TEST(Chain_test, CHAIN_MAKE_TWO_DIFFERENT_MEAL)
    {
        std::shared_ptr<AbstractChef> chain = std::make_shared<BunChef>();
        (*chain).add(std::make_shared<Chef>());
        (*chain).add(std::make_shared<HeadChef>());

        ASSERT_NE(chain, nullptr);
        std::shared_ptr<Customer> C = std::make_shared<Customer>("1");

        std::shared_ptr<Order> O1 = std::make_shared<AddWholeWheatBun>();
        std::shared_ptr<Order> O2 = std::make_shared<AddBBQSauce>();
        std::shared_ptr<Order> O3 = std::make_shared<AddBBQSauce>();

        std::shared_ptr<Order> O4 = std::make_shared<AddNormalBun>();
        std::shared_ptr<Order> O5 = std::make_shared<AddPineApple>();
        std::shared_ptr<Order> O6 = std::make_shared<AddCheese>();
        
        std::vector<std::shared_ptr<Order>> order_list = {O1, O2, O3};
         std::vector<std::shared_ptr<Order>> order_list2 = {O4, O5, O6};


        std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>> output = (*chain).makeOrder(order_list, C,nullptr);
        std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>> output2 = (*chain).makeOrder(order_list2, C,nullptr);
        
        ASSERT_NE(output.first, nullptr);
        ASSERT_NE(output.second, nullptr);
        EXPECT_EQ(output.first.get()->getItemizedList(), "Wholewheat Bun  R15.13\nBarbecue Sauce  R2.14\nBarbecue Sauce  R2.14\n\nTotal: R19.41");
        EXPECT_EQ(output.second, C);

        ASSERT_NE(output2.first, nullptr);
        ASSERT_NE(output2.second, nullptr);
        EXPECT_EQ(output2.first.get()->getItemizedList(), "Plain bun  R10.00\nPineapple  R12.99\nCheese  R4.38\n\nTotal: R27.37");
        EXPECT_EQ(output2.second, C);
    }

    TEST(Chain_test, CHAIN_MAKE_TWO_SAME_MEAL)
    {
        std::shared_ptr<AbstractChef> chain = std::make_shared<BunChef>();
        (*chain).add(std::make_shared<Chef>());
        (*chain).add(std::make_shared<HeadChef>());

        ASSERT_NE(chain, nullptr);
        std::shared_ptr<Customer> C = std::make_shared<Customer>("1");

        std::shared_ptr<Order> O1 = std::make_shared<AddWholeWheatBun>();
        std::shared_ptr<Order> O2 = std::make_shared<AddBBQSauce>();
        std::shared_ptr<Order> O3 = std::make_shared<AddBBQSauce>();

        std::shared_ptr<Order> O4 = std::make_shared<AddWholeWheatBun>();
        std::shared_ptr<Order> O5 = std::make_shared<AddBBQSauce>();
        std::shared_ptr<Order> O6 = std::make_shared<AddBBQSauce>();
        
        std::vector<std::shared_ptr<Order>> order_list = {O1, O2, O3};
         std::vector<std::shared_ptr<Order>> order_list2 = {O4, O5, O6};


        std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>> output = (*chain).makeOrder(order_list, C,nullptr);
        std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>> output2 = (*chain).makeOrder(order_list2, C,nullptr);
        
        ASSERT_NE(output.first, nullptr);
        ASSERT_NE(output.second, nullptr);
        EXPECT_EQ(output.first.get()->getItemizedList(), "Wholewheat Bun  R15.13\nBarbecue Sauce  R2.14\nBarbecue Sauce  R2.14\n\nTotal: R19.41");
        EXPECT_EQ(output.second, C);

        ASSERT_NE(output2.first, nullptr);
        ASSERT_NE(output2.second, nullptr);
        EXPECT_EQ(output2.first.get()->getItemizedList(), "Wholewheat Bun  R15.13\nBarbecue Sauce  R2.14\nBarbecue Sauce  R2.14\n\nTotal: R19.41");
        EXPECT_EQ(output2.second, C);
    }

}


namespace  kitchenTest{

    TEST(Kitchen_test, INIT_KITCHEN)
    {
        std::vector<std::shared_ptr<Waiter>> W = {nullptr};
        std::shared_ptr<Kitchen> K = std::make_shared<Kitchen>(W);
        ASSERT_NE(K, nullptr);
    }

   TEST(Kitchen_test, INIT_KITCHEN_WITH_WAITERS){
        std::shared_ptr<Waiter> W1 = std::make_shared<Waiter>("0000");
        std::shared_ptr<Waiter> W2 = std::make_shared<Waiter>("0001");
        std::shared_ptr<Waiter> W3 = std::make_shared<Waiter>("0002");

        std::vector<std::shared_ptr<Waiter>> AW = {W1, W2, W3};

        std::shared_ptr<Kitchen> K = std::make_shared<Kitchen>(AW);

        ASSERT_NE(K, nullptr);
    }

    TEST(SingleTable_test, KITCHEN_CREATES_MEAL)
    {
        
        std::shared_ptr<ConcreteMaitreD> CMD = std::make_shared<ConcreteMaitreD>();

        std::shared_ptr<Customer> C = std::make_shared<Customer>("1");

        std::list<std::shared_ptr<SingleTable>> single_tables;
        std::list<std::shared_ptr<JoinedTable>> joined_tables;
        
        single_tables.push_back(std::make_shared<SingleTable>(0));
        joined_tables.push_back(std::make_shared<JoinedTable>(1));
        
        std::vector<std::shared_ptr<Waiter>> waiters;
        std::shared_ptr<Waiter> W1 = std::make_shared<Waiter>("0000");
        waiters.push_back(W1);

        CMD->seatCustomer(single_tables, joined_tables, C);
        CMD->assignWaiterToTable(single_tables, joined_tables, W1);

        std::shared_ptr<Kitchen> K = std::make_shared<Kitchen>(waiters);

        ASSERT_NE(K, nullptr);

        std::shared_ptr<Order> O1 = std::make_shared<AddWholeWheatBun>();
        std::shared_ptr<Order> O2 = std::make_shared<AddBBQSauce>();
        std::shared_ptr<Order> O3 = std::make_shared<AddBBQSauce>();
        
        std::vector<std::shared_ptr<Order>> order_list = {O1, O2, O3};

        K.get()->createMeal(order_list, C);
        K.get()->getCompletedMeals();
        EXPECT_EQ(K.get()->getCompletedMeals().at(0).first.get()->getItemizedList(), "Wholewheat Bun  R15.13\nBarbecue Sauce  R2.14\nBarbecue Sauce  R2.14\n\nTotal: R19.41");
    }

    TEST(SingleTable_test, KITCHEN_CREATES_MULTIPLE_MEAL)
    {
        
        std::shared_ptr<ConcreteMaitreD> CMD = std::make_shared<ConcreteMaitreD>();

        std::shared_ptr<Customer> C = std::make_shared<Customer>("1");

        std::list<std::shared_ptr<SingleTable>> single_tables;
        std::list<std::shared_ptr<JoinedTable>> joined_tables;
        
        single_tables.push_back(std::make_shared<SingleTable>(0));
        joined_tables.push_back(std::make_shared<JoinedTable>(1));
        
        std::vector<std::shared_ptr<Waiter>> waiters;
        std::shared_ptr<Waiter> W1 = std::make_shared<Waiter>("0000");
        waiters.push_back(W1);

        CMD->seatCustomer(single_tables, joined_tables, C);
        CMD->assignWaiterToTable(single_tables, joined_tables, W1);

        std::shared_ptr<Kitchen> K = std::make_shared<Kitchen>(waiters);

        ASSERT_NE(K, nullptr);

        std::shared_ptr<Order> O1 = std::make_shared<AddWholeWheatBun>();
        std::shared_ptr<Order> O2 = std::make_shared<AddBBQSauce>();
        std::shared_ptr<Order> O3 = std::make_shared<AddBBQSauce>();
        
        std::vector<std::shared_ptr<Order>> order_list = {O1, O2, O3};

        std::shared_ptr<Order> O4 = std::make_shared<AddNormalBun>();
        std::shared_ptr<Order> O5 = std::make_shared<AddOnion>();
        std::shared_ptr<Order> O6 = std::make_shared<AddBeefBurgerPatty>();
        
        std::vector<std::shared_ptr<Order>> order_list2 = {O4, O5, O6};

        K.get()->createMeal(order_list, C);
        K.get()->createMeal(order_list2, C);
        std::vector<std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>>> results = K.get()->getCompletedMeals();
        EXPECT_EQ(results.at(0).first.get()->getItemizedList(), "Wholewheat Bun  R15.13\nBarbecue Sauce  R2.14\nBarbecue Sauce  R2.14\n\nTotal: R19.41");
        EXPECT_EQ(results.at(1).first.get()->getItemizedList(), "Plain bun  R10.00\nFresh Red Onion  R3.12\nBeef Patty  R10.00\n\nTotal: R23.12");
    
    }

    TEST(SingleTable_test, KITCHEN_NOTIFIES_WAITERS)
    {
        
        std::shared_ptr<ConcreteMaitreD> CMD = std::make_shared<ConcreteMaitreD>();

        ASSERT_NE(CMD, nullptr);

        std::shared_ptr<Customer> A = std::make_shared<Customer>("1");
        std::shared_ptr<Customer> B = std::make_shared<Customer>("2");
        std::shared_ptr<Waiter> C = std::make_shared<Waiter>("0000");

        std::list<std::shared_ptr<SingleTable>> single_tables;
        std::list<std::shared_ptr<JoinedTable>> joined_tables;
        std::vector<std::shared_ptr<Waiter>> waiters;
        waiters.push_back(C);

        single_tables.push_back(std::make_shared<SingleTable>(0));
        joined_tables.push_back(std::make_shared<JoinedTable>(1));

        EXPECT_EQ(CMD->seatCustomer(single_tables, joined_tables, A), true);
        EXPECT_EQ(CMD->assignWaiterToTable(single_tables, joined_tables, waiters.at(0)), true);
        EXPECT_EQ(C->getAssignedTableID(), 0);

        std::shared_ptr<SingleTableIterator> s_t_i = std::make_shared<SingleTableIterator>(single_tables);
        std::shared_ptr<Table> table = std::dynamic_pointer_cast<Table>(s_t_i->currentItem());
        EXPECT_EQ(table->getAssignedWaiterID(), "0000");

        std::shared_ptr<Kitchen> K = std::make_shared<Kitchen>(waiters);
        std::vector<std::shared_ptr<Order>> order_list = {std::make_shared<AddWholeWheatBun>(), std::make_shared<AddBBQSauce>(), std::make_shared<AddBBQSauce>()};

        K.get()->createMeal(order_list, A);
        std::vector<std::pair<std::shared_ptr<Meal>, std::shared_ptr<Customer>>> results = K.get()->getCompletedMeals();
 
        K.get()->notifyWaiters();

    }
    

}