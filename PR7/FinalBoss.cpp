#include "FinalBoss.h"

FinalBoss::FinalBoss(string pName,
	int pHp,
	int pAttack,
	int pUltraAttack,
	int pPositionX,
	int pPositionY,
	int pFireAttack,
	int pIceAttack) :Character(pName, pHp, pAttack, pUltraAttack, pPositionX, pPositionY) {
	fireAttack = pFireAttack;
	iceAttack = pIceAttack;
}

int FinalBoss::getFireAttack() {
	return fireAttack;
}

int FinalBoss::getIceAttack() {
	return iceAttack;
}

void FinalBoss::setFireAttack(int pFireAttack) {
	fireAttack = pFireAttack;
}

void FinalBoss::setIceAttack(int pIceAttack) {
	iceAttack = pIceAttack;
}

void FinalBoss::printStats() {
	cout << "El ataque de hielo del enemigo " << getName() << " vale " << getIceAttack() << endl;
	//cout << "El ataque de hielo del enemigo vale " << iceAttack << endl;
	cout << "El ataque de fuego del enemigo " << getName() << " vale " << getFireAttack() << endl;
	cout << "El ataque del enemigo " << getName() << " vale " << getAttack() << endl;

	cout << "La vida del enemigo " << getName() << " es " << getHp() << endl;
	//cout << "La vida del enemigo es " << hp << endl;
}