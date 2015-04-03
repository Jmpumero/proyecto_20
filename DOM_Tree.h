#ifndef DOM_Tree_H
#define DOM_Tree_H

#include <iostream>
#include "Node.h"

template <class T>
class DOM_Tree
{
	private:
		Node<Element> *raiz;
		int longitud;
		
		static Node<Element>* copiarNodos(Node<Element> *copia);
	
	public:
		DOM_Tree();
		DOM_Tree(Element r,const list<DOM_Tree> &l);
		
		void copiar(DOM_Tree a);
		
	
	
};

template <class T>
DOM_Tree<T> ::DOM_Tree()
{
	raiz = NULL;
	longitud = 0;
}


template <class T>
DOM_Tree<T> ::DOM_Tree(Element r,const list<DOM_Tree <T> > &l)
{
	DOM_Tree< Node<Element> > ArbolAux;
	Node<Element> *aux;
		raiz=new Node<Element>(r);
		longitud=1;
		if(!l.empty())
		{
			ArbolAux.copiar(l.front());
			raiz->setFirstChild(ArbolAux.raiz);
			longitud= longitud + ArbolAux.longitud;
			aux=raiz->firstChild();
			l.pop_front();
			while(!l.empty())
			{
				ArbolAux.copiar(l.front());
				l.pop_front();
				aux->setNextSibling(ArbolAux.raiz);
				longitud= longitud + ArbolAux.longitud;
				aux=aux->nextSibling();
			}
		}	
		ArbolAux.raiz=NULL;
}


template <class T>
void DOM_Tree<T>::copiar(DOM_Tree<T> a)
{
	Node<Element> *nuevo,*hi;
	if(a.raiz != NULL)
	{
		hi=copiarNodos(a.raiz->firstChild());
		nuevo=new Node<Element>(a.raiz->element(),hi,NULL);
	}else
		nuevo=NULL;
	raiz=nuevo;
	longitud=a.longitud;
}


template <class T>
Node<Element>* DOM_Tree<T>::copiarNodos(Node<Element> *copia)
{
	Node<Element> *aux;
	if(copia==NULL)
	{
		aux=NULL;
	}else{
			aux = new Node<Element>(copia->element(),copiarNodos(copia->firstChild()),copiarNodos(copia->nextSibling()));
	}
	return(aux);
}






#endif
