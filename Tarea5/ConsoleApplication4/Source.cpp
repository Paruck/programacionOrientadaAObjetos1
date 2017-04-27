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
	//Asi, imprime todos los valores de los nodos.
	cout << pTemp->value << endl;
}
//	

// Esta es funcion de imprimir, la cual solo me imprime las direcciones de memoria :(, por eso deje la linea de arriba que si lo hacia bien.
//void print() {
//	for (int i = 0; i < 6; i++) {
//		Node *temp = new Node();
//		temp->next = pHead;
//		temp->value = pHead->value;
//		pHead = temp;
//		cout << temp << endl;
//	}
//}


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

	//print();
	system("PAUSE");
	return 0;
}
