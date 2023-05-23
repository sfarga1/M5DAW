#include <iostream>
#include "Character.h"
#include "FinalBoss.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Dimensiones del escenario
const int FILAS = 10;
const int COLUMNAS = 5;

// Caracteres para representar los elementos
const char HEROE = 'H';
const char PUERTA = 'P';
const char ENEMIGO = 'E';
const char VACIO = '.';

// Declaración personajes
Character hero("", 100, 25, 40, 0, COLUMNAS / 2);
bool heroIsAlive = true;
Character enemy1("Abominacion del abismo", 100, 25, 40, 0, 0);
bool enemy1IsAlive = true;
Character enemy2("Criatura del valle de las lamentaciones", 100, 25, 40, 0, 0);
bool enemy2IsAlive = true;
Character enemy3("Acolito del sufrimiento", 100, 25, 40, 0, 0);
bool enemy3IsAlive = true;
Character enemy4("Oraculo de la desesperacion", 100, 25, 40, 0, 0);
bool enemy4IsAlive = true;

void introJuego() {
	string heroName;
	cout << "No hay tiempo para explicaciones." << endl << endl << "Debes vencer a un temible enemigo para librar a tu puelo de la oscuridad en la que se encuentra sumido." << endl << endl
		<< "El enemigo se esconde tras la puerta azul. Ten cuidado, es muy poderoso, y cuatro criaturas malditas trataran de impedirte que llegues a el." << endl << endl
		<< "Viajero, cual es tu nombre?" << endl << endl;
	cin >> heroName;
	hero.setName(heroName);
	system("cls");
	cout << "Viajero " << heroName << ", este es un viaje solo de ida. Seras recordado por los tuyos como un heroe si vences... y como un martir si eres derrotado. Mas te vale estar confesado."
		<< endl << endl
		<< "Buena suerte.";

	cin.get();
	cin.get();
}

void reiniciarVidaEnemigos() {
	enemy1.setHp(100);
	enemy2.setHp(100);
	enemy3.setHp(100);
	enemy4.setHp(100);
}

void combatir(Character& enemy, Character& hero) {
	bool heroIsAlive = true;
	bool enemyIsAlive = true;

	do {
		// Turno del héroe
		int heroDamageDealt = rand() % hero.getAttack() + 1;
		enemy.setHp(enemy.getHp() - heroDamageDealt);

		cout << "El heroe ataca al enemigo " << enemy.getName() << " causando " << heroDamageDealt << " puntos de danyo." << endl;
		cin.get();

		if (enemy.getHp() <= 0) {
			enemyIsAlive = false;
			break;
		}

		// Turno del enemigo
		int enemyDamageDealt = rand() % enemy.getAttack() + 1;
		hero.setHp(hero.getHp() - enemyDamageDealt);

		cout << "El enemigo " << enemy.getName() << " ataca al heroe causando " << enemyDamageDealt << " puntos de danyo." << endl;
		cin.get();

		if (hero.getHp() <= 0) {
			heroIsAlive = false;
			break;
		}

	} while (heroIsAlive && enemyIsAlive);
}

// Función que establece todos los elementos del escenario como vacíos al iniciar el juego
void inicializarEscenario(char escenario[FILAS][COLUMNAS]) {
	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLUMNAS; j++) {
			escenario[i][j] = VACIO;
		}
	}
}

// Función que muestra en consola el estado actual del escenario
void mostrarEscenario(char escenario[FILAS][COLUMNAS]) {
	system("cls");
	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLUMNAS; j++) {
			char c = escenario[i][j];
			switch (c) {
			case HEROE:
				cout << "\033[32m" << char(254) << "\033[0m ";   // Verde
				break;
			case PUERTA:
				cout << "\033[34m" << char(254) << "\033[0m ";   // Azul
				break;
			case ENEMIGO:
				cout << "\033[31m" << char(254) << "\033[0m ";   // Rojo
				break;
			default:
				cout << c << ' ';
				break;
			}
		}
		cout << endl;
	}
	cout << endl;
}

