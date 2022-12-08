#include <iostream>
#include <string>

#include "../include/classBuilder.h"
#include "../include/parameterClass.h"

int main(int argc, char**)
{
    ClassBuilder dupaRogala("nazwa/pierwsza");
    char name[50];
    //std::cin.get(name, 50);
    std::string dupaWnazwie = "nazwa/druga";
    dupaRogala.set_XML_file_path(dupaWnazwie);
    std::cout << "Witaj " << dupaWnazwie << " !";
    
    return EXIT_SUCCESS;
}