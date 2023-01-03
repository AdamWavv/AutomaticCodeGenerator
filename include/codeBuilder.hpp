#ifndef CODE_BUILDER_H
#define CODE_BUILDER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <cstring>
#include <stdio.h>
#include <type_traits>

#include "../lib/rapidxml-1.13/rapidxml.hpp"

// namespace rapidxml {
//     namespace internal {
//         template <class OutIt, class Ch>
//         inline OutIt print_children(OutIt out, const xml_node<Ch>* node, int flags, int indent);

//         template <class OutIt, class Ch>
//         inline OutIt print_attributes(OutIt out, const xml_node<Ch>* node, int flags);

//         template <class OutIt, class Ch>
//         inline OutIt print_data_node(OutIt out, const xml_node<Ch>* node, int flags, int indent);

//         template <class OutIt, class Ch>
//         inline OutIt print_cdata_node(OutIt out, const xml_node<Ch>* node, int flags, int indent);

//         template <class OutIt, class Ch>
//         inline OutIt print_element_node(OutIt out, const xml_node<Ch>* node, int flags, int indent);

//         template <class OutIt, class Ch>
//         inline OutIt print_declaration_node(OutIt out, const xml_node<Ch>* node, int flags, int indent);

//         template <class OutIt, class Ch>
//         inline OutIt print_comment_node(OutIt out, const xml_node<Ch>* node, int flags, int indent);

//         template <class OutIt, class Ch>
//         inline OutIt print_doctype_node(OutIt out, const xml_node<Ch>* node, int flags, int indent);

//         template <class OutIt, class Ch>
//         inline OutIt print_pi_node(OutIt out, const xml_node<Ch>* node, int flags, int indent);
//     }
// }

class CodeBuilder
{
public:
    CodeBuilder(std::string path);
    ~CodeBuilder();
    
//Methods
    void clear();
    virtual void parse_document() = 0;
    void set_XML_file_path(std::string new_XML_file_path);
    std::string get_XML_file_path();
    std::string generateCode();
    rapidxml::xml_node<>* search_node(const std::string file_path, const char* node_name);
    

protected:
//Attributes
    std::vector <std::string> names_vector;

private:
//Attributes
    std::string xml_file_path;
    

};


#endif //CODE_BUILDER_H
