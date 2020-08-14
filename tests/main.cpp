#include<iostream>
#include<memory>

#include "gtest/gtest.h"

#include "includes/IfIntentProvider.h"
#include "includes/intentproviderfactory.h"
#include "includes/constants.h"

class TestIntentRecognizer : public ::testing::Test {
public:
    std::unique_ptr<IfIntentProvider> m_intentProvider;
    virtual void SetUp() override {
        m_intentProvider = IntentProviderFactory::getIntentProvider(Constants::IntentProviders::BASIC);
    }

    virtual void TearDown() override {

    }
};

//Test cases for Weather intent.
TEST_F(TestIntentRecognizer, TestPositive_WeatherIntentCaseSmall) {
    std::string input = "What is the Weather like today?";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::weather_intent , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestPositive_WeatherIntentCaseCaptial) {
    std::string input = "WHAT IS THE WEATHER LIKE TODAY?";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::weather_intent , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestPositive_WeatherIntentMixedCaseInput) {
    std::string input = "WhAT IS THE WeATHer Today Like?";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::weather_intent , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestPositive_WeatherIntentOneWordMatch) {
    std::string input = "lqejqwklej weather jfjoepjfioejfioej";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::weather_intent , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestPositive_WeatherIntentOneWordInput) {
    std::string input = "weather";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::weather_intent , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestPositive_WeatherIntentKeywordInMiddle) {
    std::string input = "Whatistheweathertoday";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::weather_intent , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestNegative_WeatherIntentRandomInput) {
    std::string input = "lqejqwklej ihiowhihw jfjoepjfioejfioej";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::no_intent_found , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestNegative_WeatherIntentNoInput) {
    std::string input = "";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::no_intent_found , m_intentProvider->getIntent());
    }
}

//Test cases for Weather City Intent
TEST_F(TestIntentRecognizer, TestPositive_WeatherCityIntentCaseSmall) {
    std::string input = "What is the Weather like today in Paris?";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::weather_intent_city , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestPositive_WeatherCityIntentCaseCapital) {
    std::string input = "WHAT IS THE WEATHER LIKE TODAY IN PARIS";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::weather_intent_city , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestPositive_WeatherCityIntentMixedCaseInput) {
    std::string input = "WhAT IS THE WeATHer Today Like In LonDoN?";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::weather_intent_city , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestPositive_WeatherCityIntentOneWordMatch) {
    std::string input = "lqejqwklej weather jfjoepjfioejfioej in Berlin?";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::weather_intent_city , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestPositive_WeatherCityIntentOneWordInput) {
    std::string input = "weather in Berlin today";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::weather_intent_city , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestPositive_WeatherCityIntentKeywordInMiddle) {
    std::string input = "WhatistheweathertodayinBerlin";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::weather_intent_city , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestNegative_WeatherCityIntentRandomInput) {
    std::string input = "lqejqwklej ihiowhihw jfjoepjfioejfioej";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::no_intent_found , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestNegative_WeatherCityIntentNoInput) {
    std::string input = "";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::no_intent_found , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestNegative_WeatherCityIntentNoCityInput) {
    std::string input = "What is the weather today in";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::weather_intent , m_intentProvider->getIntent());
    }
}

//Test cases for Calendar Intent.

TEST_F(TestIntentRecognizer, TestPositive_CalendarIntentCaseSmall) {
    std::string input = "Am I free at 10:30AM tomorrow?";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::calendar_intent , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestPositive_CalendarIntentCaseCapital) {
    std::string input = "AM I FREE TOMORROW?";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::calendar_intent , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestPositive_CalendarIntentMixedCaseInput) {
    std::string input = "aM I frEe toMorroW?";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::calendar_intent , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestPositive_CalendarIntentOneWordMatch) {
    std::string input = "jdjdjdd free jjjr2ri2j";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::calendar_intent , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestPositive_CalendarIntentOneWordInput) {
    std::string input = "free";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::calendar_intent , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestPositive_CalendarIntentKeywordInMiddle) {
    std::string input = "amiFreeat10:30tomorrow?";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::calendar_intent , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestPositive_CalendarIntentSynonym) {
    std::string input = "Am I busy on next Friday at 1PM?";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::calendar_intent , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestPositive_CalendarIntentSynonym1) {
    std::string input = "Am I occupied tomorrow?";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::calendar_intent , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestNegative_CalendarIntentRandomInput) {
    std::string input = "lqejqwklej ihiowhihw jfjoepjfioejfioej";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::no_intent_found , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestNegative_CalendarIntentNoInput) {
    std::string input = "";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::no_intent_found , m_intentProvider->getIntent());
    }
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
