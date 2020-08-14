#ifndef IFINTENTPROVIDER_H
#define IFINTENTPROVIDER_H

#include<string>
class IfIntentProvider {
protected:
    std::string m_recognizedIntent;
public:
    IfIntentProvider()=default;
    virtual ~IfIntentProvider()=default;
    virtual void parseInput(std::string) = 0;
    inline std::string getIntent()const {
        return m_recognizedIntent;
    }
};

#endif // IFINTENTPROVIDER_H
