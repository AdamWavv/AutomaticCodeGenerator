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
    if (file.is_open())
    {   
        
        //Creating buffer to store data from xml file type:CHAR
        std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        buffer.push_back('\0');
        doc.parse<0>(&buffer[0]);
        const char* searched_node_name = "Class";
        if(search_node(xml_in,searched_node_name)->value())
        {              
            for(rapidxml::xml_node<> * class_node = search_node(xml_in,searched_node_name);
                class_node;  
                class_node = class_node->next_sibling(searched_node_name))
            {   
                std::cout << "Adres " << class_node << " " << class_node->name() << " is named: " << "\n  -" << class_node->first_attribute("Name")->value() << "\n";
                std::string dupa = class_node->first_attribute("Name")->value();
                std::cout << "\n" << dupa << "\n";
                this->names_vector.push_back(dupa);
                             
            }
            file.close();
        }
        else
        {
            std::cout << "WRONG NODE NAME";
            file.close();
        }

    }
    std::cout << "\n \n";  
}