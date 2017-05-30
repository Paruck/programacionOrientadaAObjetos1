#include <iostream>
#include <vector>
std:: vector <int> arreglo;
bool bandera = true;
int ConvertidorDeBases(const int &base, int numero) {
	while (numero != 0) {
		for (int i = 0; i < 32; i++) {
			arreglo.push_back(numero%base);
			numero = numero / base;
		}
	}
	return (numero%base>10)? numero%base + 54: numero%base;

}

void main() {
	int b, n;
	std::cin >> b;
	std::cin >> n;
	ConvertidorDeBases(b, n);
	for (int i = 0; i < arreglo.size(); i++) {
		std::cout << arreglo.at(i);
	}
	std::cout << "\n";
	system("Pause");
}