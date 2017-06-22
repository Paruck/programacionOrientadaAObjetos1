#pragma once
#include <vector>
class Calendario
{
public:
	long float segundos;
	int contador, minutos, horas;
	void Sumador(int dia, int mes, int año, long int segundos, std::vector<int> FechaFinal);
	Calendario();
	~Calendario();
};
