/**
*@file Application.hpp Application.cpp
*@class Application
*@author Michael
*@brief Application class that runs the main application
*/

#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include "../backend/includes/crow_all.h" //don't try to sort out this squiggly, if it's red, leave it!
#include "../backend/includes/json.hpp"
#include "../backend/includes/uuid.h"
#include "../backend/includes/color.hpp"
#include <map>
#include <mutex>
#include <chrono>
#include <thread>
#include <list>

using json = nlohmann::json;

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

        /**
         * @brief progresses the application forward on a separate thread until execution is briefly paused or the app is quit
         * @param none
         * @return void
        */
        void progressForward();

    private:
        /**
         * @brief this holds the app variable that creates a websocket and intercepts incoming requests
        */
        crow::SimpleApp app;

        /**
         * @brief this holds all of the connected/subscribed clients that way if there is an update on the backend, we can send updated data to the client in json form.
         * @note Note that when a client closes their connection, they become unsubscribed and will no longer receive any messages from the backend.
        */
        std::map<std::string, crow::websocket::connection*> connected_clients;

        /**
         * @brief thread locker.
         * @note Only use this if you are certain that you know what you are doing
        */
        std::mutex mtx;

        /**
         * @brief this has the ability to pause app execution when changed to true and unpause when changed to false
        */
        volatile bool pause_app_execution;

        /**
         * @brief this has the the ability to quit the app when changed to true and does not quit the app as long as it is false
        */
        volatile bool quit_app;

        /**
         * @brief this stores the uuid of connected customers
        */
        std::list<std::string> connected_customers;

        /**
         * @brief this stores the uuid of connected managers
        */
        std::list<std::string> connected_managers;

        /**
         * @brief processes the incoming request from the frontend and sends back a response
         * @param req incoming json request from the frontend
         * @return std::string
        */
        std::string processFrontendRequest(std::string req);

        /**
         * @brief processes the incoming request from the frontend customer and sends back a response
         * @param req incoming json request from the frontend
         * @return std::string
        */
        std::string processCustomerRequest(json req_obj);

        /**
         * @brief processes the incoming request from the frontend manager and sends back a response
         * @param req incoming json request from the frontend
         * @return std::string
        */
        std::string processManagerRequest(json req_obj);

        /**
         * @brief checks if the token exists in the passed in linked list. returns true on success and false on failure
         * @param linked_list list to find token in
         * @param token token to find in list
         * @return bool
        */
        bool existingToken(std::list<std::string> linked_list, std::string token);

        /**
         * @brief generates unique uid
         * @param none
         * @return std::string
        */
        std::string generateUUID();

        /**
         * @brief inserts this client into the map of clients and returns the uuid of that client as a string
         * @param client the client connection to insert
         * @return std::string
        */
        std::string insertClient(crow::websocket::connection* client);

        /**
         * @brief removes this client from the map of clients and returns true on success else false
         * @param client the client connection to remove
         * @return bool
        */
        bool removeClient(crow::websocket::connection* client);
};

#endif