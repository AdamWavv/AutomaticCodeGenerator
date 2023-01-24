#ifndef METHOD_BUILDER_H
#define METHOD_BUILDER_H

#include "codeBuilder.hpp"

/**

    @file methodBuilder.hpp
    @brief This file contains the declaration of the MethodBuilder class.
    @detail The MethodBuilder class inherits from the CodeBuilder class, and is used to parse data from an XML file and generate code for methods in a class.
    @author Adam Wawerski
    @include codeBuilder.hpp
*/

class MethodBuilder: public CodeBuilder
{

public:
/**
* @brief Constructor for the MethodBuilder class
* @param[in] path The path to the XML file to be parsed
*/
MethodBuilder(std::string path);

/**
* @brief        Destructor for the MethodBuilder class
*/
~MethodBuilder();

///Methods
/**
* @brief        Overriden function from the CodeBuilder class, used to parse the data from the XML file
*/
void parse_document() override;

/**
* @brief        Generates code for methods in a class, based on the data parsed from the XML file
* @param[in]    class_name  The name of the class for which the code is to be generated
* @return       std::string containing the generated code
*/
std::string generateCode(std::string class_name);

/**
* @brief        Getter method for the method_map attribute
* @return       An unordered_map containing the methods of each class in the form <class_name, vector of method names>
*/
std::unordered_map<std::string, std::vector<std::string>> get_method_map();

};

#endif