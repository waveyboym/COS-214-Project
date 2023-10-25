/**
*@file tests.cpp
*@class none
*@author Michael
*@brief tests class, runs all tests for the project
*/

#include "backend/color/color.cpp"
#include "tests/colorTest.cpp"
#include "backend/Collectable/Collectable.cpp"
#include "backend/Table/Table.cpp"
#include "backend/Bill/Bill.cpp"
#include "backend/People/People.cpp"
#include "backend/Iterators/RestaurantIterator.cpp"
#include "backend/iterators/BillIterator.cpp"
#include "backend/iterators/TableIterator.cpp"
#include "backend/iterators/PeopleIterator.cpp"
#include "tests/iteratorTest.cpp"

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}