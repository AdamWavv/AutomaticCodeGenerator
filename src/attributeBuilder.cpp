#include "../include/attributeBuilder.hpp"

AttributeBuilder::AttributeBuilder(std::string path)
    : CodeBuilder(path)
{
}
AttributeBuilder::~AttributeBuilder()
{
}

std::unordered_map<std::string, std::vector<std::string>> AttributeBuilder::get_attribute_map(){
    return attribute_map;
}

std::string AttributeBuilder::generateCode(std::string class_name){

    std::vector<std::string> &vec = this->attribute_map[class_name];
    std::string code;

    code += "    def __init__(self):\n";
    for (const auto& attr : vec)
    {
        code += "        self." + attr + " = None\n";
    }

    return code;
}
void AttributeBuilder::parse_document(){
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

        std::cout << "Parsing data in file path: " << "\n" << "........" << "\n" << s << "\n";

        if(search_node(xml_in,"Class")->value()){   
            
            for(rapidxml::xml_node<> * class_node = search_node(xml_in,"Class");
            class_node;  
            class_node = class_node->next_sibling("Class"))
            {   
                //std::cout << class_node->first_attribute("Name")->value() << ": \n";

                rapidxml::xml_node<> * bufor = class_node;
                bufor = bufor->first_node("ModelChildren");
                std::vector<std::string> attribute_vector;

                for(rapidxml::xml_node<> * attribute_node = bufor->first_node("Attribute");
                attribute_node;
                attribute_node = attribute_node->next_sibling("Attribute"))
                {   
                    attribute_vector.push_back(attribute_node->first_attribute("Name")->value()); 
                }
                
                this->attribute_map.insert(std::pair<std::string, std::vector <std::string>>(class_node->first_attribute("Name")->value(), attribute_vector));
                std::cout << "Attributes: " << "\n";
                for (const auto [key, values] : this->attribute_map){
                    std::cout << key << ":" << std::endl;
                    for (const auto& value : values) {
                        std::cout << "  " << value << std::endl;
                    }
                }
                attribute_vector.clear();
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