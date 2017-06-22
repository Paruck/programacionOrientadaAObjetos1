#include <iostream>
#include <string>
#include <vector>
void convertToString(const int numero) {
	std::string convertFinal = "";

	int numTemp = numero;
	int temporal2 = numero;

	while (true) {
			numTemp = numTemp % 10;
			(numTemp >= 0) ? numTemp : numTemp*=-1;
			numTemp += 48;
			convertFinal += numTemp;
			temporal2 = temporal2 / 10;
			numTemp = temporal2;
		if (temporal2 == NULL) {
			break;
		}
	}
	for (int i = convertFinal.size(); i >= 0; i--)
		std::cout << convertFinal[i];

}

void main() {
	int numero;
	std::cin >> numero;
	convertToString(numero);
	std::cout << "\n";
	system("Pause");
}