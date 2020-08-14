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

TEST_F(TestIntentRecognizer, TestPositive_WeatherIntentCaseSensitive) {
    std::string input = "What is the Weather like today?";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::weather_intent , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestPositive_WeatherIntentCaseInsensitive) {
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

TEST_F(TestIntentRecognizer, TestPositive_WeatherCityIntentCaseSensitive) {
    std::string input = "What is the Weather like today in Paris?";
    if(m_intentProvider) {
        m_intentProvider->parseInput(input);
        EXPECT_EQ(Constants::Intents::weather_intent_city , m_intentProvider->getIntent());
    }
}

TEST_F(TestIntentRecognizer, TestPositive_WeatherCityIntentCaseInsensitive) {
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

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
