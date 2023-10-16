/**
*@file Application.hpp Application.cpp
*@class Application
*@author Michael
*@brief Application class that runs the main application
*/

#include "../backend/includes/crow_all.h"
#ifndef APPLICATION_HPP
#define APPLICATION_HPP

/**
 * @brief Application class that runs the main application
*/
class Application{
    private:
        /**
         * @brief example
        */
        const int example = 0;

    public:
        /**
         * @brief initialises the application class
         * @param none
         * @return void
        */
        void initApp();
        /**
         * @brief runs the application class until the user quits the program
         * @param none
         * @return void
        */
        void runApp();
};

#endif