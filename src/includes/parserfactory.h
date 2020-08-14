#ifndef PARSERFACTORY_H
#define PARSERFACTORY_H

#include<memory>
#include "IfParser.h"
#include "constants.h"
class ParserFactory {
public:
    static std::unique_ptr<IFParser> getParser(const Constants::Parsers::Parser&);
};

#endif // PARSERFACTORY_H
