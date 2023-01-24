#ifndef CODE_BUILDER_H
#define CODE_BUILDER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <string>
#include <cstring>
#include <stdio.h>
#include <type_traits>
#include <algorithm>
#include <regex>

#include "../lib/rapidxml-1.13/rapidxml.hpp"

/**
* @class ClassBuilder
* @brief CodeBuilder class header file
* @details This Super class is responsible for generating code for classes. It provides based methods and attributes.
* @author Adam Wawerski
* @include iostream, fstream, vector, unordered_map, iterator, string, cstring, stdio.h, type_traits, algorithm, regex, "../lib/rapidxml-1.13/rapidxml.hpp"
    This class provides a base for building other classes that will parse data from xml file and generate code from it.
    It also provides basic functionalities for handling xml files and searching for specific nodes in the file.
*/

class CodeBuilder
{
public:
/**
* @brief Constructor, sets the path to the XML file
* @param path - path to the XML file
*/
CodeBuilder(std::string path);
/*
* @brief Destructor
*/
~CodeBuilder();
//Methods
/*
* @brief Pure virtual method for generating code, must be overridden by derived classes
* @param class_name - name of the class for which the code should be generated
* @return string - generated code
*/
virtual std::string generateCode(std::string class_name) = 0;
/*
* @brief Virtual method for parsing data from the XML file, can be overridden by derived classes
*/
virtual void parse_document();

/**
 * @brief Sets the path to the XML file
 * @param new_XML_file_path - new path to the XML file
 */
void set_file_path(std::string &new_XML_file_path);
/**
 * @brief Returns the path to the XML file
 * @return string - path to the XML file
 */
std::string get_file_path();
/**
 * @brief Returns the vector of class names
 * @return vector<string> - vector of class names
 */
std::vector <std::string> get_class_vector();

/**
 * @brief Search for a node in the XML file
 * @param file_path - path to the XML file
 * @param node_name - name
 * @return rapidxml::xml_node<>* - pointer to node in xml file
*/
rapidxml::xml_node<>* search_node(const std::string file_path, const char* node_name);
/**
 * @brief Clears class data
 * @param new_XML_file_path - new path to the XML file
 */
void clear();

protected:
///protected Attributes
/**
    @var class_vector
    @brief a vector that stores the names of classes
    @details this vector is used to hold the names of classes that are parsed from the xml file
*/
std::vector <std::string> class_vector;
/**
    @var attribute_map
    @brief an unordered_map that stores the names of attributes and corelates them with classes
    @details this unordered_map is used to hold the names of attributes that are parsed from the xml file
*/
std::unordered_map<std::string, std::vector <std::string>> attribute_map;
/**
    @var method_map
    @brief an unordered_map that stores the names of methods and corelates them with classes
    @details this unordered_map is used to hold the names of methods that are parsed from the xml file
*/
std::unordered_map<std::string, std::vector <std::string>> method_map;
private:
/// private Attributes
/**
    @var xml_file_path
    @brief an string that stores the file path to XML file
    @details this string is used to hold the file path of the XML file to create code based on it
*/
std::string xml_file_path;
};


#endif //CODE_BUILDER_H
