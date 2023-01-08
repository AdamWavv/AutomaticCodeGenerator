#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../include/codeBuilder.hpp"
#include "../include/attributeBuilder.hpp"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char* argv[])
{

    AttributeBuilder cb("");

    // cout << "Nazwa sciezki uzytej podczas konstrukcji " << cb.get_XML_file_path() << '\n';
    std::vector <const char*>  files{ 
    "../data/class_diagram_test/project.xml",
    "../data/class_diagram_medium/project.xml",
    "../data/class_diagram_advanced/project.xml",
    "../data/class_diagram_Astar/project.xml"
    };

    std::vector <AttributeBuilder> cb_vector;
    for (const auto i: files)
    {   
        cb.set_file_path(i);
        cb.parse_document();
        std::vector <std::string> dupa = cb.get_class_vector();
        for (auto& element : dupa){
            std::cout << element << std::endl;
        }
        cb.clear();  
    }
    

    return EXIT_SUCCESS;
}
