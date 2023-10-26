/**
*@file tests.cpp
*@class none
*@author Michael
*@brief tests class, runs all tests for the project
*/

#include "backend/color/color.cpp"
#include "backend/States/EmotionalState.cpp"
#include "backend/States/Angry.cpp"
#include "backend/States/Happy.cpp"
#include "backend/States/Neutral.cpp"
#include "backend/Collectable/Collectable.cpp"
#include "backend/Table/Table.cpp"
#include "backend/Bill/Bill.cpp"
#include "backend/People/People.cpp"
#include "backend/People/Customer.cpp"
#include "backend/Iterators/RestaurantIterator.cpp"
#include "backend/Iterators/BillIterator.cpp"
#include "backend/Iterators/TableIterator.cpp"
#include "backend/Iterators/CustomerIterator.cpp"

#include "tests/colorTest.cpp"
#include "tests/iteratorTest.cpp"
#include "tests/stateTest.cpp"

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}