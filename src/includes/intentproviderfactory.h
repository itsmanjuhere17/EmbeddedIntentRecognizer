#ifndef INTENTPROVIDERFACTORY_H
#define INTENTPROVIDERFACTORY_H
#include<memory>
class IfIntentProvider;
#include "constants.h"
class IntentProviderFactory
{
public:
    IntentProviderFactory() = delete;
    ~IntentProviderFactory() = delete;
    static std::unique_ptr<IfIntentProvider> getIntentProvider(const Constants::IntentProviders::Version&);
};

#endif // INTENTPROVIDERFACTORY_H