// Función para mover al Héroe
void moverHeroe(char escenario[FILAS][COLUMNAS], int& heroeX, int& heroeY) {
	int movimientoX = 0, movimientoY = 0;
	char opcion;

	cin >> opcion;

	switch (toupper(opcion)) {
	case 'W':
		movimientoX = -1;
		break;
	case 'A':
		movimientoY = -1;
		break;
	case 'S':
		movimientoX = 1;
		break;
	case 'D':
		movimientoY = 1;
		break;
	default:
		return;
	}

	int nuevoHeroeX = heroeX + movimientoX;
	int nuevoHeroeY = heroeY + movimientoY;

	// Verificar si el movimiento del héroe es válido
	if (nuevoHeroeX < 0 || nuevoHeroeX >= FILAS || nuevoHeroeY < 0 || nuevoHeroeY >= COLUMNAS ||
		escenario[nuevoHeroeX][nuevoHeroeY] == ENEMIGO) {
		return;
	}

	// Actualizar la posición del héroe en el escenario
	escenario[heroeX][heroeY] = VACIO;
	escenario[nuevoHeroeX][nuevoHeroeY] = HEROE;
	heroeX = nuevoHeroeX;
	heroeY = nuevoHeroeY;
}

// Función que busca las posiciones de los enemigos
void encontrarPosicionesEnemigos(char escenario[FILAS][COLUMNAS], int enemigos[][2], int& numEnemigos) {
	numEnemigos = 0;

	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLUMNAS; j++) {
			if (escenario[i][j] == ENEMIGO) {
				enemigos[numEnemigos][0] = i;
				enemigos[numEnemigos][1] = j;
				numEnemigos++;
			}
		}
	}
}

// Función para mover a los enemigos
void moverEnemigos(char escenario[FILAS][COLUMNAS], int enemigos[][2], int numEnemigos) {
	for (int i = 0; i < numEnemigos; i++) {
		int enemigoX = enemigos[i][0];
		int enemigoY = enemigos[i][1];

		// Generar una dirección de movimiento aleatoria para cada enemigo
		int direccionX = rand() % 3 - 1;  // -1, 0 o 1
		int direccionY = rand() % 3 - 1;  // -1, 0 o 1

		int nuevoEnemigoX = enemigoX + direccionX;
		int nuevoEnemigoY = enemigoY + direccionY;

		// Verificar si el movimiento del enemigo es válido
		if (nuevoEnemigoX >= 0 && nuevoEnemigoX < FILAS && nuevoEnemigoY >= 0 && nuevoEnemigoY < COLUMNAS
			&& escenario[nuevoEnemigoX][nuevoEnemigoY] == VACIO) {
			escenario[enemigoX][enemigoY] = VACIO;
			escenario[nuevoEnemigoX][nuevoEnemigoY] = ENEMIGO;
			enemigos[i][0] = nuevoEnemigoX;
			enemigos[i][1] = nuevoEnemigoY;
		}
	}
}

// Función que posiciona al iniciar la partida a los enemigos en posiciones aleatorias, a la puerta en una columna aleatoria de la
// última fila y al héroe en la columna del medio de la primera fila
void posicionarElementos(char escenario[FILAS][COLUMNAS], int& randomColumnaPuerta) {
	escenario[0][COLUMNAS / 2] = HEROE;

	// Generar una posición aleatoria para la puerta en la última fila
	randomColumnaPuerta = rand() % COLUMNAS;
	escenario[FILAS - 1][randomColumnaPuerta] = PUERTA;

	const int NUM_ENEMIGOS = 4;
	int enemigosColocados = 0;

	while (enemigosColocados < NUM_ENEMIGOS) {
		int randomFila = rand() % FILAS;
		int randomColumna = rand() % COLUMNAS;

		// Verificar que la posición generada no esté adyacente al personaje o la puerta
		if (!((randomFila == 0 && randomColumna == COLUMNAS / 2) ||
			(randomFila == FILAS - 1 && randomColumna == randomColumnaPuerta) ||
			(randomFila == 0 && randomColumna == COLUMNAS / 2 - 1) ||
			(randomFila == 0 && randomColumna == COLUMNAS / 2 + 1)) &&
			escenario[randomFila][randomColumna] == VACIO) {
			escenario[randomFila][randomColumna] = ENEMIGO;
			enemigosColocados++;
		}
	}
}

