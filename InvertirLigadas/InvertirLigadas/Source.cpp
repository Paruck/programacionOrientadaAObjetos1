#include <iostream>


typedef struct Node {
	int value;
	Node *next;

} Node ;

Node *head = nullptr;

void insert(const int &v) {
	Node*pTemp = new Node();
	pTemp->value = v;
	pTemp->next = head;
	head = pTemp;
}

void revertList(Node **head) {
	     Node *Htemp = NULL;
		 Node *temp = NULL;
		 while (*head != NULL)
		 {
			 temp = *head;
			 *head = (*head)->next;
			 temp->next = Htemp;
			 Htemp = temp;
		 }
		 *head = Htemp;
}

void print() {
	Node *temp = head;
	while (temp != NULL) {
		std::cout << temp->value<< "\n";
		temp = temp->next;
	}
}

void main() {
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	insert(7);
	insert(8);
	insert(9);
	revertList(&head);
	print();
	system("Pause");


}