#pragma once

class Player
{
public://속성
	Player(int id, int hp, int atk);

private://기능
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