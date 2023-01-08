#ifndef CLASS_BUILDER_H
#define CLASS_BUILDER_H

#include "codeBuilder.hpp"

class ClassBuilder: public CodeBuilder
{
 
public:
    ClassBuilder(std::string path);
    ~ClassBuilder();
    //Methods
    void parse_document() override;
private:
    

};


#endif