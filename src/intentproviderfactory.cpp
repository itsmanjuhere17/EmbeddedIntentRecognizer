#include "intentproviderfactory.h"
#include "intentprovider.h"
std::unique_ptr<IfIntentProvider> IntentProviderFactory::getIntentProvider(const Constants::IntentProviders::Version &ver) {
    std::unique_ptr<IfIntentProvider> instance = nullptr;
    switch(ver) {
    case Constants::IntentProviders::Version::BASIC: {
        instance = std::make_unique<IntentProvider>();
    }
    break;
    case Constants::IntentProviders::Version::ADVANCED: {
        instance = nullptr;
    }
        break;
    default: {
        instance = std::make_unique<IntentProvider>();
    }
    break;
    }
    return instance;
}
