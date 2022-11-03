#include <iostream>
#include "xml.hpp"

int main(int, char**)
{
    XMLDocument dupsko;
    int liczba{0};
    std::cout<<liczba;
    liczba = liczba + 10;
    XMLDocument_load();
    std::cout << liczba + 10;

    return 0;
}