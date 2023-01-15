#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <MMSystem.h>

using namespace std;

//Atributos del heroe
int heroHP = 100;
string heroName;
bool heroIsAlive = true;
int heroDamage;

//Atributos del primer enemigo (path 1)
int enemy1HP = 100;
string enemy1Name = "buscalios Yonatan";
bool enemy1IsAlive = true;
int enemy1Damage;

//Atributos del segundo enemigo (path 1)
int enemy2HP = 100;
string enemy2Name = "maleante Francisco";
bool enemy2IsAlive = true;
int enemy2Damage;

//Atributos del tercer enemigo (path 2)
int enemy3HP = 100;
string enemy3Name = "exconvicto Miguel";
bool enemy3IsAlive = true;
int enemy3Damage;

//Atributos del cuarto enemigo (path 2)
int enemy4HP = 100;
string enemy4Name = "carterista Yusef";
bool enemy4IsAlive = true;
int enemy4Damage;

void introJuego() {
	cout << "Bienvenido a Barcelona Simulator, el fantastico videojuego en el que te enfrentaras a temibles enemigos que haran todo lo posible por hacerse con tu cartera, tu movil o tu vida. Disfruta" << endl << endl;
	cout << "Un " << enemy1Name << " enemigo ha aparecido. Tiene " << enemy1HP << " puntos de vida." << endl;
	cout << "Ha aparecido tambien un " << enemy2Name << " enemigo, con " << enemy2HP << " puntos de vida." << endl;
	cout << "Ambos se acercan a ti, y no traman nada bueno..." << endl << endl;
	cout << "El " << enemy1Name << " dice: -tuuu como te llamas?" << endl;
	cin >> heroName;
}

bool ataqueEnemigo(int enemyDamage, int& heroHP, string enemyName, bool& enemyIsAlive) {
	if (enemyIsAlive)
	{
		enemyDamage = rand() % 20 + 1;
		heroHP = heroHP - enemyDamage;
		cout << "El " << enemyName << " te ha atacado!" << endl;
		cout << "Te quedan " << heroHP << " puntos de vida" << endl << endl;

		return true;
	}
	else
		return false;
}

int heroChoosesEnemyToAttack(string heroName, string& enemy1Name, string& enemy2Name) {
	int selectorEnemigo;
	cout << heroName << ", a quien quieres atacar?" << endl;
	cout << "[1] " << enemy1Name << endl << "[2] " << enemy2Name << endl;
	cin >> selectorEnemigo;
	if (selectorEnemigo == 1)
	{
		return 1;
	}
	else if (selectorEnemigo == 2)
	{
		return 2;
	}
}

void heroChoosesAttack() {
	cout << heroName << ", elige un ataque: " << endl;
	cout << "[1] Punyetazo\n[2] Patada\n[3] Arriesgarse a coger la navaja del enemigo y usarla para defenderte" << endl;
}

