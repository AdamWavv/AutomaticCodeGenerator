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

    std::unordered_map<std::string, std::vector<std::string>> get_attribute_map();
    std::string generateCode(std::string class_name);
private:
    

};


#endif