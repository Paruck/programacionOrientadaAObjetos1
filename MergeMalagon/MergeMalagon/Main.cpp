#include <iostream>
#include <vector>
#include "Merge.h"
void main() {
	Merge m;
	std::vector<int> vector1, vector2, vectorFinal;
	m.creadorDeVectores(vector1, vector2);
	m.mergeSort(vector1, vector2, vectorFinal);
	system("Pause");
}