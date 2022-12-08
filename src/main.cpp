#include <iostream>
#include <string>

#include "../include/classBuilder.h"
#include "../include/parameterClass.h"

using std::cout, std::cin, std::endl;

int main(int argc, char* argv[])
{
    ClassBuilder cb("nazwa/pierwsza");

    cout << "Nazwa sciezki uzytej podczas konstrukcji" << cb.get_XML_file_path() << '\n';

    std::string first_file ="nazwa/zmieniona";

    cb.set_XML_file_path(first_file);

    cout << "Nazwa sciezki uzytej po zmianie" << cb.get_XML_file_path() << '\n';

    cb.parse_document();

    return EXIT_SUCCESS;
}
