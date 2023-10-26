/**
*@file EmotionalState.hpp EmotionalState.cpp
*@class EmotionalState
*@author Michael
*@brief an EmotionalState class which all classes that make use of emotional state must inherit from
*/
#ifndef EMOTIONAL_STATE_HPP
#define EMOTIONAL_STATE_HPP
#include <string>

enum EMOTIONAL_STATE{
    NEUTRAL,
    ANGRY,
    HAPPY
};

/** 
*@brief an EmotionalState class which all classes that make use of emotional state must inherit from
*/
class EmotionalState{
    public:
        /** 
        *@brief returns the current emotional state as a string
        *@param none
        *@return std::string
        */
        virtual std::string getEmotionalStateString() = 0;

        /** 
        *@brief returns the current emotional state as an emotional state enum
        *@param none
        *@return EMOTIONAL_STATE
        */
        virtual EMOTIONAL_STATE getEmotionalStateEnum() = 0;
};

#endif