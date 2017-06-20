#include "Merge.h"
#include <iostream>

void Merge::creadorDeVectores(std::vector<int>& v1, std::vector<int>& v2)
{
	v1 = {2,4,6,7,9,10};
	v2 = {12,13,15,17};
}

void Merge::mergeSort(const std::vector<int>& v1, const std::vector<int>& v2, std::vector<int>& vectorFinal)
{
	i = 0;
	j = 0;

	while (i < v1.size() && j < v2.size())
	{
		if (v1.at(i) < v2.at(j))
		{
			vectorFinal.push_back(v1.at(i));
			++i;
		}
		else
		{
			vectorFinal.push_back(v2.at(j));
			++j;
		}
	}
	if (i == v1.size())
	{

		while (j < v2.size())
		{
			vectorFinal.push_back(v2.at(j));
			++j;
		}
	}
	else
	{
		while (i < v1.size())
		{
			vectorFinal.push_back(v1.at(i));
			++i;
		}
	}

	for (int i = 0; i < vectorFinal.size(); i++) {
		std::cout << vectorFinal.at(i) << ", ";
	}
}


Merge::Merge()
{
}