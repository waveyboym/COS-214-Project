/**
*@file color.hpp color.cpp
*@class color
*@author Michael
*@brief a color class
*/
#ifndef color_hpp
#define color_hpp
#include <string>

/** 
*@brief color namespace
*/
namespace color{
    /** 
    *@brief different colour codes
    */
    enum ColorCode {
        BLACK    = 30,   
        RED      = 31,
        GREEN    = 32,
        YELLOW   = 33,     
        BLUE     = 34,     
        MAGENTA  = 35,     
        CYAN     = 36,     
        WHITE    = 37,
        DEFAULT  = 39
    };

    /** 
    *@brief formatting a colour for the command line
    */
    class format_colour {
    public:
        /** 
        *@brief formatting a colour for the command line
        *@param cc color code to use
        *@return std::string
        */
        static std::string make_colour(ColorCode cc);
    };
};

#endif