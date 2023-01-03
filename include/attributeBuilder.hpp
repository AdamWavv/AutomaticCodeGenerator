#ifndef ATTRIBUTE_BUILDER_H
#define ATTRIBUTE_BUILDER_H

#include "codeBuilder.hpp"

class AttributeBuilder: public CodeBuilder
{
 
public:
    AttributeBuilder(std::string path);
    ~AttributeBuilder();
    //Methods
    void parse_document() override;
private:
    

};

   


#endif