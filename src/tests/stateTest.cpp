/**
*@file stateTest.cpp
*@namespace stateTest
*@class none
*@author Michael
*@brief tests the state design pattern and their functions
*/

#include <gtest/gtest.h>
#include "../backend/includes/Angry.hpp"
#include "../backend/includes/Happy.hpp"
#include "../backend/includes/Neutral.hpp"
#include "../backend/includes/SlightlyAngry.hpp"
#include "../backend/includes/SlightlyHappy.hpp"

namespace ANGRY_TEST{

    TEST(AngryState_test, INIT_ANGRY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Angry>();

        ASSERT_NE(ES, nullptr);
    }

    TEST(AngryState_test, GET_ANGRY_STATE_STRING)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Angry>();

        ASSERT_NE(ES, nullptr);
        EXPECT_EQ(ES->getEmotionalStateString(), "Angry");
    }

    TEST(AngryState_test, GET_ANGRY_STATE_ENUM)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Angry>();

        ASSERT_NE(ES, nullptr);
        EXPECT_EQ(ES->getEmotionalStateEnum(), EMOTIONAL_STATE::ANGRY);
    }

    TEST(AngryState_test, DOWNCAST_ANGRY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Angry>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<Angry> AES = std::dynamic_pointer_cast<Angry>(ES);
        ASSERT_NE(AES, nullptr);
    }

    TEST(AngryState_test, CHANGE_ANGRY_STATE_TO_HAPPY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Angry>();
        ASSERT_NE(ES, nullptr);

        ES = std::make_shared<Happy>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<Happy> HES = std::dynamic_pointer_cast<Happy>(ES);
        ASSERT_NE(HES, nullptr);
    }

    TEST(AngryState_test, CHANGE_ANGRY_STATE_TO_NEUTRAL_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Angry>();
        ASSERT_NE(ES, nullptr);

        ES = std::make_shared<Neutral>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<Neutral> NES = std::dynamic_pointer_cast<Neutral>(ES);
        ASSERT_NE(NES, nullptr);
    }

    TEST(AngryState_test, CHANGE_ANGRY_STATE_TO_SLIGHTLY_ANGRY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Angry>();
        ASSERT_NE(ES, nullptr);

        ES = std::make_shared<SlightlyAngry>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<SlightlyAngry> SAES = std::dynamic_pointer_cast<SlightlyAngry>(ES);
        ASSERT_NE(SAES, nullptr);
    }

    TEST(AngryState_test, CHANGE_ANGRY_STATE_TO_SLIGHTLY_HAPPY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Angry>();
        ASSERT_NE(ES, nullptr);

        ES = std::make_shared<SlightlyHappy>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<SlightlyHappy> SHES = std::dynamic_pointer_cast<SlightlyHappy>(ES);
        ASSERT_NE(SHES, nullptr);
    }

}

namespace HAPPY_TEST{

    TEST(HappyState_test, INIT_HAPPY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Happy>();

        ASSERT_NE(ES, nullptr);
    }

    TEST(HappyState_test, GET_HAPPY_STATE_STRING)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Happy>();

        ASSERT_NE(ES, nullptr);
        EXPECT_EQ(ES->getEmotionalStateString(), "Happy");
    }

    TEST(HappyState_test, GET_HAPPY_STATE_ENUM)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Happy>();

        ASSERT_NE(ES, nullptr);
        EXPECT_EQ(ES->getEmotionalStateEnum(), EMOTIONAL_STATE::HAPPY);
    }

    TEST(HappyState_test, DOWNCAST_HAPPY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Happy>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<Happy> HES = std::dynamic_pointer_cast<Happy>(ES);
        ASSERT_NE(HES, nullptr);
    }

    TEST(HappyState_test, CHANGE_HAPPY_STATE_TO_ANGRY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Happy>();
        ASSERT_NE(ES, nullptr);

        ES = std::make_shared<Angry>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<Angry> AES = std::dynamic_pointer_cast<Angry>(ES);
        ASSERT_NE(AES, nullptr);
    }

    TEST(HappyState_test, CHANGE_HAPPY_STATE_TO_NEUTRAL_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Happy>();
        ASSERT_NE(ES, nullptr);

        ES = std::make_shared<Neutral>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<Neutral> NES = std::dynamic_pointer_cast<Neutral>(ES);
        ASSERT_NE(NES, nullptr);
    }

    TEST(HappyState_test, CHANGE_HAPPY_STATE_TO_SLIGHTLY_ANGRY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Happy>();
        ASSERT_NE(ES, nullptr);

        ES = std::make_shared<SlightlyAngry>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<SlightlyAngry> SAES = std::dynamic_pointer_cast<SlightlyAngry>(ES);
        ASSERT_NE(SAES, nullptr);
    }

    TEST(HappyState_test, CHANGE_HAPPY_STATE_TO_SLIGHTLY_HAPPY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Happy>();
        ASSERT_NE(ES, nullptr);

        ES = std::make_shared<SlightlyHappy>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<SlightlyHappy> SHES = std::dynamic_pointer_cast<SlightlyHappy>(ES);
        ASSERT_NE(SHES, nullptr);
    }

}

