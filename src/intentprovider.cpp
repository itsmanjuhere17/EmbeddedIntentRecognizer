#include<iostream>
#include<algorithm>
#include<regex>
#include "intentprovider.h"
#include "constants.h"

void IntentProvider::parseInput(std::string input_text)
{
    //Convert input to lower_case.
    std::transform(input_text.begin(), input_text.end(), input_text.begin(), [](char ch){
        return std::tolower(ch);
    });
    //Regex Match to input.
    if(regex_match(input_text, std::regex("(.*)(weather)(.*)"))) {
        std::string substr = input_text.substr(input_text.find("weather"));
        std::cout<<"substring is:"<<substr<<std::endl;
        if(substr.find("in") != std::string::npos) {
            std::string substr1 = substr.substr(substr.find("in")+2);
            std::cout<<"Substr1 is:"<<substr1<<std::endl;
            if(substr1.empty()) {
                std::cout<<"Intent is:"<<"intent_weather"<<std::endl;
                m_recognizedIntent = Constants::Intents::weather_intent;
            }
            else {
                std::cout<<"Intent is:"<<"intent_weather_city"<<std::endl;
                m_recognizedIntent = Constants::Intents::weather_intent_city;
            }
        }
        else{
            std::cout<<"Intent is:"<<"intent_weather"<<std::endl;
            m_recognizedIntent = Constants::Intents::weather_intent;
        }
    }
    else if(regex_match(input_text, std::regex("(.*)(free|busy|occupied)(.*)"))) {
        std::cout<<"Intent is:"<<"intent_calendar"<<std::endl;
        m_recognizedIntent = Constants::Intents::calendar_intent;
    }
    else if(regex_match(input_text, std::regex("(.*)(fact[s]*|truth[s]*)(.*)"))) {
        std::cout<<"Intent is:"<<"intent_fact"<<std::endl;
        m_recognizedIntent = Constants::Intents::fact_event;
    }
    else {
        std::cout<<"No Matching Intent found"<<std::endl;
        m_recognizedIntent = Constants::Intents::no_intent_found;
    }
}

void IntentProvider::showIntent()
{
    std::cout<<m_recognizedIntent<<std::endl;
}
