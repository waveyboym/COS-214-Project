/**
*@file tests.cpp
*@class none
*@author Michael
*@brief tests class, runs all tests for the project
*/

#include "backend/color/color.cpp"
#include "backend/States/EmotionalState.cpp"
#include "backend/Collectable/Collectable.cpp"

#include "backend/States/Angry.cpp"
#include "backend/States/Happy.cpp"
#include "backend/States/Neutral.cpp"
#include "backend/States/SlightlyAngry.cpp"
#include "backend/States/SlightlyHappy.cpp"

#include "backend/Table/Table.cpp"
#include "backend/Table/SingleTable.cpp"
#include "backend/Table/JoinedTable.cpp"

#include "backend/Bill/Bill.cpp"
#include "backend/Bill/MainBill.cpp"
#include "backend/Bill/SubBill.cpp"

#include "backend/People/People.cpp"
#include "backend/People/Customer.cpp"
#include "backend/People/Waiter.cpp"

#include "backend/Iterators/RestaurantIterator.cpp"
#include "backend/Iterators/BillIterator.cpp"
#include "backend/Iterators/JoinedTableIterator.cpp"
#include "backend/Iterators/SingleTableIterator.cpp"
#include "backend/Iterators/CustomerIterator.cpp"
#include "backend/Iterators/WaiterIterator.cpp"

#include "backend/MaitreD/MaitreD.cpp"
#include "backend/MaitreD/ConcreteMaitreD.cpp"

#include "tests/colorTest.cpp"
#include "tests/iteratorTest.cpp"
#include "tests/stateTest.cpp"
#include "tests/peopleTest.cpp"
#include "tests/tableTest.cpp"
#include "tests/billTest.cpp"
#include "tests/maitreDTest.cpp"

#include "tests/ordersTest.cpp"

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}