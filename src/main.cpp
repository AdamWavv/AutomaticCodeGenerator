#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../include/codeBuilder.hpp"
#include "../include/attributeBuilder.hpp"
#include "../include/methodBuilder.hpp"


using std::cout;
using std::cin;
using std::endl;

int main(int argc, char* argv[])
{

    AttributeBuilder ab("");
    MethodBuilder mb("");
    std::vector <const char*>  files{ 
    "../data/class_diagram_test/project.xml",
    "../data/class_diagram_medium/project.xml",
    "../data/class_diagram_advanced/project.xml",
    "../data/class_diagram_Astar/project.xml"
    };

    for (const auto i: files)
    {   
        ab.set_file_path(i);
        ab.parse_document();
        mb.set_file_path(i);
        mb.parse_document();

        std::vector <std::string> dupa = ab.get_class_vector();
        for (auto& element : dupa){
            std::cout << element << " : \n";

            std::unordered_map<std::string, std::vector<std::string>> attribute_map = ab.get_attribute_map();
            std::vector<std::string> attributes = attribute_map[element];
            std::cout << "Attributes: " << "\n";
            for (auto& attr : attributes){
                std::cout << "      -" << attr << "\n";
            }
            std::unordered_map<std::string, std::vector<std::string>> method_map = mb.get_method_map();
            std::vector<std::string> methods = method_map[element];
            std::cout << "Methods: " << "\n";
            for (auto& mts : methods){
                std::cout << "      -" << mts << "\n";
            }
        }
        mb.generateCode();
    }
    

    return EXIT_SUCCESS;
}
