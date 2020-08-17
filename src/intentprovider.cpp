#include<iostream>
#include<algorithm>
#include<regex>
#include "intentprovider.h"
#include "constants.h"
#include "parserfactory.h"

void IntentProvider::parseInput(std::string input_text)
{
    //Convert input to lower_case.
    std::transform(input_text.begin(), input_text.end(), input_text.begin(), [](char ch){
        return std::tolower(ch);
    });
    Constants::Parsers::Parser enParser;
    //Regex Match to input.
    if(regex_match(input_text, std::regex("(.*)(weather|rain|sunny|(carry)?(.*)(umbrella))(.*)"))) {
        enParser = Constants::Parsers::Parser::WEATHER;
    }
    else if(regex_match(input_text, std::regex("(.*)(free|busy|occupied|(have)?(.*)(appointment[s]?|meeting[s]?))(.*)"))) {
        enParser = Constants::Parsers::Parser::CALENDAR;
    }
    else if(regex_match(input_text, std::regex("(.*)(fact[s]?|truth[s]?)(.*)"))) {
        enParser = Constants::Parsers::Parser::FACT;
    }
    else {
        enParser = Constants::Parsers::Parser::NONE;
    }
    if(enParser != Constants::Parsers::Parser::NONE) {
        auto parser = ParserFactory::getParser(enParser);
        if(parser) {
            parser->parseInput(input_text);
            m_recognizedIntent = parser->get_intent();
        }
        else {
            m_recognizedIntent = Constants::Intents::no_intent_found;
        }
    }
    else {
        m_recognizedIntent = Constants::Intents::no_intent_found;
    }

}

