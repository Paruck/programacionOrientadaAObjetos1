#include "DLList.h"
#include <iostream>
DLList::DLList():_head(nullptr),_tail(nullptr)
{}

void DLList::insert(const int &v) {
	Node *nuevo = new Node();
	nuevo->value = v;
	std::cout << nuevo->value << "\n";
	if (_head == nullptr){
		_head = nuevo;
		_tail = nuevo;
		return;
	}

	nuevo->prev = _tail;
	_tail->next = nuevo;
	_tail = nuevo;
}

void DLList::deleteAll() {
	if (_head == nullptr)
		return;
	Node *pTemp = _head;
	while (_head)
	{
		_head = _head->next;
		delete pTemp;
	}
}

void DLList::print() {
	if (_head == nullptr)
		return;
	Node *pTemp = _head->next;
	while (_head)
	{
		_head = _head->next;
		std::cout<<pTemp->value;
	}
}

static void ShallowCopy(Node* &valor1, Node* const &valor2){
	valor1 = valor2;
}

