#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../include/codeBuilder.hpp"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char* argv[])
{

    CodeBuilder cb("");

    // cout << "Nazwa sciezki uzytej podczas konstrukcji " << cb.get_XML_file_path() << '\n';
    std::vector <const char*>  files{ 
    "../data/class_diagram_test/project.xml",
    "../data/class_diagram_medium/project.xml",
    "../data/class_diagram_advanced/project.xml",
    "../data/class_diagram_Astar/project.xml"
    };

    std::vector <CodeBuilder> cb_vector;
    for (const auto i: files)
    {   
        cb.set_XML_file_path(i);
        std::ifstream plik_in(i);
        cb.parse_document();
    }
    

    return EXIT_SUCCESS;
}
