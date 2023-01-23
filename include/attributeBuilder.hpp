#ifndef ATTRIBUTE_BUILDER_H
#define ATTRIBUTE_BUILDER_H

#include "codeBuilder.hpp"

/**
* @file         attributeBuilder.hpp
* @brief        class for parsing and generating attributes from XML file
* @detail       this class inherits from CodeBuilder and parses attribute data from a given XML file,
*               it also provides a method for generating code for attributes
* @author       Adam Wawerski
* @include      codeBuilder.hpp
*/

class AttributeBuilder: public CodeBuilder
{
 
public:
    AttributeBuilder(std::string path);
    ~AttributeBuilder();
    
    /**
    * @brief         parse data from xml file
    * @detail        parse_document method parse data from xml file and stores it in attribute_map
    * @return        void
    */
    void parse_document() override;

    /**
    * @brief         getter for attribute_map
    * @detail        getter method for attribute_map
    * @return        std::unordered_map<std::string, std::vector<std::string>>
    */
    std::unordered_map<std::string, std::vector<std::string>> get_attribute_map();

    /**
    * @brief         generate code for attributes
    * @detail        generateCode method generates code for attributes based on data stored in attribute_map
    * @param         std::string class_
    */
    std::string generateCode(std::string class_name);
};


#endif