/**
*@file SimulationInterface.hpp SimulationInterface.cpp
*@class SimulationInterface
*@author Michael
*@brief provides an interface for proxy object and real object to inherit from
*/

#ifndef SIMULATION_INTERFACE_HPP
#define SIMULATION_INTERFACE_HPP
#include <string>

/** 
*@brief provides an interface for proxy object and real object to inherit from
*/
class SimulationInterface{
    protected:
        /**
         * @brief processes the incoming request from the frontend and sends back a response
         * @param req incoming json request from the frontend
         * @return std::string
        */
        virtual std::string processFrontendRequest(std::string req) = 0;
};

#endif