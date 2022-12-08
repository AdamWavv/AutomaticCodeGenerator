#include "../include/classBuilder.h"

ClassBuilder::ClassBuilder(std::string path): xml_file_path(path)
{
}
void ClassBuilder::set_XML_file_path(std::string new_XML_file_path){xml_file_path=new_XML_file_path;}
std::string ClassBuilder::get_XML_file_path(){return xml_file_path;}
void ClassBuilder::clear(){
    std::cout<<"dupa";
}
