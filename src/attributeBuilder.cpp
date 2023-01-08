#include "../include/attributeBuilder.hpp"

AttributeBuilder::AttributeBuilder(std::string path)
    : CodeBuilder(path)
{
}
AttributeBuilder::~AttributeBuilder()
{
}

std::string AttributeBuilder::generateCode(){

    std::vector<std::string> &vec = this->attribute_vector;
    std::string code;

    code += "    def __init__(self):\n";
    for (const auto& attr : vec)
    {
        code += "        self." + attr + " = None\n";
    }

    return code;
}

void AttributeBuilder::parse_document()
{
    //PREPARING DOCUMENT TO LOAD DATA FROM XML FILE
    std::string s = this->get_file_path(); //ENCAPSULATION
    const char* xml_in = s.c_str();
    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> * root_node = nullptr;
    std::ifstream file (xml_in);

    if (file.is_open()){   
        
        //Creating buffer to store data from xml file type:CHAR
        std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        buffer.push_back('\0');
        doc.parse<0>(&buffer[0]);
        // const char* searched_node_name = "Class";

        if(search_node(xml_in,"Class")->value()){   
            rapidxml::xml_node<> * bufor = search_node(xml_in,"Class");
            bufor = bufor->first_node("ModelChildren");   
            
            for(rapidxml::xml_node<> * attribute_node = bufor->first_node("Attribute");
                attribute_node;  
                attribute_node = attribute_node->next_sibling("Attribute"))
            {   
                this->attribute_vector.push_back(attribute_node->first_attribute("Name")->value());       
            }
            file.close();
        }
        else{
            std::cout << "WRONG NODE NAME";
            file.close();
        }

    }
    std::cout << "\n \n";  
}