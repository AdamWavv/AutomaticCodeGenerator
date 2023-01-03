#include "../include/attributeBuilder.hpp"

AttributeBuilder::AttributeBuilder(std::string path)
    : CodeBuilder(path)
{
}

AttributeBuilder::~AttributeBuilder()
{
}

void AttributeBuilder::parse_document()
{
    //PREPARING DOCUMENT
    //Converting datatype from string to const char*
    std::string s = this->get_XML_file_path();
    const char* xml_in = s.c_str();
    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> * root_node = NULL;
    std::ifstream file (xml_in);

    std::cout << "\nParsing data in: \n" << xml_in << "\n ..... \n";
    std::cout << "TEST LOKALIZACJI PLIKU: " << this->get_XML_file_path() <<"\n";
    if (file.is_open())
    {   
        
        //Creating buffer to store data from xml file type:CHAR
        std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        buffer.push_back('\0');
        doc.parse<0>(&buffer[0]);
        const char* searched_node_name = "Class";
        if(search_node(xml_in,searched_node_name))
        {              
            for(rapidxml::xml_node<> * class_node = search_node(xml_in,searched_node_name);
                class_node;  
                class_node = class_node->next_sibling(searched_node_name))
            {   
                std::cout << "Adres " << class_node << class_node->name() << " is named:" << "\n  -" << class_node->first_attribute("Name")->value() <<"\n";
            }
        }


    }
    std::cout << "\n \n";
    file.close();
}