#include <iostream>
#include "Calendario.h"

void main() {
	int d, m, a, s;
	std::cout << "Introduce El dia: ";
	std::cin >> d;
	std::cout << "Introduce El mes: ";
	std::cin >> m;
	std::cout << "Introduce El año: ";
	std::cin >> a;
	std::cout << "Introduce los segundos que le quieres sumar a la fecha actual: ";
	std::cin >> s;
	Calendario C;
	C.Sumador(d,m,a,s);
	
	system("Pause");
}

/*int hora = 0, minuto = 0;
while (segundos >= 0) {
if (segundos >= 60) {
minuto++;
segundos -= 60;
}
if (minuto >= 60) {
hora++;
segundos -= 3600;

}
if (hora >= 24)
{
dia++;
segundos -= 86400;
}
if (dia >= 30)
{
mes++;
segundos -= 2592000;

}
if (mes >= 12)
{
año++;
segundos -= 31536000;
}
else {
segundos = segundos;
}
std::cout << dia << "/ " << mes << "/ " << año << " : " << hora << " : " << minuto << " : " << segundos << "\n";

}*/