#include "../include/classBuilder.h"

ClassBuilder::ClassBuilder(std::string path): xml_file_path(path)
{
}
void ClassBuilder::set_XML_file_path(std::string new_XML_file_path){xml_file_path=new_XML_file_path;}

std::string ClassBuilder::get_XML_file_path(){return xml_file_path;}

void ClassBuilder::clear(){
    std::cout<<"dupa";
}

void parse_document()
{
    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> * root_node = NULL;
   
    std::cout << "\nParsing my students data (sample.xml)....." << endl;
   
    // Read the sample.xml file
    std::ifstream theFile ("sample.xml");
    std::vector<char> buffer((std::istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');
   
    // Parse the buffer
    doc.parse<0>(&buffer[0]);
   
    // Find out the root node
    root_node = doc.first_node("MyStudentsData");
   
    // Iterate over the student nodes
    for (xml_node<> * student_node = root_node->first_node("Student");
                student_node; student_node = student_node->next_sibling())
    {
        std::cout << "\nStudent Type =   " <<
                student_node->first_attribute("student_type")->value();
        std::cout << endl;
           
            // Interate over the Student Names
        for(xml_node<> * student_name_node = student_node->first_node("Name");
                student_name_node; student_name_node = student_name_node->next_sibling())
        {
            std::cout << "Student Name =   " << student_name_node->value();
            std::cout << endl;
        }
        std::cout << endl;
    }
}
