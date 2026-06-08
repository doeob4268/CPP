#include "pch.h"
#include "Part03.h"

Part03::Part03()
{
	Class();
}

void Part03::Class()
{
	Player p1();
	Player p2();
}

Player::Player(int id, int hp, int atk)
	: id(id), hp(hp), atk(atk)
{
	this->id = id;
	this->hp = hp;
	this->atk = atk;
}
