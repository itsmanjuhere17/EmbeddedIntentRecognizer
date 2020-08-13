#ifndef IFINTENTPROVIDER_H
#define IFINTENTPROVIDER_H

#include<string>
class IfIntentProvider {
public:
    IfIntentProvider()=default;
    virtual ~IfIntentProvider()=default;
    virtual void parseInput(std::string) = 0;
    virtual void showIntent() = 0;
};

#endif // IFINTENTPROVIDER_H
