#include "../include/methodBuilder.hpp"

MethodBuilder::MethodBuilder(std::string path)
    : CodeBuilder(path)
{
}

MethodBuilder::~MethodBuilder()
{
}


std::string MethodBuilder::generateCode(){

    std::vector<std::string> &vec = this->method_vector;
    std::string code;
    code += "\n";
    for (const auto& attr : vec)
    {
        code += "    def get_" + attr + "(self):\n";
        code += "        return self." + attr + "\n";
        code += "    def set_" + attr + "(self, value):\n";
        code += "        self." + attr + " = value\n";
        code += "\n";
    }
    return code;
}
void MethodBuilder::parse_document()
{
    //PREPARING DOCUMENT
    //Converting datatype from string to const char*
    std::string s = this->get_file_path();
    const char* xml_in = s.c_str();
    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> * root_node = nullptr;
    std::ifstream file (xml_in);

    std::cout << "\nParsing data in: \n" << xml_in << "\n ..... \n";
    if (file.is_open()){   
        
        //Creating buffer to store data from xml file type:CHAR
        std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        buffer.push_back('\0');
        doc.parse<0>(&buffer[0]);
        const char* searched_node_name = "Class";
        if(search_node(xml_in,"Class")->value()){   
            rapidxml::xml_node<> * bufor = search_node(xml_in,"Class");
            bufor = bufor->first_node("ModelChildren");   
            
            for(rapidxml::xml_node<> * attribute_node = bufor->first_node("Operation");
                attribute_node;  
                attribute_node = attribute_node->next_sibling("Operation"))
            {   
                this->attribute_vector.push_back(attribute_node->first_attribute("Name")->value());       
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