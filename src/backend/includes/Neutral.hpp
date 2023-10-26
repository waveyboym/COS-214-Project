/**
*@file Neutral.hpp Neutral.cpp
*@class Neutral
*@author Michael
*@implements EmotionalState
*@brief an Neutral class which is a concrete state class of EmotionalState
*/
#ifndef NEUTRAL_HPP
#define NEUTRAL_HPP
#include "EmotionalState.hpp"

/** 
*@brief an Neutral class which is a concrete state class of EmotionalState
*/
class Neutral: public EmotionalState{
    public:
        /** 
        *@brief returns the neutral emotional state as a string
        *@param none
        *@return std::string
        */
        std::string getEmotionalStateString();

        /** 
        *@brief returns the neutral emotional state as an emotional state enum
        *@param none
        *@return EMOTIONAL_STATE
        */
        EMOTIONAL_STATE getEmotionalStateEnum();
};

#endif