#include <iostream>
#include <string>

using namespace std;

typedef struct  Node
{
	string value;
	Node *next;
} Node ;

Node *pHead = NULL;

void insert(const string &v) {

	Node *pTemp = new Node();
	pTemp->value = v;
	pTemp -> next = pHead;
	pHead = pTemp;
	//Si descomenta esta linea, imprime los valores sin nuingun problema y comenta la funcion 
	/*cout << pTemp->value << endl;*/
}
//	

void print() {
	for (int i = 0; i < 6; i++) {
		Node *temp = new Node();
		temp->next = pHead;
		temp->value = pHead->value;
		pHead = temp;
		cout << temp << endl;
	}
}


int main()
{
	insert("a");
	insert("b");
	insert("c");
	insert("a");
	insert("b");
	insert("c");


	print();
	system("PAUSE");
	return 0;
}