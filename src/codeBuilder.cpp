#include "../include/codeBuilder.h"


CodeBuilder::CodeBuilder(std::string path): xml_file_path(path)
{
}

void CodeBuilder::set_XML_file_path(std::string new_XML_file_path){
    this->xml_file_path = new_XML_file_path;
}


std::string CodeBuilder::get_XML_file_path(){
    return xml_file_path;
}

void CodeBuilder::clear(){
    this->xml_file_path = nullptr;
}

rapidxml::xml_node<>* get_node(const std::string file_path, const char* node_name)
{
    //PREPARING DOCUMENT
    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> * root_node = NULL;
    // Read the xml_in file
    std::ifstream theFile (file_path);

    std::cout << "\nParsing data in: \n" << file_path << "\n ..... \n";

    //Creating buffer to store data from xml file type:CHAR
    std::vector<char> buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');
    doc.parse<0>(&buffer[0]);

    // // Find out the root node
    const char* root_node_name = "Project";
    root_node = doc.first_node(root_node_name);

    //acces to UML model data
    rapidxml::xml_node<> * model_node = root_node->first_node("Models");
    std::cout <<"Adres " <<model_node
            << " Zawiera w sobie:" 
            << model_node->name() << "\n";
    
    
    if (model_node->first_node("Model"))
    {
        model_node = model_node->first_node("Model")->first_node("ModelChildren");   
    }
    std::cout <<"Adres " 
    <<model_node->first_node() 
    << " Zawiera w sobie:" 
    << model_node->name() << "\n";

    return model_node->first_node(node_name);
}

void CodeBuilder::parse_document()
{
    //PREPARING DOCUMENT
    //Converting datatype from string to const char*
    std::string s = this->xml_file_path;
    const char* xml_in = s.c_str();

    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> * root_node = NULL;
    // Read the xml_in file
    std::ifstream theFile (xml_in);

    std::cout << "\nParsing data in: \n" << xml_in << "\n ..... \n";

    if (theFile.is_open())
    {   
        //Creating buffer to store data from xml file type:CHAR
        std::vector<char> buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
        buffer.push_back('\0');
        doc.parse<0>(&buffer[0]);

        rapidxml::xml_node<> * model_node = get_node(xml_in,"Class");

        for(rapidxml::xml_node<> * class_node = model_node->first_node("Class");
            class_node;  
            class_node = class_node->next_sibling())
        {
            std::cout << "Node " << class_node->name() << " Atributes:" << "\n  -" << class_node->first_attribute("Name")->value() <<"\n";
        }
        
    }
    std::cout << "\n \n";
}  
