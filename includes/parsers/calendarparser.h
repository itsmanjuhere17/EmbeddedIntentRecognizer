#ifndef CALENDARPARSER_H
#define CALENDARPARSER_H

#include "IfParser.h"
class CalendarParser : public IFParser {
public:
    CalendarParser()=default;
    ~CalendarParser()=default;
    void parseInput(const std::string &) override;
};

#endif // CALENDARPARSER_H
