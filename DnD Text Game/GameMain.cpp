// DnD Text Game.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <time.h> 


int main(){
	//Sets up intial items
	int choice = 0;
	int stat[6];
	string name;
	srand(time(0));

	//starting menu and name selection
	start(choice, false, stat);
	nameselect(name);
	Class* u = 0;

	//gives player chosen class
	switch (choice) {
	case 1: //Paladin choice
		u = new Paladin(name, 12 + stat[4], stat[0], stat[4], stat[1], stat[2], stat[5], stat[3]);
		break;
	case 2:  //rougue choice
		u = new Rogue(name, 6 + stat[2], stat[4], stat[0], stat[2], stat[3], stat[5], stat[1]);
		break;
	case 3:  //ranger choice
		u = new Ranger(name, 8 + stat[4], stat[1], stat[0], stat[4], stat[2], stat[3], stat[5]);
		break;
	case 4: //monk choice
		u = new Monk(name, 10 + stat[3], stat[0], stat[2], stat[3], stat[4], stat[1], stat[5]);
		break;
	case 5: //wizard choice
		u = new Wizard(name, 4 + stat[3], stat[5], stat[2], stat[3], stat[1], stat[0], stat[4]);
		break;
	}
	u->Arm(); //player equips their weapon
	u->liststats(); //lists player's stats
	return 1;
}

