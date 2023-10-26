#include "../includes/Neutral.hpp"

std::string Neutral::getEmotionalStateString(){
    return "Neutral";
}

EMOTIONAL_STATE Neutral::getEmotionalStateEnum(){
    return EMOTIONAL_STATE::NEUTRAL;
}