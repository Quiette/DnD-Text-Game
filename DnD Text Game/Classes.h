#pragma once
#include <string>

using namespace std;

class Class {
protected:
	string name;
	int AC;
	int maxhp; int currenthp;
	int str;int dex;int con;int wis;int intel;int cha;
	string type;
public:
	string showtype()const { return type; }
	virtual int attack() { return rand() % 21 + str; }
	virtual bool hit(int h){ return (h > AC); }
	virtual void dmg(int d) { currenthp = currenthp - d; if (currenthp <= 0) { death(); } }
	virtual void Arm() {}
	//virtual void specialability() {}
	void liststats(){
		cout << "STR: " << str << "	DEX: " << dex << "	CON: " << con << "	WIS: "
			<< wis << "	INT: " << intel << "	CHA: " << cha << "\n";
		cout << "MAX HP: " << maxhp << "	CUR HP: " << currenthp << "\n";
	}
	void death() {}

	Class(string nm,int mhp, int st, int de, int co, int wi, int inte, int ch, int AC)
		:  name(nm),maxhp(mhp), currenthp(mhp), str(st), dex(de), con(co), wis(wi), intel(inte), cha(ch) {}
};

class Paladin : public Class{
private:
	string weapon;
	//void detectevil();
public:
	Paladin(string nm, int mhp, int st, int de, int co, int wi, int inte, int ch)
		: Class(nm, mhp, st, de, co, wi, inte, ch, 10 + 5 + de / 2) {weapon = "sword"; type = "Pal";}
	virtual void Arm() { cout << "You draw your " << weapon << ".\n"; }
	//virtual void specialability() { detectevil();}
};

class Rogue : public Class {
private:
	string weapon;
	//void flank();
public:
	Rogue(string nm, int mhp, int st, int de, int co, int wi, int inte, int ch)
		: Class(nm, mhp, st, de, co, wi, inte, ch, 10 + 3+ de / 2) {weapon = "daggers"; type = "Rog";}
	virtual void Arm() { cout << "You draw your " << weapon << ".\n"; }
	//virtual void specialability() { flank(); }
};

class Ranger : public Class {
private:
	string weapon;
	int arrows;
public:
	Ranger(string nm, int mhp, int st, int de, int co, int wi, int inte, int ch)
		: Class(nm, mhp, st, de, co, wi, inte, ch, 10 + 2 + de / 2) {
		weapon = "bow";
		arrows = 20;
		type = "Ran";
	}
	virtual int attack() {if (arrows <= 0) { cout << "You have no more arrows!\n"; return 0; } arrows--; return rand() % 20 +1 + str;}
	virtual void Arm() { cout << "You draw your " << weapon << " and nock an arrow.\n"; }
};

class Monk : public Class {
private:
public:
	Monk(string nm, int mhp, int st, int de, int co, int wi, int inte, int ch)
		: Class(nm, mhp, st, de, co, wi, inte, ch, 10 + de / 2) {type = "Mon";}
	virtual void Arm() { cout << "You raise your fists and enter a fighting stance.\n"; }
};

class Wizard : public Class {
private:
public:
	Wizard(string nm, int mhp, int st, int de, int co, int wi, int inte, int ch)
		: Class(nm, mhp, st, de, co, wi, inte, ch, 10 + de / 2) {
		type = "Wiz";}
	virtual void Arm() { cout << "You raise your arm and bekon to your magic.\n"; }
};