namespace NEUTRAL_TEST{

    TEST(NeutralState_test, INIT_NEUTRAL_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Neutral>();

        ASSERT_NE(ES, nullptr);
    }

    TEST(NeutralState_test, GET_NEUTRAL_STATE_STRING)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Neutral>();

        ASSERT_NE(ES, nullptr);
        EXPECT_EQ(ES->getEmotionalStateString(), "Neutral");
    }

    TEST(NeutralState_test, GET_NEUTRAL_STATE_ENUM)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Neutral>();

        ASSERT_NE(ES, nullptr);
        EXPECT_EQ(ES->getEmotionalStateEnum(), EMOTIONAL_STATE::NEUTRAL);
    }

    TEST(NeutralState_test, DOWNCAST_NEUTRAL_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Neutral>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<Neutral> NES = std::dynamic_pointer_cast<Neutral>(ES);
        ASSERT_NE(NES, nullptr);
    }

    TEST(NeutralState_test, CHANGE_NEUTRAL_STATE_TO_ANGRY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Neutral>();
        ASSERT_NE(ES, nullptr);

        ES = std::make_shared<Angry>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<Angry> AES = std::dynamic_pointer_cast<Angry>(ES);
        ASSERT_NE(AES, nullptr);
    }

    TEST(NeutralState_test, CHANGE_NEUTRAL_STATE_TO_HAPPY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Neutral>();
        ASSERT_NE(ES, nullptr);

        ES = std::make_shared<Happy>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<Happy> NES = std::dynamic_pointer_cast<Happy>(ES);
        ASSERT_NE(NES, nullptr);
    }

    TEST(NeutralState_test, CHANGE_NEUTRAL_STATE_TO_SLIGHTLY_ANGRY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Neutral>();
        ASSERT_NE(ES, nullptr);

        ES = std::make_shared<SlightlyAngry>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<SlightlyAngry> SAES = std::dynamic_pointer_cast<SlightlyAngry>(ES);
        ASSERT_NE(SAES, nullptr);
    }

    TEST(NeutralState_test, CHANGE_NEUTRAL_STATE_TO_SLIGHTLY_HAPPY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<Neutral>();
        ASSERT_NE(ES, nullptr);

        ES = std::make_shared<SlightlyHappy>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<SlightlyHappy> SHES = std::dynamic_pointer_cast<SlightlyHappy>(ES);
        ASSERT_NE(SHES, nullptr);
    }

}

namespace SLIGHTLY_ANGRY_TEST{

    TEST(SlightlyAngryState_test, INIT_SLIGHTLY_ANGRY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<SlightlyAngry>();

        ASSERT_NE(ES, nullptr);
    }

    TEST(SlightlyAngryState_test, GET_SLIGHTLY_ANGRY_STATE_STRING)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<SlightlyAngry>();

