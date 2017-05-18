#include "Arbol.h"
#include <iostream>

Arbol::Arbol():root(nullptr)
{}

void Arbol::Insert(const int &v, Node * & root, Node* parent) {
	if (root == nullptr){
		root = new Node(v,parent);
		return;
	}
	
	else if (v < root->value) Insert( v, (root->l), root);
	else Insert(v, (root->r), root);
}

void Arbol::Print(Node* root)
{
	if (root != nullptr) {
		Print(root->r);
		std::cout << *root << "\n";
		Print(root->l);
	}
}

void Arbol::PrintBackwards( Node* root)
{
	if (root != nullptr) {
		PrintBackwards(root->l);
		std::cout << *root << "\n";
		PrintBackwards(root->r);
	}
}

