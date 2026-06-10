#pragma once

class Player
{
public:
	Player() : Player(1, 0, 0) { cout << "Player() 생성자 실행 완료!\n"; }
	Player(int id, int hp, int atk);

	void Attack();

	// Getter
	int GetID() const { return id; }
	int GetHP() const { return hp; }
	int GetATK() const { return atk; }


	// Setter
	void SetHP(int hp) { (*this).hp = hp; }		 //둘이 똑같이 작용함
	void SetATK(int atk) { this->atk = atk; }	 //둘이 똑같이 작용함

private:
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