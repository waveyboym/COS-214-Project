/**
*@file SlightlyHappy.hpp SlightlyHappy.cpp
*@class SlightlyHappy
*@author Michael
*@implements EmotionalState
*@brief an SlightlyHappy class which is a concrete state class of EmotionalState
*/
#ifndef SLIGHTLY_HAPPY_HPP
#define SLIGHTLY_HAPPY_HPP
#include "EmotionalState.hpp"

/** 
*@brief an SlightlyHappy class which is a concrete state class of EmotionalState
*/
class SlightlyHappy: public EmotionalState{
    public:
        /** 
        *@brief returns the slightlyhappy emotional state as a string
        *@param none
        *@return std::string
        */
        std::string getEmotionalStateString();

        /** 
        *@brief returns the slightlyhappy emotional state as an emotional state enum
        *@param none
        *@return EMOTIONAL_STATE
        */
        EMOTIONAL_STATE getEmotionalStateEnum();
};

#endif