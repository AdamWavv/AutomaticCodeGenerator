#include "../include/classBuilder.h"

ClassBuilder::ClassBuilder(std::string path): xml_file_path(path)
{
}
void ClassBuilder::set_XML_file_path(std::string new_XML_file_path){xml_file_path=new_XML_file_path;}

std::string ClassBuilder::get_XML_file_path(){return xml_file_path;}

void ClassBuilder::clear(){
    std::cout<<"dupa";
}




void ClassBuilder::parse_document()
{
    //PREPARING DOCUMENT
    const std::string& xml_in = this->xml_file_path;
    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> * root_node = NULL;
        std::cout << "\nParsing data in: \n" << xml_file_path << "\n ..... \n";
    // Read the xml_in file
    std::ifstream theFile (xml_in);

    if (theFile.is_open())
    {   
        std::cout<<"Dostales sb do pliku\n";
        //Creating buffer to store data from xml file type:CHAR
        std::vector<char> buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
        buffer.push_back('\0');
        doc.parse<0>(&buffer[0]);

        // Find out the root node
        root_node = doc.first_node("Project");
        std::cout<<"Nazwa ROOT NODE to:\n"<<root_node->name()<<"\n";

        std::cout<<"Nazwa PODRZEDNEGO wezla to:\n";
        
        //checking XML files
        char* is_more_layers = strstr(root_node->first_node("Models")->name(), "Models");
        //Founded CLASS node
        if (is_more_layers != nullptr)
        {

            //acces to UML model node
            rapidxml::xml_node<> * models_node = root_node->first_node("Models");
            std::cout << models_node->name() << "\n";

            for (rapidxml::xml_node<> * class_node = models_node->first_node("Class");
                class_node;  
                class_node = class_node->next_sibling())
            {
                std::cout << "Node " << class_node->name() << " Atributes:" << "\n  -" << class_node->first_attribute("Name")->value() <<"\n";
            }
        }
        else
        {   
            //acces to UML model node
            rapidxml::xml_node<> * node = root_node->first_node();
            std::cout << node->name() << "\n";
            rapidxml::xml_node<> * models_node = root_node->first_node("ModelChildren");
            std::cout<< "here should be MODEL CHILDREN and ther is =" << models_node->name() << "\n";

            for (rapidxml::xml_node<> * class_node = models_node->first_node()->first_node("Class");
                class_node;  
                class_node = class_node->next_sibling())
            {
                std::cout << "Node " << class_node->name() << " Atributes:" << "\n  -" << class_node->first_attribute("Name")->value() <<"\n";
            }
            // for (rapidxml::xml_node<> * class_node = models_node->first_node("Class");
            //     class_node;  
            //     class_node = class_node->next_sibling())
            // {
            //     std::cout << "Node " << class_node->name() << " Atributes:" << "\n  -" << class_node->first_attribute("Name")->value() <<"\n";
            // }
        }

        
        

            
    }
}  
//     rapidxml::xml_node<> * models_node = root_node->first_node()->next_sibling("Models");

//     // Iterate over the student nodes
//     for (rapidxml::xml_node<> * models_node = root_node->first_node("Models");
//                                 models_node; models_node = models_node->next_sibling())
//     {
//         std::cout << "\n Class Name =   " <<
//                 models_node->first_attribute("Name")->value();
//         std::cout << "\n";
            
//         // Interate over the Student Names
//         for(rapidxml::xml_node<> * class_name_node = models_node->first_node("Name");
//                 class_name_node; class_name_node = class_name_node->next_sibling())
//         {
//             std::cout << "Class Name =   " << class_name_node->value();
//             std::cout << "\n";
//         }
//         std::cout << "\n";
//     }
// }