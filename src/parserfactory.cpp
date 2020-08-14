#include "parserfactory.h"
#include "weatherparser.h"
#include "calendarparser.h"
#include "factparser.h"

std::unique_ptr<IFParser> ParserFactory::getParser(const Constants::Parsers::Parser &parser)
{
    std::unique_ptr<IFParser> parser_instance = nullptr;
    switch(parser) {
    case Constants::Parsers::Parser::WEATHER:{
        parser_instance = std::make_unique<WeatherParser>();
    }
    break;
    case Constants::Parsers::Parser::CALENDAR: {
        parser_instance = std::make_unique<CalendarParser>();
    }
    break;
    case Constants::Parsers::Parser::FACT: {
        parser_instance = std::make_unique<FactParser>();
    }
    break;
    default: {
        break;
    }
    }
    return parser_instance;
}
