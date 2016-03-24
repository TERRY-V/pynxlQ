#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <sys/stat.h>
#include "tinyxml2.h"

using namespace tinyxml2;

int main(int argc, char **argv)
{
	XMLDocument doc;
	doc.LoadFile("./dataInfoXml.xml");
	if(doc.ErrorID()) {
		printf("File loading error......");
		return -1;
	}

	doc.Print();

	XMLElement* annidElement=doc.FirstChildElement("datainfo") \
				 ->FirstChildElement("anninfo") \
				 ->FirstChildElement("annid");
	const XMLAttribute* annidAttr=annidElement->FirstAttribute();
	printf("\n%s: %s\n", annidAttr->Value(), annidElement->GetText());

	XMLElement* anntitleElement=annidElement->NextSiblingElement();
	const XMLAttribute* anntitleAttr=anntitleElement->FirstAttribute();
	printf("%s: %s\n", anntitleAttr->Value(), anntitleElement->GetText());

	XMLElement* companyElement=doc.FirstChildElement("datainfo") \
				   ->FirstChildElement("project") \
				   ->FirstChildElement("company");
	const XMLAttribute* companyAttr=companyElement->FirstAttribute();
	printf("%s: %s\n", companyAttr->Value(), companyElement->GetText());

	XMLElement* objectElement=companyElement->NextSiblingElement();
	const XMLAttribute* objectAttr=objectElement->FirstAttribute();
	printf("%s: %s\n", objectAttr->Value(), objectElement->GetText());

	XMLElement* serviceElement=objectElement->NextSiblingElement();
	const XMLAttribute* serviceAttr=serviceElement->FirstAttribute();
	printf("%s: %s\n", serviceAttr->Value(), serviceElement->GetText());

	XMLElement* anntypeElement=serviceElement->NextSiblingElement();
	const XMLAttribute* anntypeAttr=anntypeElement->FirstAttribute();
	printf("%s: %s\n", anntypeAttr->Value(), anntypeElement->GetText());

	return 0;
}
