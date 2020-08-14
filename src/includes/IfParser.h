#ifndef IFPARSER_H
#define IFPARSER_H
#include<string>
class IFParser {
protected:
    std::string m_intent;
public:
    IFParser() = default;
    virtual ~IFParser() = default;
    virtual void parseInput(const std::string &)=0;
    inline std::string get_intent()const {
        return m_intent;
    }
};

#endif // IFPARSER_H
