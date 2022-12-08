#ifndef CLASS_BUILDER_H
#define CLASS_BUILDER_H

#include <iostream>
#include <fstream>
#include <string>
//#include "rapidxml.hpp"

class ClassBuilder
{

public:
    ClassBuilder(std::string path);
    // ~ClassBuilder();
    //Attributes
    void set_XML_file_path(std::string new_XML_file_path);
    std::string get_XML_file_path();
    void clear();
    
private:
    std::string xml_file_path;

};


#endif //CODE_BUILDER_H