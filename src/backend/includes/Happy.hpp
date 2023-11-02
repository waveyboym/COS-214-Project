/**
*@file Happy.hpp Happy.cpp
*@class Happy
*@author Michael
*@implements EmotionalState
*@brief an Happy class which is a concrete state class of EmotionalState
*/
#ifndef HAPPY_HPP
#define HAPPY_HPP
#include "EmotionalState.hpp"

/** 
*@brief an Happy class which is a concrete state class of EmotionalState
*/
class Happy: public EmotionalState{
    public:
        /** 
        *@brief returns the happy emotional state as a string
        *@param none
        *@return std::string
        */
        std::string getEmotionalStateString();

        /** 
        *@brief returns the happy emotional state as an emotional state enum
        *@param none
        *@return EMOTIONAL_STATE
        */
        EMOTIONAL_STATE getEmotionalStateEnum();
};

#endif