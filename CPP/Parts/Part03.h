#pragma once

class Player
{
public://기능
	Player(int id, int hp, int atk)
		: id(id), hp(hp), atk(atk)

private://속성
	int hp = 0;
	int atk = 0;

	const int id;

};

class Part03
{
public:
	Part03();

private:
	void Class();
};