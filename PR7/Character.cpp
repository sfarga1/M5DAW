#include "Character.h"

//constructor
Character::Character(string pName, int pHp, int pAttack, int pUltraAttack, int pPositionX, int pPositionY) {
	name = pName;
	hp = pHp;
	attack = pAttack;
	ultraAttack = pUltraAttack;
	positionX = pPositionX;
	positionY = pPositionY;
}

//getters
int Character::getAttack() {
	return attack;
}

int Character::getUltraAttack() {
	return ultraAttack;
}

int Character::getHp() {
	return hp;
}

string Character::getName() {
	return name;
}

int Character::getPositionX() {
	return positionX;
}

int Character::getPositionY() {
	return positionY;
}

//setters
void Character::setAttack(int pAttack) {
	attack = pAttack;
}

void Character::setHp(int pHp) {
	hp = pHp;
}

void Character::setName(string pName) {
	name = pName;
}

void Character::setUltraAttack(int pUltraAttack) {
	ultraAttack = pUltraAttack;
}

void Character::setPositionX(int pPositionX) {
	positionX = pPositionX;
}

void Character::setPositionY(int pPositionY) {
	positionY = pPositionY;
}

//METHODS
void Character::printStats() {
	cout << "El ataque del enemigo es " << getAttack()
		<< ", su nombre es " << getName() << ", su vida es de " << hp
		<< " y su ultra ataque es de " << ultraAttack << endl;
}
