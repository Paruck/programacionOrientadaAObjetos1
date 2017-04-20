#include <iostream>

using namespace std;
void main() {
	int i = 10;
	int j = 1;
	int x = 10;
	 
	//Se ejecuta de Izquierda a derecha, el “OR” se detiene cuando encuentra un true, y el “&&” se detiene cuando encuentra un false.
		if (i != 10 && j != 1 || i == 10 && x == 10) {
			cout << " Hola" << endl;
			x++;
			j++;
		}
	system("PAUSE");
}