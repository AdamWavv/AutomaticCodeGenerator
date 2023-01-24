#include "../include/methodBuilder.hpp"

MethodBuilder::MethodBuilder(std::string path)
    : CodeBuilder(path)
{
}

MethodBuilder::~MethodBuilder()
{
}
std::string MethodBuilder::generateCode(std::string class_name){
    //Converting data with spaces to underscores and put them to method declaration
    //Create methods segment of code
    std::string code = "";
    code += "\n";
    std::vector<std::string> values = this->method_map[class_name];    
    for (auto& v : values){
        
        const auto target = std::regex{ " " };
        const auto replacement = std::string{ "_" };
        std::string method = std::regex_replace(v, target, replacement);
        code += "\tdef get_" + method + "(self):\n";
        code += "\t\treturn self." + method + "\n";
    }
    code += "\n";
    for (auto& v : values){
        //Change space into underscore
        const auto target = std::regex{ " " };
        const auto replacement = std::string{ "_" };
        std::string method = std::regex_replace(v, target, replacement);
        code += "\tdef set_" + method + "(self, value):\n";
        code += "\t\tself." + method + " = value\n";
        
    }
    code += "\n";  
    
    std::cout<<code <<"\n";

    return code;
}
void MethodBuilder::parse_document(){
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
                std::cout << class_node->first_attribute("Name")->value() << ": \n";

                rapidxml::xml_node<> * bufor = class_node;
                bufor = bufor->first_node("ModelChildren");
                std::vector<std::string> method_vector;

                for(rapidxml::xml_node<> * method_node = bufor->first_node("Operation");
                method_node;
                method_node = method_node->next_sibling("Operation"))
                {   
                    method_vector.push_back(method_node->first_attribute("Name")->value()); 
                    std::cout << " -" << method_node->first_attribute("Name")->value() << "\n";
                }
                //Write data from XML file to unordered_map
                this->method_map.insert(std::pair<std::string, std::vector <std::string>>(class_node->first_attribute("Name")->value(), method_vector));
                method_vector.clear();
                
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