#include "weatherparser.h"
#include<iostream>
#include "constants.h"

void WeatherParser::parseInput(const std::string &input_text)
{
    std::string substr = input_text.substr(input_text.find("weather"));
    std::cout<<"substring is:"<<substr<<std::endl;
    if(substr.find("in") != std::string::npos) {
        std::string substr1 = substr.substr(substr.find("in")+2);
        std::cout<<"Substr1 is:"<<substr1<<std::endl;
        if(substr1.empty()) {
            std::cout<<"Intent is:"<<"intent_weather"<<std::endl;
            m_intent = Constants::Intents::weather_intent;
        }
        else {
            std::cout<<"Intent is:"<<"intent_weather_city"<<std::endl;
            m_intent = Constants::Intents::weather_intent_city;
        }
    }
    else{
        std::cout<<"Intent is:"<<"intent_weather"<<std::endl;
        m_intent = Constants::Intents::weather_intent;
    }
}
