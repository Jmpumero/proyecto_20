#ifndef Node_H
#define Node_H

#include "Element.h"

template <class Element>
class Node
{
	private:  
		Element elem;
		Node *hijoI,*hermanoD;
	public: 
		///Constructores
		Node();
		Node(Element e);
		Node(Element e,Node<Element>* const hijoIzq,Node<Element>* const hermaD);
		
		///Consultores
		Element element();
		Node<Element>* firstChild();
		Node<Element>* nextSibling();
		
		///Modificadores
		void setElement(Element e);
		void setFirstChild(Node<Element>* const hijoIzq);
		void setNextSibling(Node<Element>* const hermaD);
		

		/*friend std::ostream& operator<<(std::ostream &salida, const Node<Element> &n)
		{
			salida << n.Element->tag;
			return(salida);
		}*/
		
};

///Constructores
template <class Element>
Node<Element>::Node(Element e)
{
	elem.tag = e.tag;
	elem.list_Atributos = e.list_Atributos;
	elem.inner = e.inner;
	hijoI = NULL;
	hermanoD = NULL;
}

template <class Element>
Node<Element>::Node(Element e,Node<Element>* const hijoIzq,Node<Element>* const hermaD)
{
	elem.tag = e.tag;
	elem.list_Atributos = e.list_Atributos;
	elem.inner = e.inner;
	hijoI = hijoIzq;
	hermanoD = hermaD;
}

///Consultores
template <class Element>
Element Node<Element>::element()
{
	return(elem);
}

template <class Element>
Node<Element>* Node<Element>::firstChild()
{
	return(hijoI);
}

template <class Element>
Node<Element>* Node<Element>::nextSibling()
{
	return(hermanoD);
}

template <class Element>
void Node<Element>::setElement(Element e)
{
	elem.tag = e.tag;
	elem.list_Atributos = e.list_Atributos;
	elem.inner = e.inner;
	hijoI = e.hijoI;
	hermanoD = e.hermanoD;
	
}

template <class Element>
void Node<Element>::setFirstChild(Node<Element>* const hijoIzq)
{
	hijoI = hijoIzq;
}

template <class Element>
void Node<Element>::setNextSibling(Node<Element>* const hermaD)
{
	hermanoD = hermaD;
}



#endif
