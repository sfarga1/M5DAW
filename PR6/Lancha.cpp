#include "Lancha.h"

//constructor
lancha::lancha(string pNombre, double pVelocidad, int pDistanciaRecorrida, int pNitro) {
	nombre = pNombre;
	velocidad = pVelocidad;
	distanciaRecorrida = pDistanciaRecorrida;
	nitro = pNitro;
}

//getters
string lancha::getNombre() {
	return nombre;
}

double lancha::getVelocidad() {
	return velocidad;
}

int lancha::getDistanciaRecorrida() {
	return distanciaRecorrida;
}

int lancha::getNitro() {
	return nitro;
}

//setters
void lancha::setNombre(string pNombre) {
	nombre = pNombre;
}

void lancha::setVelocidad(double pVelocidad) {
	velocidad = pVelocidad;
}

void lancha::setDistanciaRecorrida(int pDistanciaRecorrida) {
	distanciaRecorrida = pDistanciaRecorrida;
}

void lancha::setNitro(int pNitro) {
	nitro = pNitro;
}

//methods
void lancha::printStats() {
	cout << "La velocidad actual de la " << getNombre() << " es " << getVelocidad()
		<< ", y ha recorrido una distancia de " << getDistanciaRecorrida() << endl << endl;
}

void lancha::finJuego() {
	cout << getNombre() << " ha recorrido una distancia total de " << getDistanciaRecorrida() << endl << endl;
}