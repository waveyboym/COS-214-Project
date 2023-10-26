/**
*@file colorTest.cpp
*@namespace colorTest
*@class none
*@author Michael
*@brief tests the color class
*/

#include <gtest/gtest.h>
#include "../backend/includes/color.hpp"

namespace colorTest{
    TEST(color_test, COLOR_BLACK)
    {
        GTEST_ASSERT_EQ(color::format_colour::make_colour(color::BLACK), "\033[30m");
    }

    TEST(color_test, COLOR_RED)
    {
        GTEST_ASSERT_EQ(color::format_colour::make_colour(color::RED), "\033[31m");
    }

    TEST(color_test, COLOR_GREEN)
    {
        GTEST_ASSERT_EQ(color::format_colour::make_colour(color::GREEN), "\033[32m");
    }

    TEST(color_test, COLOR_YELLOW)
    {
        GTEST_ASSERT_EQ(color::format_colour::make_colour(color::YELLOW), "\033[33m");
    }

    TEST(color_test, COLOR_BLUE)
    {
        GTEST_ASSERT_EQ(color::format_colour::make_colour(color::BLUE), "\033[34m");
    }

    TEST(color_test, COLOR_MAGENT)
    {
        GTEST_ASSERT_EQ(color::format_colour::make_colour(color::MAGENTA), "\033[35m");
    }

    TEST(color_test, COLOR_CYAN)
    {
        GTEST_ASSERT_EQ(color::format_colour::make_colour(color::CYAN), "\033[36m");
    }

    TEST(color_test, COLOR_WHITE)
    {
        GTEST_ASSERT_EQ(color::format_colour::make_colour(color::WHITE), "\033[37m");
    }

    TEST(color_test, COLOR_DEFAULT)
    {
        GTEST_ASSERT_EQ(color::format_colour::make_colour(color::DEFAULT), "\033[39m");
    }
}

