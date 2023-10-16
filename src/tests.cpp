#include <gtest/gtest.h>
#include "backend/container.cpp"

TEST(SIZE, container)
{
    container <int> Cont;
    GTEST_ASSERT_EQ(Cont.size_of_container(), 0);
}

TEST(CAPACITY, container)
{
    container <int> Cont;
    GTEST_ASSERT_EQ(Cont.capacity_of_container(), 4);
}

TEST(EMPTY, container)
{
    container <int> Cont;
    GTEST_ASSERT_EQ(Cont.empty(), true);
}

TEST(PUSHBACK, container)
{
    container <int> Cont;
    Cont.push_back(5);
    Cont.push_back(10);
    Cont.push_back(23);
    Cont.push_back(25);
    GTEST_ASSERT_EQ(Cont.empty(), false);
    GTEST_ASSERT_EQ(Cont.size_of_container(), 4);
    GTEST_ASSERT_EQ(Cont.get(0), 5);
    GTEST_ASSERT_EQ(Cont[2], 23);
}

TEST(PUSHFRONT, container)
{
    container <int> Cont;
    Cont.push_front(5);
    Cont.push_front(10);
    Cont.push_front(23);
    Cont.push_front(25);
    GTEST_ASSERT_EQ(Cont.empty(), false);
    GTEST_ASSERT_EQ(Cont.size_of_container(), 4);
    GTEST_ASSERT_EQ(Cont.get(0), 25);
    GTEST_ASSERT_EQ(Cont[2], 10);
}

TEST(PUSHBACK_PUSHFRONT_RESIZE, container)
{
    container <int> Cont;
    Cont.push_front(5);
    Cont.push_front(10);
    Cont.push_front(23);
    Cont.push_front(25);
    Cont.push_back(15);
    Cont.push_back(100);

    GTEST_ASSERT_EQ(Cont.empty(), false);
    GTEST_ASSERT_EQ(Cont.size_of_container(), 6);
    GTEST_ASSERT_EQ(Cont.capacity_of_container(), 8);
    GTEST_ASSERT_EQ(Cont.get(0), 25);
    GTEST_ASSERT_EQ(Cont[5], 100);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}