bool hayEnemigosAdyacentes(char escenario[FILAS][COLUMNAS], int heroeX, int heroeY) {
	// Verificar si hay un enemigo a la izquierda del héroe
	if (heroeY > 0 && escenario[heroeX][heroeY - 1] == ENEMIGO) {
		return true;
	}

	// Verificar si hay un enemigo a la derecha del héroe
	if (heroeY < COLUMNAS - 1 && escenario[heroeX][heroeY + 1] == ENEMIGO) {
		return true;
	}

	// Verificar si hay un enemigo arriba del héroe
	if (heroeX > 0 && escenario[heroeX - 1][heroeY] == ENEMIGO) {
		return true;
	}

	// Verificar si hay un enemigo abajo del héroe
	if (heroeX < FILAS - 1 && escenario[heroeX + 1][heroeY] == ENEMIGO) {
		return true;
	}

	return false;
}

// Bucle del juego
void gameLoop(char escenario[FILAS][COLUMNAS], int randomColumnaPuerta) {
	int enemigos[FILAS * COLUMNAS][2];
	int numEnemigos = 0;
	int heroeX = 0, heroeY = COLUMNAS / 2;

	encontrarPosicionesEnemigos(escenario, enemigos, numEnemigos);

	while (true) {
		// Guardar el mensaje antes de llamar a mostrarEscenario()
		string mensajeEnemigosAdyacentes;

		// Llamar a mostrarEscenario() y guardar el mensaje si hay enemigos adyacentes
		if (hayEnemigosAdyacentes(escenario, heroeX, heroeY)) {
			mensajeEnemigosAdyacentes = "Oh no! Hay enemigos adyacentes. Se ha iniciado un combate.";

			// Bucle de batalla
			if (enemy1IsAlive) {
				combatir(enemy1, hero);
				enemy1IsAlive = false;
			}
			else

				if (enemy2IsAlive) {
					reiniciarVidaEnemigos();
					combatir(enemy2, hero);
					enemy2IsAlive = false;
				}
				else

					if (enemy3IsAlive) {
						reiniciarVidaEnemigos();
						combatir(enemy3, hero);
						enemy3IsAlive = false;
					}
					else

						if (enemy4IsAlive) {
							reiniciarVidaEnemigos();
							combatir(enemy4, hero);
							enemy4IsAlive = false;
						}
		}

		mostrarEscenario(escenario);

		// Imprimir el mensaje si existe
		if (!mensajeEnemigosAdyacentes.empty()) {
			cout << mensajeEnemigosAdyacentes << endl;
		}

		// Mover al héroe
		moverHeroe(escenario, heroeX, heroeY);

		// Mover enemigos
		moverEnemigos(escenario, enemigos, numEnemigos);

		if (escenario[FILAS - 1][randomColumnaPuerta] == HEROE) {
			cout << "Felicidades! El heroe ha llegado a la puerta. Has ganado el juego!" << endl;
			break;
		}
	}
}

int main() {
	srand(time(0));

	introJuego();
	char escenario[FILAS][COLUMNAS];
	int randomColumnaPuerta;
	inicializarEscenario(escenario);
	posicionarElementos(escenario, randomColumnaPuerta);

	gameLoop(escenario, randomColumnaPuerta);

	return 0;
}