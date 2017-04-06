#include <iostream>

int main() {
	int suma;
	int y = 0;
	for (int x = 0; x < 10; ++x) {
		suma = x + y;
		std::cout << "El valor de la suma es igual a : " << suma << std::endl;

		if (++x) {
			std::cout << "El valor de X es igual a : "<< x << std::endl;
		}

	}
	system("PAUSE");
		
	return 0;
}
