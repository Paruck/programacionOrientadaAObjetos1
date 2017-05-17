#pragma once
#include "Node.h"
class DLList {
private:
	Node *_head, *_tail;
public:
	void insert(const int &v);
	void deleteAll();
	void print();
	DLList();
};
