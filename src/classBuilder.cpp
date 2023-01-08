#include "../include/classBuilder.hpp"

ClassBuilder::ClassBuilder(std::string path)
    : CodeBuilder(path)
{
}
ClassBuilder::~ClassBuilder()
{
}

void ClassBuilder::parse_document()
{
    //PREPARING DOCUMENT
    //Converting datatype from string to const char*
    std::string s = this->get_file_path();
    const char* xml_in = s.c_str();
    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> * root_node = nullptr;
    std::ifstream file (xml_in);

    if (file.is_open()){   
        
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
                this->class_vector.push_back(class_node->first_attribute("Name")->value());       
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