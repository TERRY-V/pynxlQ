#include "../common/qglobal.h"
#include "../common/tinyxml2.h"

using namespace niu;
using namespace tinyxml2;

int parseXML()
{
	XMLDocument doc;
	doc.Parse("<?xml version=\"1.0\" encoding=\"UTF-8\"?>" \
			"<doc>" \
			"	<!-- 刘德华的个人相关信息 -->" \
			"	<base>" \
			"		<chinese pid=\"\" sex='male'>刘德华</chinese>" \
			"		<english><![CDATA[liudehua]]></english>" \
			"		<birth>1954-03-02</birth>" \
			"	</base>" \
			"	<! 刘德华的个人相关信息>" \
			"	<relationship>" \
			"		<relation>" \
			"			<name>曾志伟</name>" \
			"			<rela>朋友</rela>" \
			"		</relation>" \
			"		<relation>" \
			"			<name>朱丽倩</name>" \
			"			<rela>夫妻</rela>" \
			"		</relation>" \
			"		<relation>" \
			"			<name>张学友</name>" \
			"			<rela>朋友</rela>" \
			"		</relation>" \
			"	</relationship>" \
			"</doc>");
	if(doc.Error()) {
		Q_INFO("XML parse error = (%s)", doc.GetErrorStr1());
		Q_INFO("XML parse error = (%s)", doc.GetErrorStr2());
		Q_INFO("XML parse error = (%s)", doc.ErrorName());
		doc.PrintError();
		return -1;
	} else {
		Q_INFO("XML parse success!");
	}

	XMLElement* rootElement=doc.RootElement();
	Q_CHECK_PTR(rootElement);

	XMLElement* baseElement=rootElement->FirstChildElement();
	Q_CHECK_PTR(baseElement);

	XMLElement* chineseElement=baseElement->FirstChildElement();
	Q_INFO("TAG = (%s), TEXT = (%s)", chineseElement->Name(), chineseElement->GetText());

	const XMLAttribute* pidAttribute=chineseElement->FirstAttribute();
	Q_INFO("TAG = (%s), TEXT = (%s)", pidAttribute->Name(), pidAttribute->Value());

	Q_INFO("TAG = (%s), TEXT = (%s)", "sex", chineseElement->Attribute("sexs"));

	XMLElement* engElement=chineseElement->NextSiblingElement();
	Q_INFO("TAG = (%s), TEXT = (%s)", engElement->Name(), engElement->GetText());

	XMLElement* birthElement=baseElement->FirstChildElement("birth");
	Q_INFO("TAG = (%s), TEXT = (%s)", birthElement->Name(), birthElement->GetText());

	XMLElement* relationshipElement=baseElement->NextSiblingElement();
	Q_CHECK_PTR(relationshipElement);

	XMLElement* relationElement=relationshipElement->FirstChildElement();
	Q_CHECK_PTR(relationElement);

	while(relationElement) {
		XMLElement* nameElement=relationElement->FirstChildElement();
		Q_INFO("TAG = (%s), TEXT = (%s)", nameElement->Name(), nameElement->GetText());

		XMLElement* relaElement=nameElement->NextSiblingElement();
		Q_INFO("TAG = (%s), TEXT = (%s)", relaElement->Name(), relaElement->GetText());

		relationElement=relationElement->NextSiblingElement();
	}

	return 0;
}

int createXML()
{
	XMLDocument doc;

#if 1
	XMLDeclaration* dec=doc.NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\"");
	Q_CHECK_PTR(dec);
	doc.LinkEndChild(dec);
#endif

	XMLElement* rootElement=doc.NewElement("doc");
	Q_CHECK_PTR(rootElement);
	doc.LinkEndChild(rootElement);

	XMLElement* subElement=doc.NewElement("sub");
	Q_CHECK_PTR(subElement);
	rootElement->LinkEndChild(subElement);

	XMLElement* nameElement=doc.NewElement("name");
	Q_CHECK_PTR(nameElement);
	subElement->LinkEndChild(nameElement);

	nameElement->LinkEndChild(doc.NewText("张柏芝"));
	nameElement->SetAttribute("pid", "2");
	nameElement->SetAttribute("age", "38");

	XMLElement* sexElement=doc.NewElement("sex");
	Q_CHECK_PTR(sexElement);
	subElement->LinkEndChild(sexElement);

	sexElement->LinkEndChild(doc.NewText("female"));

	return 0;
}

void testXML()
{
	XMLDocument doc;
	char buf[1<<20]={0};
	int len=0;

	FILE*fp=fopen("sss.xml", "rb");
	len=q_get_file_size("sss.xml");
	fread(buf, len, 1, fp);
	fclose(fp);

	doc.Parse(buf, len);
	if(doc.Error()) {
		Q_INFO("XML parse error = (%s)", doc.GetErrorStr1());
		Q_INFO("XML parse error = (%s)", doc.GetErrorStr2());
		Q_INFO("XML parse error = (%s)", doc.ErrorName());
		doc.PrintError();
	} else {
		Q_INFO("XML parse success!");
	}
}

int main(int argc, char** argv)
{
	//parseXML();
	//createXML();
	testXML();
	return EXIT_SUCCESS;
}
