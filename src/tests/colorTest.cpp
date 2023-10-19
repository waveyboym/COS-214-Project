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
    TEST(COLOR_BLACK, color)
    {
        GTEST_ASSERT_EQ(color::format_colour::make_colour(color::BLACK), "\033[" + std::to_string(color::BLACK) + "m");
    }

    TEST(COLOR_RED, color)
    {
        GTEST_ASSERT_EQ(color::format_colour::make_colour(color::RED), "\033[" + std::to_string(color::RED) + "m");
    }

    TEST(COLOR_GREEN, color)
    {
        GTEST_ASSERT_EQ(color::format_colour::make_colour(color::GREEN), "\033[" + std::to_string(color::GREEN) + "m");
    }

    TEST(COLOR_YELLOW, color)
    {
        GTEST_ASSERT_EQ(color::format_colour::make_colour(color::YELLOW), "\033[" + std::to_string(color::YELLOW) + "m");
    }

    TEST(COLOR_BLUE, color)
    {
        GTEST_ASSERT_EQ(color::format_colour::make_colour(color::BLUE), "\033[" + std::to_string(color::BLUE) + "m");
    }

    TEST(COLOR_MAGENTA, color)
    {
        GTEST_ASSERT_EQ(color::format_colour::make_colour(color::MAGENTA), "\033[" + std::to_string(color::MAGENTA) + "m");
    }

    TEST(COLOR_CYAN, color)
    {
        GTEST_ASSERT_EQ(color::format_colour::make_colour(color::CYAN), "\033[" + std::to_string(color::CYAN) + "m");
    }

    TEST(COLOR_WHITE, color)
    {
        GTEST_ASSERT_EQ(color::format_colour::make_colour(color::WHITE), "\033[" + std::to_string(color::WHITE) + "m");
    }

    TEST(COLOR_DEFAULT, color)
    {
        GTEST_ASSERT_EQ(color::format_colour::make_colour(color::DEFAULT), "\033[" + std::to_string(color::DEFAULT) + "m");
    }
}

