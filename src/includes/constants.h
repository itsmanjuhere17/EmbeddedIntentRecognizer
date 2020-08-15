#ifndef CONSTANTS_H
#define CONSTANTS_H

#include<string>
namespace Constants {

    namespace IntentProviders{
        enum Version {
            BASIC,
            ADVANCED
        };
    }

    namespace Intents {
        const std::string no_intent_found     = "Intent Not Found";
        const std::string weather_intent      = "Get Weather";
        const std::string weather_intent_city = "Get Weather City";
        const std::string calendar_intent     = "Check Calendar";
        const std::string fact_intent         = "Get Fact";
    }

    namespace Parsers {
        enum Parser {
            NONE,
            WEATHER,
            CALENDAR,
            FACT
        };
    }

}

#endif
