#pragma
#ifdef XML_HPP
#define XML_HPP

struct XMLDocument
{
    char* path;
};

void XMLDocument_load();
void XMLDocument_free(XMLDocument* doc);

#endif //XML_HPP