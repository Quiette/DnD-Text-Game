// DnD Text Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <time.h> 


int main()
{
	int choice = 0;
	int stat[6];
	string name;
	srand(time(0));
	start(choice, false, stat);
	nameselect(name);
	Class* u = 0;
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
	u->Arm();
	u->liststats();
	return 1;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
