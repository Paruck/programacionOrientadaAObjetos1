#include "Node.h"
Node:: Node():prev(nullptr), next(nullptr)
{}
//Deep Copy.
Node::Node(Node * const & copy) : Node()
{
	this->value = copy->value;
}
