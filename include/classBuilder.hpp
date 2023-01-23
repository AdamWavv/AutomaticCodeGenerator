#ifndef CLASS_BUILDER_H
#define CLASS_BUILDER_H

#include "codeBuilder.hpp"
#include "attributeBuilder.hpp"
#include "methodBuilder.hpp"

class ClassBuilder: public CodeBuilder
{
 
public:
    ClassBuilder(std::string path);
    ~ClassBuilder();
    //Methods
    std::string generateCode(std::string class_name) override;
private:
    

};


#endif