#include <iostream>
#include "Lancha.h"
#include <time.h>

using namespace std;

int activarNitro;

void intro() {
	cout << "Bienvenido a Columbus for Speed, el videojuego en el que "
		<< "los tripulantes de los tres barcos con los que Colon llego a America "
		<< "se echan una carrera en su viaje para ver quien llega antes al Nuevo Mundo\n\n";

	cout << "Presiona intro para continuar";

	cin.get();
	system("cls");
}

int usarNitro(lancha &numeroLancha, int activarNitro) {
	srand(time(NULL));
	bool dadoNitro = rand() % 2;

		cout << "Quieres intentar usar el nitro?\n[1] - Si\n[2] - No\n";
		cin >> activarNitro;
		if (activarNitro == 1)
		{
			if (dadoNitro == 0)
			{
				cout << "El nitro ha fallado! Tu velocidad se ha reducido a la mitad...\n\n";
				numeroLancha.setVelocidad(numeroLancha.getVelocidad() / 2);
			}
			else {
				cout << "El nitro ha funcionado! Tu velocidad se ha duplicado!!\n\n";
				numeroLancha.setVelocidad(numeroLancha.getVelocidad() * 2);
			}
			numeroLancha.setNitro(0);
		}

	return activarNitro;
}

int jugarTurno(lancha &numeroLancha) {
	cin.get();
	cout << numeroLancha.getNombre() << ", presiona intro para lanzar el dado\n";

	cin.ignore();
	int dado = rand() % 6 + 1;
	cout << "Te ha salido un " << dado << "!\n\n";

	numeroLancha.setVelocidad(numeroLancha.getVelocidad() + dado);

	if (numeroLancha.getNitro() == 1) {
		activarNitro = usarNitro(numeroLancha, activarNitro);
	}

	numeroLancha.setDistanciaRecorrida(numeroLancha.getDistanciaRecorrida() + numeroLancha.getVelocidad() * 100);

	numeroLancha.printStats();
	cin.ignore();

	return numeroLancha.getVelocidad();
}

void verificarGanador(lancha &lancha1, lancha &lancha2, lancha lancha3) {
	if (lancha1.getDistanciaRecorrida() == lancha2.getDistanciaRecorrida())
	{
		cout << "Empate entre " << lancha1.getNombre() << " y " << lancha2.getNombre() << endl;
	}
	else if (lancha1.getDistanciaRecorrida() == lancha3.getDistanciaRecorrida())
	{
		cout << "Empate entre " << lancha1.getNombre() << " y " << lancha3.getNombre() << endl;
	}
	else if (lancha2.getDistanciaRecorrida() == lancha3.getDistanciaRecorrida())
	{
		cout << "Empate entre " << lancha2.getNombre() << " y " << lancha3.getNombre() << endl;
	}
	else if (lancha1.getDistanciaRecorrida() > lancha2.getDistanciaRecorrida() && lancha1.getDistanciaRecorrida() > lancha3.getDistanciaRecorrida())
	{
		cout << "Ha ganado " << lancha1.getNombre() << endl;
	}
	else if (lancha2.getDistanciaRecorrida() > lancha1.getDistanciaRecorrida() && lancha2.getDistanciaRecorrida() > lancha3.getDistanciaRecorrida())
	{
		cout << "Ha ganado " << lancha2.getNombre() << endl;
	}
	else if (lancha3.getDistanciaRecorrida() > lancha1.getDistanciaRecorrida() && lancha3.getDistanciaRecorrida() > lancha2.getDistanciaRecorrida())
	{
		cout << "Ha ganado " << lancha3.getNombre() << endl;
	}
}

int main() {
	srand(time(NULL));
	int turno = 1;
	int dado;
	int juego;
	
	lancha lancha1("La Ninya", 0, 0, 1);
	lancha lancha2("La Pinta", 0, 0, 1);
	lancha lancha3("La Santa Maria", 0, 0, 1);

	intro();
	cin.ignore();

	do
	{
		cout << "TURNO " << turno << endl << endl;
		lancha1.printStats();
		lancha2.printStats();
		lancha3.printStats();

		juego = jugarTurno(lancha1);
		juego = jugarTurno(lancha2);
		juego = jugarTurno(lancha3);

		turno++;
	} while (turno <= 5);

	lancha1.finJuego();
	lancha2.finJuego();
	lancha3.finJuego();

	verificarGanador(lancha1, lancha2, lancha3);

	return 0;
}