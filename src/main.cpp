#include <iostream>
#include <fstream>
#include <string>

#include "../include/classBuilder.h"
#include "../include/parameterClass.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char* argv[])
{

    ClassBuilder cb("nazwa/pierwsza");

    cout << "Nazwa sciezki uzytej podczas konstrukcji " << cb.get_XML_file_path() << '\n';

    std::string first_file = "/home/adam/source/AutomaticCodeGenerator/AutomaticCodeGenerator/data/class_diagram_test/project.xml";
    std::string second_file = "/home/adam/source/AutomaticCodeGenerator/AutomaticCodeGenerator/build/example.xml";

    cb.set_XML_file_path(first_file);

    std::ifstream plik_in(first_file);
    if(plik_in.is_open()) 
        cout << "Otworzono plik i essa \n";

    cout << "Nazwa sciezki uzytej po zmianie " << cb.get_XML_file_path() << '\n';



    cb.parse_document();

    return EXIT_SUCCESS;
}
