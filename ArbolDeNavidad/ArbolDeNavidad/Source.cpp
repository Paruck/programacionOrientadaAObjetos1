#include <iostream>

void arbolNav(const int size) {
	for (int i = 0; i <= size; i++) {
		int asteriscos = i + i - i;
		std::cout << "\n";
		for(int x = size; x >= asteriscos; x--)
			std::cout << " ";
		for (int a = 0; a <= asteriscos; a++)
			std::cout << "*";
		for (int x = 1; x <= asteriscos; x++)
			std::cout << "*";
	}
}

//void arbolRevert(const int size ) {
//	for (int i = 0; i <= size; i++) {
//		int asteriscos = i + i - i;
//		std::cout << "*\n";
//		for (int x = size; x >= 0; x--) {
//			std::cout << " ";
//			for (int x = size; i >= 0; i--)
//				std::cout << "*\n";
//		}
//		/*for (int a = 0; a <= asteriscos; a++)
//		std::cout << "*";*/
//	/*	for (int x = 0; x <= size; x++)
//		std::cout << " ";
//		for (int a = size; a >= asteriscos; a--)
//		std::cout << "*";*/
//	}
//}

void main() {
	int n;
	std::cin >> n;
	arbolNav(n);
	std::cout << "\n";
	system("Pause");
}