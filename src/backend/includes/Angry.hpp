/**
*@file Angry.hpp Angry.cpp
*@class Angry
*@author Michael
*@implements EmotionalState
*@brief an Angry class which is a concrete state class of EmotionalState
*/
#ifndef ANGRY_HPP
#define ANGRY_HPP
#include "EmotionalState.hpp"

/** 
*@brief an Angry class which is a concrete state class of EmotionalState
*/
class Angry: public EmotionalState{
    public:
        /** 
        *@brief returns the angry emotional state as a string
        *@param none
        *@return std::string
        */
        std::string getEmotionalStateString();

        /** 
        *@brief returns the angry emotional state as an emotional state enum
        *@param none
        *@return EMOTIONAL_STATE
        */
        EMOTIONAL_STATE getEmotionalStateEnum();
};

#endif