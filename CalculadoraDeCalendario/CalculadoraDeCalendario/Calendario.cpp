#include "Calendario.h"
#include <iostream>


void Calendario::Sumador(int dia, int mes, int año, long int segundos)
{
	int mesFinal, mesInicial;
	int añoInicial;
	int contador;
	int minutos = 0;
	mesInicial = mes;
	añoInicial = año;
	contador = segundos/60;
	segundos %=60;
	minutos += contador;
	int horas = 0;
	contador = minutos/60;
	minutos%=60;
	horas += contador;
	contador = horas / 24;
	horas %= 24;
	dia += contador;
	contador = dia / 30;
	dia %= 30;
	mes += contador;
	contador = mes / 12;
	mes %= 12;
	año += contador;

	mesFinal = mes;

	if (mesFinal > mesInicial) {
		contador = mesFinal - mesInicial;
		contador /= 2;
		dia -= contador;
	}
	else if(mesInicial> mesFinal)
	{
		contador = mesInicial - mesFinal;
		contador /= 2;
		dia -= contador;
	}
	else if (mesFinal == mesInicial && añoInicial != año) {
		dia -= 5;
	}
	std::cout << dia << "/ " << mes << "/ " << año << " : " << horas << " : " << minutos << " : " << segundos << "\n";
}

Calendario::Calendario()
{
	
}


Calendario::~Calendario()
{
}
