#ifndef INTENTPROVIDER_H
#define INTENTPROVIDER_H

#include<memory>

#include "IfIntentProvider.h"
class IntentProvider:public IfIntentProvider
{
    std::string m_recognizedIntent;
public:
    IntentProvider()=default;
    ~IntentProvider()=default;
    void parseInput(std::string) override;
    void showIntent() override;
};

#endif // INTENTPROVIDER_H