        ASSERT_NE(ES, nullptr);
        EXPECT_EQ(ES->getEmotionalStateString(), "SlightlyAngry");
    }

    TEST(SlightlyAngryState_test, GET_SLIGHTLY_ANGRY_STATE_ENUM)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<SlightlyAngry>();

        ASSERT_NE(ES, nullptr);
        EXPECT_EQ(ES->getEmotionalStateEnum(), EMOTIONAL_STATE::SLIGHTLY_ANGRY);
    }

    TEST(SlightlyAngryState_test, DOWNCAST_SLIGHTLY_ANGRY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<SlightlyAngry>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<SlightlyAngry> NES = std::dynamic_pointer_cast<SlightlyAngry>(ES);
        ASSERT_NE(NES, nullptr);
    }

    TEST(SlightlyAngryState_test, CHANGE_SLIGHTLY_ANGRY_STATE_TO_ANGRY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<SlightlyAngry>();
        ASSERT_NE(ES, nullptr);

        ES = std::make_shared<Angry>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<Angry> AES = std::dynamic_pointer_cast<Angry>(ES);
        ASSERT_NE(AES, nullptr);
    }

    TEST(SlightlyAngryState_test, CHANGE_SLIGHTLY_ANGRY_STATE_TO_HAPPY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<SlightlyAngry>();
        ASSERT_NE(ES, nullptr);

        ES = std::make_shared<Happy>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<Happy> HES = std::dynamic_pointer_cast<Happy>(ES);
        ASSERT_NE(HES, nullptr);
    }

    TEST(SlightlyAngryState_test, CHANGE_SLIGHTLY_ANGRY_STATE_TO_NEUTRAL_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<SlightlyAngry>();
        ASSERT_NE(ES, nullptr);

        ES = std::make_shared<Neutral>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<Neutral> NES = std::dynamic_pointer_cast<Neutral>(ES);
        ASSERT_NE(NES, nullptr);
    }

    TEST(SlightlyAngryState_test, CHANGE_SLIGHTLY_ANGRY_STATE_TO_SLIGHTLY_HAPPY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<SlightlyAngry>();
        ASSERT_NE(ES, nullptr);

        ES = std::make_shared<SlightlyHappy>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<SlightlyHappy> SHES = std::dynamic_pointer_cast<SlightlyHappy>(ES);
        ASSERT_NE(SHES, nullptr);
    }
}

namespace SLIGHTLY_HAPPY_TEST{

    TEST(SlightlyHappyState_test, INIT_SLIGHTLY_HAPPY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<SlightlyHappy>();

        ASSERT_NE(ES, nullptr);
    }

    TEST(SlightlyHappyState_test, GET_SLIGHTLY_HAPPY_STATE_STRING)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<SlightlyHappy>();

        ASSERT_NE(ES, nullptr);
        EXPECT_EQ(ES->getEmotionalStateString(), "SlightlyHappy");
    }

    TEST(SlightlyHappyState_test, GET_SLIGHTLY_HAPPY_STATE_ENUM)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<SlightlyHappy>();

        ASSERT_NE(ES, nullptr);
        EXPECT_EQ(ES->getEmotionalStateEnum(), EMOTIONAL_STATE::SLIGHTLY_HAPPY);
    }

    TEST(SlightlyHappyState_test, DOWNCAST_SLIGHTLY_HAPPY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<SlightlyHappy>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<SlightlyHappy> NES = std::dynamic_pointer_cast<SlightlyHappy>(ES);
        ASSERT_NE(NES, nullptr);
    }

    TEST(SlightlyHappyState_test, CHANGE_SLIGHTLY_HAPPY_STATE_TO_ANGRY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<SlightlyHappy>();
        ASSERT_NE(ES, nullptr);

        ES = std::make_shared<Angry>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<Angry> AES = std::dynamic_pointer_cast<Angry>(ES);
        ASSERT_NE(AES, nullptr);
    }

    TEST(SlightlyHappyState_test, CHANGE_SLIGHTLY_HAPPY_STATE_TO_HAPPY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<SlightlyHappy>();
        ASSERT_NE(ES, nullptr);

        ES = std::make_shared<Happy>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<Happy> HES = std::dynamic_pointer_cast<Happy>(ES);
        ASSERT_NE(HES, nullptr);
    }

    TEST(SlightlyHappyState_test, CHANGE_SLIGHTLY_HAPPY_STATE_TO_NEUTRAL_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<SlightlyHappy>();
        ASSERT_NE(ES, nullptr);

        ES = std::make_shared<Neutral>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<Neutral> NES = std::dynamic_pointer_cast<Neutral>(ES);
        ASSERT_NE(NES, nullptr);
    }

    TEST(SlightlyHappyState_test, CHANGE_SLIGHTLY_HAPPY_STATE_TO_SLIGHTLY_ANGRY_STATE)
    {
        std::shared_ptr<EmotionalState> ES = std::make_shared<SlightlyHappy>();
        ASSERT_NE(ES, nullptr);

        ES = std::make_shared<SlightlyAngry>();
        ASSERT_NE(ES, nullptr);

        std::shared_ptr<SlightlyAngry> SAES = std::dynamic_pointer_cast<SlightlyAngry>(ES);
        ASSERT_NE(SAES, nullptr);
    }

}