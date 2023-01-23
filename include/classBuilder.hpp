#ifndef CLASS_BUILDER_H
#define CLASS_BUILDER_H

#include "codeBuilder.hpp"
#include "attributeBuilder.hpp"
#include "methodBuilder.hpp"

/**
* @class ClassBuilder
* @brief Class for generating code for classes
* @details This class is responsible for generating code for classes. It inherits from the CodeBuilder class and uses the AttributeBuilder and MethodBuilder classes to generate code for attributes and methods respectively.
* @author Adam Wawerski
* @include codeBuilder.hpp, attributeBuilder.hpp, methodBuilder.hpp
*/
class ClassBuilder: public CodeBuilder
{
 
public:
    /**
    * @brief Constructor
    * @param path - path to the XML file used to generate the code
    */
    ClassBuilder(std::string path);

    /**
    * @brief Destructor
    */
    ~ClassBuilder();

    /**
    * @brief Generates code for a class
    * @param class_name - name of the class for which the code will be generated
    * @returns string containing the generated code
    */
    std::string generateCode(std::string class_name) override;
};

#endif
