#include "Node.h"

Node::Node(): l(nullptr), r(nullptr), padre(nullptr)
{

}

Node::Node(Node * const & copy) : Node()
{
	this->value = copy->value;
}

Node::Node(const int & val) : Node()
{
	this->value = val;
}
//Concatenacion de constructores.
Node::Node(const int & val, Node * const & father) : Node(val)
{
	padre = father;
}

std::ostream & operator<<(std::ostream & lhs, const Node & rhs)
{
	return lhs << rhs.value;
}

std::istream & operator >> (std::istream & lhs, Node & rhs)
{
	return lhs >> rhs.value;
}
