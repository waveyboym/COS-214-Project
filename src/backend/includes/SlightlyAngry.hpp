/**
*@file SlightlyAngry.hpp SlightlyAngry.cpp
*@class SlightlyAngry
*@author Michael
*@implements EmotionalState
*@brief a SlightlyAngry class which is a concrete state class of EmotionalState
*/
#ifndef SLIGHTLY_ANGRY_HPP
#define SLIGHTLY_ANGRY_HPP
#include "EmotionalState.hpp"

/** 
*@brief a SlightlyAngry class which is a concrete state class of EmotionalState
*/
class SlightlyAngry: public EmotionalState{
    public:
        /** 
        *@brief returns the slightlyangry emotional state as a string
        *@param none
        *@return std::string
        */
        std::string getEmotionalStateString();

        /** 
        *@brief returns the slightlyangry emotional state as an emotional state enum
        *@param none
        *@return EMOTIONAL_STATE
        */
        EMOTIONAL_STATE getEmotionalStateEnum();
};

#endif