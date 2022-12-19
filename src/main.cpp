#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../include/codeBuilder.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char* argv[])
{

    CodeBuilder cb("nazwa/pierwsza");

    // cout << "Nazwa sciezki uzytej podczas konstrukcji " << cb.get_XML_file_path() << '\n';
    std::vector <const char*>  files{ "../data/class_diagram_test/project.xml",
    "../data/class_diagram_medium/project.xml",
    "../data/class_diagram_advanced/project.xml",
    "../data/class_diagram_Astar/project.xml"
    };

    std::vector <CodeBuilder> cb_vector;
    for (const auto &i: files)
    {
        std::cout << i << "\n";
        
        cb.set_XML_file_path(i);
        std::ifstream plik_in(i);
        if(plik_in.is_open()){ cout << "Otworzono plik i essa \n";} 
    
        // cout << "Nazwa sciezki uzytej po zmianie " << cb.get_XML_file_path() << '\n';

        cb.parse_document();
    }
    



    return EXIT_SUCCESS;
}
