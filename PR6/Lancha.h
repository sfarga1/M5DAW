#pragma once
#include <iostream>

using namespace std;

class lancha {
private:
	string nombre;
	double velocidad;
	int distanciaRecorrida;
	int nitro;
public:
	//constructor
	lancha(string pNombre, double pVelocidad, int pDistanciaRecorrida, int pNitro);

	//getters
	string getNombre();
	double getVelocidad();
	int getDistanciaRecorrida(), getNitro();

	//setters
	void setNombre(string pNombre), setVelocidad(double pVelocidad), setDistanciaRecorrida(int pDistanciaRecorrida), setNitro(int pNitro);

	//methods
	void printStats();
	void finJuego();
};