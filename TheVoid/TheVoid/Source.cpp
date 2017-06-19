#include <iostream>

int mult(const unsigned int& a, const unsigned int& b) {
	int resultado = 0;

	if (a == 0 || b == 0)
		std::cout << 0 << "\n";

	else if (a > b) {
		for (int i = 1; i <= b; i++)
		{
			resultado += a;
			if (a < 0)
				resultado -= a;
			else if (b < 0)
			resultado -= b;
			std::cout << resultado << "\n";
		}
	}
	else if(a < b)
	{
		for (int i = 1; i <= a; i++)
		{
			resultado += b;
			std::cout << resultado << "\n";
		}
	}
	return 0;
}

void main() {
	int a, b;
	std::cin >> a;
	std::cin >> b;
	mult(a, b);
	system("Pause");
}