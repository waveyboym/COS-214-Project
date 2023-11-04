#include <gtest/gtest.h>

// #include "../backend/includes/Order.hpp"
// #include "../backend/includes/Ingredient.hpp"


// class AddBBQSauce;
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
#include "../backend/Orders/AddOnion.cpp"
#include "../backend/Orders/AddPickles.cpp"
#include "../backend/Orders/AddPineapple.cpp"
#include "../backend/Orders/AddTomato.cpp"
#include "../backend/Orders/AddVeggieBurgerPatty.cpp"
#include "../backend/Orders/AddWater.cpp"
#include "../backend/Orders/AddWholeWheatBun.cpp"


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
}