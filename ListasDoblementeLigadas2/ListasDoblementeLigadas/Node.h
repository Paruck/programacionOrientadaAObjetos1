#pragma once

class Node {
public:
	Node *next, *prev;
	int value;
	//Deep Copy
	Node(Node* const& copy);
	Node();
};