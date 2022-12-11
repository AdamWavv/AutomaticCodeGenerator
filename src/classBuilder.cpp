#include "../include/classBuilder.h"

ClassBuilder::ClassBuilder(std::string path): xml_file_path(path)
{
}
void ClassBuilder::set_XML_file_path(std::string new_XML_file_path){xml_file_path=new_XML_file_path;}

std::string ClassBuilder::get_XML_file_path(){return xml_file_path;}

void ClassBuilder::clear(){
    std::cout<<"dupa";
}











void ClassBuilder::parse_document()
{
    const std::string& xml_in = this->xml_file_path;

    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> * root_node = NULL;
        std::cout << "\nParsing my students data (example.xml)..... \n";
   
    // Read the xml_in file
    std::ifstream theFile (xml_in);
    //Creating buffer for data proces
    std::vector<char> buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');
    // Parse the buffer
    doc.parse<0>(&buffer[0]);
    // Find out the root node
    root_node = doc.first_node("Project");
    
    rapidxml::xml_node<> * models_node = root_node->first_node()->next_sibling("Models");
   
    // Iterate over the student nodes
    for (rapidxml::xml_node<> * models_node = root_node->first_node("Models");
                                models_node; models_node = models_node->next_sibling())
    {
        std::cout << "\n Class Name =   " <<
                models_node->first_attribute("Name")->value();
        std::cout << "\n";
           
        // Interate over the Student Names
        for(rapidxml::xml_node<> * class_name_node = models_node->first_node("Name");
                class_name_node; class_name_node = class_name_node->next_sibling())
        {
            std::cout << "Class Name =   " << class_name_node->value();
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}