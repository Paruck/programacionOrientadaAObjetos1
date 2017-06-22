#include <iostream>
#include <string>

using namespace std;

typedef struct  Node
{
	string value;
	Node *next;
} Node ;

Node *pHead = NULL;

void printNodes(const string &v) {

	Node *pTemp = new Node();
	pTemp->value = v;
	pTemp -> next = pHead;
	pHead = pTemp;
}
void print() {
	if (pHead == nullptr)
		return;
	Node *pTemp = pHead;
	while (pHead)
	{
		pHead = pHead->next;
		std::cout<<pTemp->value;
	}
}

int main()
{
	insert("a");
	insert("b");
	insert("c");
	insert("d");
	insert("e");
	insert("f");
        insert("g");
	insert("h");
	insert("i");

	system("PAUSE");
	return 0;
}
