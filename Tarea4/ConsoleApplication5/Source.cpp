#include <iostream>

using namespace std;
int arreglo[32];
int convertidorDeBits(int n, int *arreglo) {

	while(n != 0)
	for (int i = 0; i <= 32; i++) {
		if ((n % 2 == 0)) { arreglo[i] = 0; }
		else { arreglo[i] = 1; }
		n = n / 2;
	}
	return n;
}

void main() {
	cout << "Introduce el numero que quieres convertir a Binario \n" << endl;
	int n;
	cin >> n;
	convertidorDeBits(n, arreglo);
	for (int i = 0; i < 32; ++i) {
		cout << arreglo[i];
	}
	cout << "\n" << endl;
	for (int y = 0; y <= 33; y++) {
		cout << "Que numero de Bit quieres comprobar si esta encendido \n" << endl;
		int x;
		cin >> x;
		if (arreglo[x] == 0) {
			arreglo[x] = 1;
		}

		for (int i = 0; i < 32; ++i) {
			cout << arreglo[i];
		}
		cout << "\n" << endl;
	}
	system("Pause");
}
