#include "weatherparser.h"
#include<iostream>
#include "constants.h"

void WeatherParser::parseInput(const std::string &input_text)
{
    std::string substring;
    if(auto pos = input_text.find("weather"); pos!= std::string::npos) {
        substring = input_text.substr(pos);
    }
    else if(auto pos = input_text.find("rain"); pos!= std::string::npos) {
        substring = input_text.substr(pos);
    }
    else if(auto pos = input_text.find("umbrella"); pos!= std::string::npos) {
        substring = input_text.substr(pos);
    }
    else if(auto pos = input_text.find("sunny"); pos!= std::string::npos) {
        substring = input_text.substr(pos);
    }
    else {
        substring="";
    }

    if(!substring.empty()) {
        auto pos = substring.find("in");
        if(pos!= std::string::npos){
            std::string substr1 = substring.substr(substring.find("in")+2);
            if(substr1.empty()) {
                m_intent = Constants::Intents::weather_intent;
            }
            else {
                m_intent = Constants::Intents::weather_intent_city;
            }
        }
        else {
            m_intent = Constants::Intents::weather_intent;
        }
    }
}
