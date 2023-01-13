#include "../include/methodBuilder.hpp"

MethodBuilder::MethodBuilder(std::string path)
    : CodeBuilder(path)
{
}

MethodBuilder::~MethodBuilder()
{
}

std::unordered_map<std::string, std::vector<std::string>> MethodBuilder::get_method_map(){
    return method_map;
}

std::string MethodBuilder::generateCode(){

    std::string code = "";
    code += "\n";

    for (const auto& [key, values] : this->method_map){
        std::cout << key << ":" << std::endl;
        for (auto& v : values){
            
            // std::replace(v.begin(), v.end(), ' ', '_');
            const auto target = std::regex{ " " };
            const auto replacement = std::string{ "_" };
            std::string method = std::regex_replace(v, target, replacement);
            std::cout << "POWINNO BYC ZMIENIONE !!! " << method << "\n";

            code += "    def get_" + method + "(self):\n";
            code += "        return self." + method + "\n";
            code += "    def set_" + method + "(self, value):\n";
            code += "        self." + method + " = value\n";
            code += "\n";
        }
        
    }
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
                
                this->method_map.insert(std::pair<std::string, std::vector <std::string>>(class_node->first_attribute("Name")->value(), method_vector));
                std::cout << "Methods: " << "\n";
                for (const auto& [key, values] : this->method_map){
                    std::cout << key << ":" << std::endl;
                    for (const auto& value : values) {
                        std::cout << "  " << value << std::endl;
                    }
                }
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