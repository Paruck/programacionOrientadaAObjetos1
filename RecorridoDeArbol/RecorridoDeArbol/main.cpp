#include <iostream>
#include "Arbol.h"

void main() {
	Arbol l;
	Node *root = nullptr;
	l.Insert(5, root);
	l.Insert(10, root);
	l.Insert(7, root);
	l.Insert(3, root);
	l.Insert(9, root);
	l.Insert(12, root);
	l.Print(root);
	std::cout << "Ahora se imprime el arbol binario en orden inverso\n";
	l.PrintBackwards(root);
	
	
	system("PAUSE");

}