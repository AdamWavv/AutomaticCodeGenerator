#include <iostream>
#include <fstream>
#include <string>

#include "../include/classBuilder.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char* argv[])
{

    ClassBuilder cb("nazwa/pierwsza");

    // cout << "Nazwa sciezki uzytej podczas konstrukcji " << cb.get_XML_file_path() << '\n';

    std::string class_diagram_test = "../data/class_diagram_test/project.xml";
    std::string class_diagram_medium = "../data/class_diagram_medium/project.xml";
    std::string class_diagram_advanced = "../data/class_diagram_advanced/project.xml";
    std::string class_diagram_Astar = "../data/class_diagram_Astar/project.xml";

    std::string data_bufor = class_diagram_Astar;

    cb.set_XML_file_path(data_bufor);
    std::ifstream plik_in(data_bufor);
    if(plik_in.is_open()) 
        cout << "Otworzono plik i essa \n";

    // cout << "Nazwa sciezki uzytej po zmianie " << cb.get_XML_file_path() << '\n';



    cb.parse_document();

    return EXIT_SUCCESS;
}
