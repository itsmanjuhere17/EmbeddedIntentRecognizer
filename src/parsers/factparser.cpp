#include "factparser.h"
#include "constants.h"

void FactParser::parseInput(const std::string &input)
{
    m_intent = Constants::Intents::fact_event;
}
