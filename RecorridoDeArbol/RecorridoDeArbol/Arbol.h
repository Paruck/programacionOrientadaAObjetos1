#pragma once
#include "Node.h"

class Arbol{
public:
	Node *root;
	//Apuntador a referencia de memoria.
	void Insert(const int &v, Node * & root, Node* parent = nullptr);
	void Print( Node* root);
	void PrintBackwards( Node* root );

	
	Arbol();
};