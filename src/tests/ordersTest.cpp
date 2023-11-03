#include <gtest/gtest.h>

#include "../backend/includes/Order.hpp"

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


namespace OrderTests {
TEST(Order_Test, INIT_BasicOrder) 
{
    std::shared_ptr<Order> O = std::make_shared<AddBBQSauce>();
    ASSERT_NE(O, nullptr);
}

TEST(Order_Test, AddToList_True)
{
    std::shared_ptr<Order> O = std::make_shared<AddBBQSauce>();
    O->addedToList = true;
    EXPECT_EQ(O->addedToList, true);
}

TEST(Order_Test, EXECUTE_ORDER) 
{
    std::shared_ptr<Order> O = std::make_shared<AddBBQSauce>();
    EXPECT_EQ(O->executeOrder(nullptr), std::make_shared<BBQSauce>(nullptr));
}
}