#include "Insert.h"
#include <iostream>
#include <vector>


Insert::Insert()
{
}

void Insert::insertNum1()
{
    	sumador = 0;
		while (true)
		{
			std::cin >> x;
			if (x < 0)
				break;
			sumador += x;

		}
		std::cout << "El resultado de la suma es: " << sumador;
}


void Insert::insertNum2()
{
	std::vector<int> vectorDeSuma;
	sumador = 0;
	i = 0;
	while (true)
	{
		std::cin >> y;
		if (y < 0)
			break;


		vectorDeSuma.push_back(y);

		sumador += vectorDeSuma.at(i);

		i++;
	}
	std::cout << "El resultado de la suma es: " << sumador;
}

Insert::~Insert()
{
}
