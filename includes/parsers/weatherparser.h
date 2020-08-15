#ifndef WEATHERPARSER_H
#define WEATHERPARSER_H

#include "IfParser.h"
class WeatherParser:public IFParser {
public:
    WeatherParser()=default;
    ~WeatherParser()=default;
    void parseInput(const std::string &) override;
};

#endif // WEATHERPARSER_H
