#ifndef INTENTPROVIDER_H
#define INTENTPROVIDER_H

#include<memory>

#include "IfIntentProvider.h"
class IntentProvider:public IfIntentProvider
{
public:
    IntentProvider()=default;
    ~IntentProvider()=default;
    void parseInput(std::string) override;
};

#endif // INTENTPROVIDER_H
