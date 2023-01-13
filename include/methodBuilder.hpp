#ifndef METHOD_BUILDER_H
#define METHOD_BUILDER_H

#include "codeBuilder.hpp"

class MethodBuilder: public CodeBuilder
{
 
public:
    MethodBuilder(std::string path);
    ~MethodBuilder();
    //Methods
    void parse_document() override;
    std::string generateCode() override;

    std::unordered_map<std::string, std::vector<std::string>> get_method_map();

private:
    

};


#endif