#include <iostream>

void calculadoraDeCalendario(int dia, int mes, int año, int segundos) {
	int hora = 0, minuto = 0, contador;
	while (segundos >= 0) {
	if (segundos >= 60) {
		contador = segundos / 60;
		segundos %= 60;
		minuto+= contador;
	}
	if (minuto >= 60) {

		contador = minuto / 60;
		minuto %= 60;
		hora += contador;

	}
	if (hora >= 24)
	{
		contador = hora / 24;
		hora %= 24;
		dia += contador;

	}
	if (dia >= 30)
	{
		contador = dia / 30;
		dia %= 30;
		mes += contador;

	}
	if (mes >= 12)
	{
		contador = mes / 12;
		mes %= 12;
		año += contador;
	}
	else {
	segundos = segundos;
	}
	std::cout << dia << "/ " << mes << "/ " << año << " : " << hora << " : " << minuto << " : " << segundos << "\n";
	break;
	}
}

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
	calculadoraDeCalendario(d, m, a, s);
	system("Pause");
}