#ifndef Element_H_
#define Element_H_

#include <list>
#include <string>

using namespace std; //SE DEBE INCLUIR SOLO EL STD::STRING

class Element
{
	public: ///PRIVATE
		string tag,inner;
		list<string> list_Atributos;
	
	public:
		///Constructores
		Element();
		Element(string tag);
		Element(string tag,const list<string> &atributos,string html);
		///Consultores
		string tagName();
		list<string>& attributeList();
		string innerHTML();
		///Modificadores
		void setTagName(string tag);
		void setAttributeList(const list<string> &atributos);
		void setInnerHTML(string html);
};

/// Constructores
Element::Element()
{

}

Element::Element(string tag)
{
	this->tag = tag;
}

Element::Element(string tag,const list<string> &atributos,string html)
{
	this->tag = tag;
	list_Atributos = atributos;
	inner = html;
}

/// Consultores 
string Element::tagName()
{
	//if(!tag.empty()) pendiente
		return(tag); 
	
}

list<string>& Element::attributeList()
{
	if(!list_Atributos.empty())
		return(list_Atributos);
}

string Element::innerHTML()
{
	if(!inner.empty())
		return(inner);
}

///Modificadores
void Element::setTagName(string tag)
{
	this->tag = tag;
}

void Element::setAttributeList(const list<string> &atributos)
{
	list_Atributos.clear();
	list_Atributos = atributos;
}

void Element::setInnerHTML(string html)
{
	inner = html;
}








#endif
