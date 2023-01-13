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

class CodeBuilder
{
public:
    CodeBuilder(std::string path);
    ~CodeBuilder();
//Methods
virtual void parse_document() = 0;
virtual std::string generateCode();

void set_file_path(std::string new_XML_file_path);
std::string get_file_path();
std::vector <std::string> get_class_vector();

rapidxml::xml_node<>* search_node(const std::string file_path, const char* node_name);
void clear();

protected:
//Attributes
    std::vector <std::string> class_vector;
    std::unordered_map<std::string, std::vector <std::string>> attribute_map;
    std::unordered_map<std::string, std::vector <std::string>> method_map;
private:
//Attributes
    std::string xml_file_path;
};


#endif //CODE_BUILDER_H
