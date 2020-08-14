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
    std::unique_ptr<IFParser> parser{nullptr};
    //Regex Match to input.
    if(regex_match(input_text, std::regex("(.*)(weather)(.*)"))) {
        parser = ParserFactory::getParser(Constants::Parsers::Parser::WEATHER);
    }
    else if(regex_match(input_text, std::regex("(.*)(free|busy|occupied)(.*)"))) {
        parser = ParserFactory::getParser(Constants::Parsers::Parser::CALENDAR);
    }
    else if(regex_match(input_text, std::regex("(.*)(fact[s]*|truth[s]*)(.*)"))) {
        parser = ParserFactory::getParser(Constants::Parsers::Parser::FACT);
    }
    else {
        std::cout<<"No Matching Intent found"<<std::endl;
        m_recognizedIntent = Constants::Intents::no_intent_found;
    }
    if(parser) {
        parser->parseInput(input_text);
        m_recognizedIntent = parser->get_intent();
    }
}

