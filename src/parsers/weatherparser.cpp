#include "weatherparser.h"
#include<iostream>
#include "constants.h"

void WeatherParser::parseInput(const std::string &input_text)
{
    std::string substr = input_text.substr(input_text.find("weather"));
    if(substr.find("in") != std::string::npos) {
        std::string substr1 = substr.substr(substr.find("in")+2);
        if(substr1.empty()) {
            m_intent = Constants::Intents::weather_intent;
        }
        else {
            m_intent = Constants::Intents::weather_intent_city;
        }
    }
    else{
        m_intent = Constants::Intents::weather_intent;
    }
}
