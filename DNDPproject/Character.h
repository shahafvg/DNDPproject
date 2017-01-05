#pragma once
#include <iostream>
#include "Monster.h"
using namespace std;

class Character
{
public:
	virtual ~Character() {};
	int getStr() {return STR;};
	int getDex() {return DEX;};
	int getHP() {return HP;};
	int getDef() {return DEF;};
	int getInt() {return INT;};
	void setDex(int DEX) {Character::DEX=DEX;};
	void setInt(int INT) {Character::INT=INT;};
	void setStr(int STR) {Character::STR=STR;};
	void setHp(int HP) {Character::HP=HP;};
	void setDef(int DEF) {Character::DEF=DEF;};
	virtual void Attack(Monster * enemy) =0; //need to create Monster first...
	virtual int DMG()  =0;//damage of each character
private:
	int STR;
	int DEX;
	int HP;
	int DEF;
	int INT;
};