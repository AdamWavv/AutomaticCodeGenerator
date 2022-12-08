#ifndef PARAMETERCLASS_H
#define PARAMETERCLASS_H

#include <string>

class ParameterClass
{
public:
    ParameterClass();
    ~ParameterClass();


private:
    std::string name;
    const std::string acces = {};

};

#endif