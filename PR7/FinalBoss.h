#pragma once
#include "Character.h"
#include <iostream>

using namespace std;

class FinalBoss : public Character {
private:
	int fireAttack;
	int iceAttack;

public:

	FinalBoss(string pName, int pHp, int pAttack, int pUltraAttack, int pPositionX, int pPositionY, int pFireAttack, int pIceAttack);
	//GETTERS AND SETTERS
	void setFireAttack(int pFireAttack);
	void setIceAttack(int pIceAttack);

	int getFireAttack();
	int getIceAttack();

	//My METHODS
	void printStats();
};