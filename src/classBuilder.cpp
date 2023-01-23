#include "../include/classBuilder.hpp"

ClassBuilder::ClassBuilder(std::string path)
    : CodeBuilder(path)
{
}
ClassBuilder::~ClassBuilder()
{
}
std::string ClassBuilder::generateCode(std::string class_name){

    const std::string file = this->get_file_path();
    this->parse_document();

    std::vector<std::string> &vec = this->class_vector;
    std::string code = "";
    AttributeBuilder ab(file);
    MethodBuilder mb(file);

    ab.parse_document();
    mb.parse_document();

    code += "\n";

    for (const auto& class_name: class_vector)
    {
        code += "class" +  class_name + ":\n";
        code += ab.generateCode(class_name);
        std::cout << ab.generateCode(class_name);
        code += mb.generateCode(class_name);
        std::cout << code;
    }
    
    return code;
}