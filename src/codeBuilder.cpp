#include "../include/codeBuilder.hpp"


CodeBuilder::CodeBuilder(std::string path)
    : xml_file_path(path)
{
}
CodeBuilder::~CodeBuilder()
{
    clear();
}
void CodeBuilder::set_file_path(std::string new_file_path){
    this->xml_file_path = new_file_path;
}
std::string CodeBuilder::get_file_path(){
    return xml_file_path;
}
std::vector <std::string> CodeBuilder::get_class_vector(){
    return class_vector;
}
std::unordered_map<std::string, std::vector<std::string>> CodeBuilder::get_attribute_map(){
    return attribute_map;
}
std::unordered_map<std::string, std::vector<std::string>> CodeBuilder::get_method_map(){
    return method_map;
}

rapidxml::xml_node<>* CodeBuilder::search_node(const std::string file_path, const char* node_name)
{
    //PREPARING DOCUMENT
    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> * root_node = nullptr;
    rapidxml::xml_node<> * searched_node = nullptr;
    // Read the xml_in file
    std::ifstream file (file_path);

    //Creating buffer to store data from xml file type:CHAR
    std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');
    doc.parse<0>(&buffer[0]);

    root_node = doc.first_node("Project");

    //Minimal required path to data code nodes
    rapidxml::xml_node<> * model_node = root_node->first_node("Models");

    if (model_node->first_node("Model"))
    {
        model_node = model_node->first_node("Model");
        model_node = model_node->first_node("ModelChildren");   
        searched_node = model_node->first_node(node_name);
        file.close();
        
        return searched_node;
    }
    else
    {
        searched_node = model_node->first_node(node_name);
        file.close();

        return searched_node;
    }

}
void CodeBuilder::clear(){
    this->class_vector.clear();
    this->attribute_map.clear();
    this->method_map.clear();
    this->xml_file_path.clear();
}