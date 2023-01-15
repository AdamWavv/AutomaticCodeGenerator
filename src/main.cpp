#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../include/codeBuilder.hpp"
#include "../include/attributeBuilder.hpp"
#include "../include/methodBuilder.hpp"
#include "../include/classBuilder.hpp"


using std::cout;
using std::cin;
using std::endl;

int main(int argc, char* argv[])
{

    
    std::vector <const char*>  files{ 
    "../data/class_diagram_test/project.xml",
    "../data/class_diagram_medium/project.xml",
    "../data/class_diagram_advanced/project.xml",
    // "../data/class_diagram_Astar/project.xml"
    };

    for (const auto i: files)
    {   
        ClassBuilder cb(i);
        cb.parse_document();
        cb.generateCode();
    }
    

    return EXIT_SUCCESS;
}