int main() {

	//bool backgroungMusic = (PlaySound(TEXT("Cyberpunk2077Music.wav"), NULL, SND_ASYNC)); //Musica del juego

	srand(time(NULL));

	int opcion, opcion2, atacarUnEnemigo, ataque, contadorAtaque = 0, contadorAtaque2 = 0;

	introJuego();

	system("cls");
	cout << "-" << heroName << "? Menudo nombre de parguela. Dame tu movil o te rajo" << endl;
	do
	{
		cout << heroName << ", que quieres hacer?" << endl;
		cout << "[1] Luchar" << endl << "[2] Huir" << endl; //Luchar abre el path 1, huir abre el path 2
		cin >> opcion;
	} while ((opcion != 1) && (opcion != 2));

	switch (opcion) {
	case 1: //path 1
		while ((heroIsAlive) && ((enemy1IsAlive) || (enemy2IsAlive))) { //hacer varios bucles, segun que enemigo este vivo.

			//Enemigo 1 ataca
			heroIsAlive = ataqueEnemigo(enemy1Damage, heroHP, enemy1Name, enemy1IsAlive);
			//Enemigo 2 ataca
			heroIsAlive = ataqueEnemigo(enemy2Damage, heroHP, enemy2Name, enemy2IsAlive);

			//Heroe ataca
			if (heroHP > 0)
			{
				cout << "El " << enemy1Name << " enemigo tiene " << enemy1HP << " puntos de vida." << endl;
				cout << "El " << enemy2Name << " enemigo tiene " << enemy2HP << " puntos de vida." << endl << endl;

				//Heroe elige a que enemigo atacar

				atacarUnEnemigo = heroChoosesEnemyToAttack(heroName, enemy1Name, enemy2Name);

				//Heroe elige que ataque realizar
				if (atacarUnEnemigo == 1)
				{
					heroChoosesAttack();
					cin >> ataque;
					system("cls");

					if (ataque == 1) //Ataque 1: Punyetazo, quita 40 puntos de vida
					{
						heroDamage = 40;
						enemy1HP -= heroDamage;
						cout << "Le das un punyetazo en toda la cara al " << enemy1Name << " enemigo, quitandole " << heroDamage << " puntos de vida." << endl;
						cout << "Al enemigo " << enemy1Name << " le quedan " << enemy1HP << " puntos de vida" << endl << endl;
					}
					else
						if (ataque == 2) //Ataque 2: Patada, quita 30 puntos de vida
						{
							heroDamage = 30;
							enemy1HP -= heroDamage;
							cout << "Le asestas tremenda patada al " << enemy1Name << " enemigo, quitandole " << heroDamage << " puntos de vida." << endl;
							cout << "Al enemigo " << enemy1Name << " le quedan " << enemy1HP << " puntos de vida" << endl << endl;
						}
						else
							if ((ataque == 3) && (enemy1HP < 50) && (contadorAtaque != 2)) //Ataque 3: Especial, arrebatarle el arma al enemigo para derrotarle de un golpe. Quita 100 puntos de vida. El ataque 3 solo puede intentarse un total de dos veces por enemigo, y solo se logra utilizar con exito si el enemigo tiene menos de la mitad de la vida.
							{
								contadorAtaque++;
								heroDamage = 100;
								enemy1HP -= heroDamage;
								cout << "Logras lanzar al suelo al " << enemy1Name << " enemigo, haciendote con su navaja. Atacas al " << enemy1Name << " enemigo, quitandole " << heroDamage << " puntos de vida." << endl;
								cout << "Al enemigo " << enemy1Name << " le quedan " << enemy1HP << " puntos de vida" << endl << endl;
							}
							else
								if ((ataque == 3) && (enemy1HP >= 50) && (contadorAtaque != 2)) //Por tener el enemigo mas de la mitad de la vida, este ataque falla y sale en contra del heroe, perdiendo vida y el turno.
								{
									contadorAtaque++;

									cout << "Intentas hacerte con la navaja del enemigo " << enemy1Name << ", pero no esta muy desgastado y es mas rapido que tu." << endl;
									cout << "Fallas miserablemente en tu intento por hacerte con la navaja del enemigo." << endl << endl;

									enemy1Damage = rand() % 20 + 1;
									heroHP = heroHP - enemy1Damage;
									cout << "El " << enemy1Name << " te ha dado un navajazo bastante importante por haberte flipado!" << endl;
									cout << "Te quedan " << heroHP << " puntos de vida" << endl;
									cout << "Al enemigo " << enemy1Name << " le quedan " << enemy1HP << " puntos de vida" << endl << endl;
								}
								else
									if ((ataque == 3) && (contadorAtaque == 2)) //Este ataque especial solo puede intentar hacerse dos veces. Si se insiste, el heroe pierde vida y un turno.
									{
										cout << "Ya has intentado hacerte con el arma de este enemigo 2 veces. No puedes intentarlo mas." << endl;
									}
				}
				else
					if (atacarUnEnemigo == 2)
					{
						heroChoosesAttack();
						cin >> ataque;
						system("cls");

						if (ataque == 1) //Ataque 1: Punyetazo, quita 40 puntos de vida
						{
							heroDamage = 40;
							enemy2HP -= heroDamage;
							cout << "Le das un punyetazo en toda la cara al " << enemy2Name << " enemigo, quitandole " << heroDamage << " puntos de vida." << endl;
							cout << "Al enemigo " << enemy2Name << " le quedan " << enemy2HP << " puntos de vida" << endl << endl;
						}
						else
							if (ataque == 2) //Ataque 2: Patada, quita 30 puntos de vida
							{
								heroDamage = 30;
								enemy2HP -= heroDamage;
								cout << "Le asestas tremenda patada al " << enemy2Name << " enemigo, quitandole " << heroDamage << " puntos de vida." << endl;
								cout << "Al enemigo " << enemy2Name << " le quedan " << enemy2HP << " puntos de vida" << endl << endl;
							}
							else
								if ((ataque == 3) && (enemy2HP < 50) && (contadorAtaque2 != 2)) //Ataque 3: Especial, arrebatarle el arma al enemigo para derrotarle de un golpe. Quita 100 puntos de vida. El ataque 3 solo puede intentarse un total de dos veces por enemigo, y solo se logra utilizar con exito si el enemigo tiene menos de la mitad de la vida.
								{
									contadorAtaque2++;
									heroDamage = 100;
									enemy2HP -= heroDamage;
									cout << "Logras lanzar al suelo al " << enemy2Name << " enemigo, haciendote con su navaja. Atacas al " << enemy2Name << " enemigo, quitandole " << heroDamage << " puntos de vida." << endl;
									cout << "Al enemigo " << enemy2Name << " le quedan " << enemy2HP << " puntos de vida" << endl << endl;
								}
								else
									if ((ataque == 3) && (enemy2HP >= 50) && (contadorAtaque2 != 2)) //Por tener el enemigo mas de la mitad de la vida, este ataque falla y sale en contra del heroe, perdiendo vida y el turno.
									{
										contadorAtaque2++;

										cout << "Intentas hacerte con la navaja del enemigo " << enemy2Name << ", pero no esta muy desgastado y es mas rapido que tu." << endl;
										cout << "Fallas miserablemente en tu intento por hacerte con la navaja del enemigo." << endl << endl;

										enemy2Damage = rand() % 20 + 1;
										heroHP = heroHP - enemy2Damage;
										cout << "El " << enemy2Name << " te ha dado un navajazo bastante importante por haberte flipado!" << endl;
										cout << "Te quedan " << heroHP << " puntos de vida" << endl;
										cout << "Al enemigo " << enemy2Name << " le quedan " << enemy2HP << " puntos de vida" << endl << endl;
									}
									else
										if ((ataque == 3) && (contadorAtaque2 == 2)) //Este ataque especial solo puede intentar hacerse dos veces. Si se insiste, el heroe pierde vida y un turno.
										{
											cout << "Ya has intentado hacerte con el arma de este enemigo 2 veces. No puedes intentarlo mas." << endl;
										}
					}
			}
			if (enemy1HP <= 0) //Mensaje de derrota del enemigo1
			{
				enemy1HP = 0;
				enemy1IsAlive = false;
				cout << "Has derrotado al enemigo " << enemy1Name << "!" << endl;
				cout << "Dejalo, ya esta muerto!" << endl << endl;
			}
			if (enemy2HP <= 0) //Mensaje de derrota del enemigo2
			{
				enemy2HP = 0;
				enemy2IsAlive = false;
				cout << "Has derrotado al enemigo " << enemy2Name << "!" << endl;
				cout << "Dejalo, ya esta muerto!" << endl << endl;
			}
			if ((!enemy1IsAlive) && (!enemy2IsAlive)) //Mensaje de fin del juego. Victoria
			{
				cout << "Enhorabuena, has logrado vencer a " << enemy1Name << " y a " << enemy2Name << "." << endl;
				cout << "Te diriges de inmediato al Vall dHebron a curarte de tus heridas." << endl;
				cout << "Has vencido. Has logrado volver a casa con tu movil, tu cartera y tu vida." << endl << endl;
				cout << "FIN DEL JUEGO" << endl;

				return 0;
			}
			if (heroHP <= 0)
			{
				heroHP = 0;
				heroIsAlive = false;
			}
		}
		if (!heroIsAlive) //Mensaje de fin del juego. Derrota
		{
			cout << "Los enemigos te han dejado fino, sin movil, sin cartera y al borde de la muerte." << endl;
			cout << "Un transeunte te encuentra en el suelo y llama al 112." << endl;
			cout << "Llega una ambulancia y te lleva de inmediato al Vall dHebron a curarte de tus heridas." << endl;
			cout << "Has perdido. No has logrado volver a casa a salvo." << endl << endl;
			cout << "FIN DEL JUEGO" << endl;

			return 0;
		}
		break;
	case 2: //path 2
		system("cls");
		cout << "El " << enemy2Name << " dice: " << "-" << heroName << ", eres un cagao! " << enemy1Name << ", vamos a por el, primo" << endl;
		cout << "Creias que podias huir, pero " << enemy1Name << " y " << enemy2Name << " estan empenyados en robarte el movil" << endl << endl;
		cout << "Mientras corres, un tipo con carpeta te detiene repentinamente" << endl;
		cout << "-Buenas tardes, me llamo Josep Armengol y trabajo para curadores sin fronteras, me echas una firmita porfa?" << endl;
		cout << heroName << ", que quieres hacer?" << endl;
		cout << "[1] Seguir corriendo" << endl << "[2] Darle una firmita al carpetas" << endl;
		cin >> opcion;
		system("cls");

		if (opcion == 2) {
			cout << "El " << enemy1Name << " y el " << enemy2Name << " te han dado una paliza y se han llevado todas tus pertenencias." << endl << endl;
			cout << "FIN DEL JUEGO" << endl;
			return 0;
		}
		else
		{
			cout << "Tras correr cinco manzanas, logras entrar en el metro de Drassanes y zafarte de " << enemy1Name << " y " << enemy2Name << "." << endl;
			cout << "Te bajas en Plaza Catalunya, y te enciendes un piti por los nervios en uno de los bancos de la plaza." << endl << endl;
			cout << "Un " << enemy3Name << " enemigo ha aparecido. Tiene " << enemy3HP << " puntos de vida." << endl;
			cout << "Ha aparecido tambien un " << enemy4Name << " enemigo, con " << enemy4HP << " puntos de vida." << endl;
			cout << "Ambos se acercan a ti, y no traman nada bueno..." << endl << endl;
			cout << "El " << enemy3Name << " dice: -me das un cigarrito porfa?" << endl;
			cout << heroName << ", que quieres hacer?" << endl;
			cout << "[1] Darle un cigarrito" << endl << "[2] Negarte" << endl;
			cin >> opcion2;
			system("cls");

			if (opcion2 == 1)
			{
				cout << "Mientras le dabas un cigarrito al " << enemy3Name << ", el " << enemy4Name << " te ha robado la cartera y el movil." << endl << endl;
				cout << "FIN DEL JUEGO" << endl;
				return 0;
			}
			else if (opcion2 == 2)
			{
				while ((heroIsAlive) && ((enemy3IsAlive) || (enemy4IsAlive))) { //De aqui en adelante es todo exactamente igual que en el bucle de batalla del path 1 (exceptuando los mensajes de victoria y derrota), cambiando al enemy1 por enemy3 y al enemy2 por enemy4.

					//Enemigo 3 ataca
					heroIsAlive = ataqueEnemigo(enemy3Damage, heroHP, enemy3Name, enemy3IsAlive);

					//Enemigo 4 ataca
					heroIsAlive = ataqueEnemigo(enemy4Damage, heroHP, enemy4Name, enemy4IsAlive);

					//Heroe ataca
					if (heroHP > 0)
					{
						cout << "El " << enemy3Name << " enemigo tiene " << enemy3HP << " puntos de vida." << endl;
						cout << "El " << enemy4Name << " enemigo tiene " << enemy4HP << " puntos de vida." << endl << endl;
						//Heroe elige a que enemigo atacar
						atacarUnEnemigo = heroChoosesEnemyToAttack(heroName, enemy3Name, enemy4Name);

						//Heroe elige que ataque realizar
						if (atacarUnEnemigo == 1)
						{
							heroChoosesAttack();
							cin >> ataque;
							system("cls");

							if (ataque == 1) //Ataque 1: Punyetazo, quita 40 puntos de vida
							{
								heroDamage = 40;
								enemy3HP -= heroDamage;
								cout << "Le das un punyetazo en toda la cara al " << enemy3Name << " enemigo, quitandole " << heroDamage << " puntos de vida." << endl;
								cout << "Al enemigo " << enemy3Name << " le quedan " << enemy3HP << " puntos de vida" << endl << endl;
							}
							else
								if (ataque == 2) //Ataque 2: Patada, quita 30 puntos de vida
								{
									heroDamage = 30;
									enemy3HP -= heroDamage;
									cout << "Le asestas tremenda patada al " << enemy3Name << " enemigo, quitandole " << heroDamage << " puntos de vida." << endl;
									cout << "Al enemigo " << enemy3Name << " le quedan " << enemy3HP << " puntos de vida" << endl << endl;
								}
								else
									if ((ataque == 3) && (enemy3HP < 50) && (contadorAtaque != 2)) //Ataque 3: Especial, arrebatarle el arma al enemigo para derrotarle de un golpe. Quita 100 puntos de vida. El ataque 3 solo puede intentarse un total de dos veces por enemigo, y solo se logra utilizar con exito si el enemigo tiene menos de la mitad de la vida.
									{
										contadorAtaque++;
										heroDamage = 100;
										enemy3HP -= heroDamage;
										cout << "Logras lanzar al suelo al " << enemy3Name << " enemigo, haciendote con su navaja. Atacas al " << enemy3Name << " enemigo, quitandole " << heroDamage << " puntos de vida." << endl;
										cout << "Al enemigo " << enemy3Name << " le quedan " << enemy3HP << " puntos de vida" << endl << endl;
									}
									else
										if ((ataque == 3) && (enemy3HP >= 50) && (contadorAtaque != 2)) //Por tener el enemigo mas de la mitad de la vida, este ataque falla y sale en contra del heroe, perdiendo vida y el turno.
										{
											contadorAtaque++;

											cout << "Intentas hacerte con la navaja del enemigo " << enemy3Name << ", pero no esta muy desgastado y es mas rapido que tu." << endl;
											cout << "Fallas miserablemente en tu intento por hacerte con la navaja del enemigo." << endl << endl;

											enemy3Damage = rand() % 20 + 1;
											heroHP = heroHP - enemy3Damage;
											cout << "El " << enemy3Name << " te ha dado un navajazo bastante importante por haberte flipado!" << endl;
											cout << "Te quedan " << heroHP << " puntos de vida" << endl;
											cout << "Al enemigo " << enemy3Name << " le quedan " << enemy3HP << " puntos de vida" << endl << endl;
										}
										else
											if ((ataque == 3) && (contadorAtaque == 2)) //Este ataque especial solo puede intentar hacerse dos veces. Si se insiste, el heroe pierde vida y un turno.
											{
												cout << "Ya has intentado hacerte con el arma de este enemigo 2 veces. No puedes intentarlo mas." << endl;
											}
						}
						else
							if (atacarUnEnemigo == 2)
							{
								heroChoosesAttack();
								cin >> ataque;
								system("cls");

								if (ataque == 1) //Ataque 1: Punyetazo, quita 40 puntos de vida
								{
									heroDamage = 40;
									enemy4HP -= heroDamage;
									cout << "Le das un punyetazo en toda la cara al " << enemy4Name << " enemigo, quitandole " << heroDamage << " puntos de vida." << endl;
									cout << "Al enemigo " << enemy4Name << " le quedan " << enemy4HP << " puntos de vida" << endl << endl;
								}
								else
									if (ataque == 2) //Ataque 2: Patada, quita 30 puntos de vida
									{
										heroDamage = 30;
										enemy4HP -= heroDamage;
										cout << "Le asestas tremenda patada al " << enemy4Name << " enemigo, quitandole " << heroDamage << " puntos de vida." << endl;
										cout << "Al enemigo " << enemy4Name << " le quedan " << enemy4HP << " puntos de vida" << endl << endl;
									}
									else
										if ((ataque == 3) && (enemy4HP < 50) && (contadorAtaque2 != 2)) //Ataque 3: Especial, arrebatarle el arma al enemigo para derrotarle de un golpe. Quita 100 puntos de vida. El ataque 3 solo puede intentarse un total de dos veces por enemigo, y solo se logra utilizar con exito si el enemigo tiene menos de la mitad de la vida.
										{
											contadorAtaque2++;
											heroDamage = 100;
											enemy4HP -= heroDamage;
											cout << "Logras lanzar al suelo al " << enemy4Name << " enemigo, haciendote con su navaja. Atacas al " << enemy4Name << " enemigo, quitandole " << heroDamage << " puntos de vida." << endl;
											cout << "Al enemigo " << enemy4Name << " le quedan " << enemy4HP << " puntos de vida" << endl << endl;
										}
										else
											if ((ataque == 3) && (enemy4HP >= 50) && (contadorAtaque2 != 2)) //Por tener el enemigo mas de la mitad de la vida, este ataque falla y sale en contra del heroe, perdiendo vida y el turno.
											{
												contadorAtaque2++;

												cout << "Intentas hacerte con la navaja del enemigo " << enemy4Name << ", pero no esta muy desgastado y es mas rapido que tu." << endl;
												cout << "Fallas miserablemente en tu intento por hacerte con la navaja del enemigo." << endl << endl;

												enemy4Damage = rand() % 20 + 1;
												heroHP = heroHP - enemy4Damage;
												cout << "El " << enemy4Name << " te ha dado un navajazo bastante importante por haberte flipado!" << endl;
												cout << "Te quedan " << heroHP << " puntos de vida" << endl;
												cout << "Al enemigo " << enemy4Name << " le quedan " << enemy4HP << " puntos de vida" << endl << endl;
											}
											else
												if ((ataque == 3) && (contadorAtaque2 == 2)) //Este ataque especial solo puede intentar hacerse dos veces. Si se insiste, el heroe pierde vida y un turno.
												{
													cout << "Ya has intentado hacerte con el arma de este enemigo 2 veces. No puedes intentarlo mas." << endl;
												}
							}
					}
					if (enemy3HP <= 0) //Mensaje de derrota del enemigo3
					{
						enemy3HP = 0;
						enemy3IsAlive = false;
						cout << "Has derrotado al enemigo " << enemy3Name << "!" << endl;
						cout << "Dejalo, ya esta muerto!" << endl << endl;
					}
					if (enemy4HP <= 0) //Mensaje de derrota del enemigo4
					{
						enemy4HP = 0;
						enemy4IsAlive = false;
						cout << "Has derrotado al enemigo " << enemy4Name << "!" << endl;
						cout << "Dejalo, ya esta muerto!" << endl << endl;
					}
					if ((!enemy3IsAlive) && (!enemy4IsAlive)) //Mensaje de fin del juego. Victoria
					{
						cout << "Enhorabuena, has logrado vencer a " << enemy3Name << " y a " << enemy4Name << "." << endl;
						cout << "Te diriges de inmediato al Vall dHebron a curarte de tus heridas." << endl;
						cout << "Has vencido. Has logrado volver a casa con tu movil, tu cartera, tu cigarro y tu vida." << endl << endl;
						cout << "FIN DEL JUEGO" << endl;

						return 0;
					}
					if (heroHP <= 0)
					{
						heroHP = 0;
						heroIsAlive = false;
					}
				}
				if (!heroIsAlive)  //Mensaje de fin del juego. Derrota
				{
					cout << "Los enemigos te han dejado fino, sin movil, sin cartera, sin cigarro y al borde de la muerte." << endl;
					cout << "Un transeunte te encuentra en el suelo y llama al 112." << endl;
					cout << "Llega una ambulancia y te lleva de inmediato al Vall dHebron a curarte de tus heridas." << endl;
					cout << "Has perdido. No has logrado volver a casa a salvo." << endl << endl;
					cout << "FIN DEL JUEGO" << endl;

					return 0;
				}
			}
		}
		break;
	}
	return 0;
}
