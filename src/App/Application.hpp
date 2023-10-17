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

    private:
        /**
         * @brief this holds the app variable that creates a websocket and intercepts incoming requests
        */
        crow::SimpleApp app;

        /**
         * @brief processes the incoming request from the frontend and sends back a response
         * @param req incoming json request from the frontend
         * @return std::string
        */
        std::string processFrontendRequest(std::string req);
};

#endif