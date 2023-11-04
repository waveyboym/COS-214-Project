#include <gtest/gtest.h>

// #include "../backend/includes/Order.hpp"
// #include "../backend/includes/Ingredient.hpp"


// class AddBBQSauce;
#include "../backend/includes/AddBBQSauce.hpp"
#include "../backend/includes/AddBeefBurgerPatty.hpp"
#include "../backend/includes/AddCaramelizedOnion.hpp"
#include "../backend/includes/AddCheese.hpp"
#include "../backend/includes/AddChickenBurgerPatty.hpp"
#include "../backend/includes/AddColdDrink.hpp"
#include "../backend/includes/AddFries.hpp"
#include "../backend/includes/AddJuice.hpp"
#include "../backend/includes/AddLettuce.hpp"
#include "../backend/includes/AddMayo.hpp"
#include "../backend/includes/AddNoBun.hpp"
#include "../backend/includes/AddNormalBun.hpp"
#include "../backend/includes/AddOnion.hpp"
#include "../backend/includes/AddPickles.hpp"
#include "../backend/includes/AddPineapple.hpp"
#include "../backend/includes/AddTomato.hpp"
#include "../backend/includes/AddVeggieBurgerPatty.hpp"
#include "../backend/includes/AddWater.hpp"
#include "../backend/includes/AddWholeWheatBun.hpp"
#include "../backend/includes/AddTomatoSauce.hpp"
#include "../backend/includes/AddSalad.hpp"


namespace orderTests{
TEST(Order_Test, INIT_BasicOrder) 
{
    std::shared_ptr<Order> O= std::make_shared<AddBeefBurgerPatty>();
    ASSERT_NE(O, nullptr);
}

TEST(Order_Test, AddToList_True)
{
    std::shared_ptr<Order> O = std::make_shared<AddBBQSauce>();
    O->addedToList = true;
    EXPECT_EQ(O->addedToList, true);
}

TEST(Order_Test, EXECUTE_ORDER_INGREDIENT) 
{
    std::shared_ptr<Order> O = std::make_shared<AddBBQSauce>();

    std::shared_ptr<Order> O_1 = std::make_shared<AddBBQSauce>();

    std::shared_ptr<Meal> B= std::make_shared<PlainBun>();
    std::shared_ptr<Meal> B1= std::make_shared<BBQSauce>(B);


    EXPECT_EQ(O->executeOrder(B)->getName(),B1->getName());
}

TEST(Order_Test, EXECUTE_ORDER_BUN) 
{
    std::shared_ptr<Order> O = std::make_shared<AddWholeWheatBun>();

    // std::shared_ptr<Order> O_1 = std::make_shared<AddBBQSauce>();

    std::shared_ptr<Meal> B= std::make_shared<PlainBun>();
    std::shared_ptr<Meal> B1= std::make_shared<WholewheatBun>();


    EXPECT_EQ(O->executeOrder(nullptr)->getName(),B1->getName());
}

// TEST(Order_Test, EXECUTE_ORDER_NOTBUN_NULLPTR) 
// {
//     std::shared_ptr<Order> O = std::make_shared<AddWholeWheatBun>();
//     std::shared_ptr<Meal> m = std::make_shared<BBQSauce>(nullptr);
// }

TEST(Order_Test, EXECUTE_ORDER_BUN_MORE)
{
    std::shared_ptr<Order> O = std::make_shared<AddWholeWheatBun>();
    std::shared_ptr<Order> O1 = std::make_shared<AddBeefBurgerPatty>();


    std::shared_ptr<Meal> B1 = std::make_shared<WholewheatBun>();
    std::shared_ptr<Meal> B2 = std::make_shared<BeefPatty>(B1);

    std::shared_ptr<Meal> C = O->executeOrder(nullptr);

    EXPECT_EQ(O1->executeOrder(C)->getItemizedList(),B2->getItemizedList());
}
}