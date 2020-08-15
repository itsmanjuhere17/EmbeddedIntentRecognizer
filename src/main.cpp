#include <iostream>
#include<memory>
#include<regex>
using namespace std;

#include "constants.h"
#include "IfIntentProvider.h"
#include "intentproviderfactory.h"
int main()
{
    std::cout<<std::endl<<"############# EMBEDDED INTENT RECOGNIZER ###############"<<std::endl<<std::endl;
    std::cout<<"Please enter a input text. If you want to exit, say good bye!"<<std::endl;
    while(1) {
        std::string input_text;
        std::getline(std::cin, input_text);
        //Convert input to lower_case.
        std::transform(input_text.begin(), input_text.end(), input_text.begin(), [](char ch){
            return std::tolower(ch);
        });
        if(regex_match(input_text, std::regex("(good)?(.*)(bye)+(.*)"))) {
            std::cout<<"Good Bye!!"<<std::endl;
            break;
        }
        auto intent_prov = IntentProviderFactory::getIntentProvider(Constants::IntentProviders::Version::BASIC);
        if(intent_prov) {
            intent_prov->parseInput(input_text);
            std::cout<<"Intent:"<<intent_prov->getIntent()<<std::endl<<std::endl;
        }
    }

    return 0;
}
