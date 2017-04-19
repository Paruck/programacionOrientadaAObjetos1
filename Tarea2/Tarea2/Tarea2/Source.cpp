#include <iostream>

char texto[] = "anita lava la tina";

bool isPalidrom(char *texto, int lenght) {

	int i = 0, j = lenght - 1;
	while (texto[i] == texto[j] && i++ < j--) {
		if (texto[i] == ' ') { ++i; }
		if (texto[j] == ' ') { --j; }
	}
	return(i >= j) ? true : false;
}
void main() {
	std::cout << isPalidrom(texto, 18) << std::endl;
	system("PAUSE");
}