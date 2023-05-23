#pragma once
#include <iostream>

using namespace std;

class Character {
private:
	string name;
	int hp;
	int attack;
	int ultraAttack;
	int positionX;
	int positionY;

public:
	//constructor
	Character(string pName, int pHp, int pAttack, int pUltraAttack, int pPositionX, int pPositionY);

	//getters
	string getName();
	int getHp();
	int getAttack();
	int getUltraAttack();
	int getPositionX();
	int getPositionY();

	//setters
	void setName(string pName);
	void setHp(int pHp);
	void setAttack(int pAttack);
	void setUltraAttack(int pUltraAttack);
	void setPositionX(int pPositionX);
	void setPositionY(int pPositionY);

	//METHODS
	void printStats();
};