#pragma once
#include <vector>
class Merge
{
private:
	std::vector <int> vectorFinal;

	int i, j;
public:
	void creadorDeVectores(std::vector<int>& v1, std::vector<int>& v2);
	void mergeSort(const std::vector<int>& v1, const std::vector<int>& v2, std::vector <int>& vectorFinal);
	Merge();
};

