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
	//Asi, imprime todos los valores de los nodos en orden.
	cout << pTemp->value << endl;
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
