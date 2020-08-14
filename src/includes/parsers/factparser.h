#ifndef FACTPARSER_H
#define FACTPARSER_H

#include "IfParser.h"

class FactParser : public IFParser {
public:
    FactParser()=default;
    ~FactParser()=default;
    void parseInput(const std::string &) override;
};

#endif // FACTPARSER_H
