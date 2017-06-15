#include <iostream>
#include <vector>

std::vector<int> vectorBin;
void crearVector() {
	vectorBin.push_back(1);
	vectorBin.push_back(2);
	vectorBin.push_back(9);
	vectorBin.push_back(13);
	vectorBin.push_back(20);
	vectorBin.push_back(24);
	vectorBin.push_back(27);
	vectorBin.push_back(50);
}

int busquedaBinaria(const std::vector<int>& v, const int numero) {

	int ls = v.size() - 1;
	int li = 0;
	int bsqNum = (ls - li) / 2;
	while (ls >= li) {
		if (v.at(bsqNum) == numero) {
			std::cout << "El indice de el numero que buscas es: " << bsqNum;
			return bsqNum;
		}
		if (numero > v.at(bsqNum)) {
			li = bsqNum;
			int c = (ls - li) / 2;
			bsqNum = c + li;
			if (c == 0) {
				bsqNum += 1;
			}
			else if (c == 2) {
				bsqNum -= 1;
			}
		}
		else {
			ls = bsqNum;
			bsqNum = (ls - li) / 2 - li;
		}
		if (bsqNum < 0) {
			std::cout << "El numero que buscas no esta en este vector " << bsqNum;
			return -1;
		}
		else if (bsqNum > 7) {
			std::cout << "El numero que buscas no esta en este vector " << bsqNum;
			return -1;
		} 

	}
	return -1;
}

void main() {
	int num;
	std::cin >> num;
	crearVector();
	busquedaBinaria(vectorBin, num);
	std::cout << "\n";
	system("Pause");
}