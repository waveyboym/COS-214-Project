#include <gtest/gtest.h>

// #include "../backend/includes/Order.hpp"
// #include "../backend/includes/Ingredient.hpp"


// class AddBBQSauce;

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