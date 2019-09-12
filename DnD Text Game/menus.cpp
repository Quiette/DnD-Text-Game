#include "pch.h"
#include "menus.h"
#include "Classes.h"
#include <iostream>
using namespace std;

//Intro Menu. Selects Class and finds stats
void start(int &choice, bool statsmade, int st []){
	bool confirm = false;
	cout <<"Welcome to your Dungeons and Dragon Adventure!\n";
	cout << "Choose your class (Press the corresponding number):\n";
	cout << "1. Paladin		2. Rogue		3. Ranger 		4. Monk 		5. Wizard\n";
	cin >> choice;
	while (cin.fail() ||choice < 1 || choice>5 ) { //invalid choice
		cin.clear(); //clear error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear entry until "\n"
		cout << "That is not a valid class option, Brave Hero.\n";
		cout << "Choose your class (Press the corresponding number):\n";
		cout << "1. Paladin		2. Rogue		3. Ranger 		4. Monk 		5. Wizard\n";
		cin >> choice;
	}
	cout << "You have picked: ";
	if (statsmade == false){ //if no stats created, create stats; if created don't allow for rerolling/minmaxing
		setstatarray(st);
		statsmade = true;
	}
	
	string cl;
	switch(choice) {
		case 1: //paladin choice
			cl = "PALADIN";
			cout << cl << "\n";
			statbreakdown(st, 1);
			break;
		case 2:  //rougue choice
			cl = "ROGUE";
			cout << cl << "\n";
			statbreakdown(st, 2);
			break;
		case 3:  //ranger choice
			cl = "RANGER";
			cout << cl << "\n";
			statbreakdown(st, 3);

			break;
		case 4: //monk choice
			cl = "MONK";
			cout << cl << "\n";
			statbreakdown(st, 4);
			break;
		case 5: //wizard choice
			cl = "WIZARD";
			cout << cl << "\n";
			statbreakdown(st, 5);
			break;
		}
	cout << "Please press ENTER to confirm your class choice, or any other key to go back to class selection.\n";
	cin.ignore();
	if (cin.get()=='\n') {
		cout << "Thank you for confirming. You have chosen the " << cl << " class\n";
	}
	else {
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear entry until "\n"
		start(choice, true, st);
	}
	return;
}

//Gives player a name
void nameselect(string &name){
	cout << "What is the name of the hero that the legends speak about?\n";
		cin >> name;
		while (cin.fail()) {
			cout << "That doesn't sound like a hero's name!\n";
			cout << "What is the name of the hero that the legends speak about?\n";
			cin >> name;
		}
	
		cout << "Welcome, " << name << ", to your adventure! May the gods be with you.\n";
}
