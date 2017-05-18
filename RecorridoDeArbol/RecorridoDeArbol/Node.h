#pragma once
#include <iostream>
class Node
{
public:
	int value;
	Node *r, *l, *padre;
	Node();
	//Por sintanxis siempre se declara ell costructor copia.
	Node(Node* const& copy);
	Node(const int& val);
	Node(const int& val, Node* const& father);
	friend std::ostream& operator << (std::ostream& lhs, const Node& rhs);
	friend std::istream& operator >> (std::istream & lhs, Node& rhs);
};
