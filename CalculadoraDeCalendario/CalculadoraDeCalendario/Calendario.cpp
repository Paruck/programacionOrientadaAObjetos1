#include "Calendario.h"
#include <iostream>
#include <vector>

void Calendario::Sumador(int dia, int mes, int año, long int segundos, std::vector<int> FechaFinal)
{
	minutos = 0;
	horas = 0;
	contador = segundos / 60;
	segundos %= 60;
	FechaFinal.push_back(segundos);
	minutos += contador;
	contador = minutos / 60;
	minutos %= 60;
	FechaFinal.push_back(minutos);
	horas += contador;
	contador = horas / 24;
	horas %= 24;
	FechaFinal.push_back(horas);
	dia += contador;
	contador = dia / 30;
	dia %= 30;
	FechaFinal.push_back(dia);
	mes += contador;
	contador = mes / 12;
	mes %= 12;
	FechaFinal.push_back(mes);
	año += contador;
	FechaFinal.push_back(año);
}

Calendario::Calendario()
{
	
}


Calendario::~Calendario()
{
}
