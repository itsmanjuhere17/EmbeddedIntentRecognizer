#include <iostream>
#include<memory>
using namespace std;

#include "constants.h"
#include "IfIntentProvider.h"
#include "intentproviderfactory.h"
int main(int argc, char** argv)
{
    if(argc < 2) {
        std::cerr<<"Please input a text."<<std::endl;
        std::exit(1);
    }
    //Read command line input.
    std::string input_text;
    for(auto index=1 ;index < argc; ++index) {
        input_text += argv[index];
        input_text += " ";
    }
    auto intent_prov = IntentProviderFactory::getIntentProvider(Constants::IntentProviders::Version::BASIC);
    intent_prov->parseInput(input_text);
    intent_prov->showIntent();
    return 0;
}
