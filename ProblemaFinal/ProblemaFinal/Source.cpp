#include <iostream>

char numberArray[4096];

void pushNumbers() {

	while (true)
	{
		int indexArray, numero;
		std::cout << "Introduce los numeros que quieras meter al Array, cuando quieras terminar, mete un numero negativo. \n";
		std::cin >> numero;
		if (numero < 0)
			break;
		else
		numero -= 1;
		indexArray = numero / 8;
		numero = numero % 8;
		numberArray[indexArray] = numberArray[indexArray] | (1 << (numero));
	}
}

void searchNumbers() {
	while (true)
	{
		int indexArray, numero;
		std::cout << "Introduce el numero que quieres buscar dentro del array, cuando decidas terminar, introduce un numero negativo. \n";
		std::cin >> numero;
		if (numero < 0)
			break;
		else
		numero -= 1;
		indexArray = numero / 8;
		numero = numero % 8;
		if ((numberArray[indexArray] & (1 << (numero))))
			std::cout << "El numero si esta dentro del Array.\n";
		else
			std::cout << "El numero no esta dentro del Array.\n";
	}
}

int main()
{
	pushNumbers();
	searchNumbers();
	system("Pause");
	return 0;
}