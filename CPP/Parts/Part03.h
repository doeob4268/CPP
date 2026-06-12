#pragma once

class Player
{
public:
	Player() : Player(1, 0, 0) { cout << "Player() 생성자 실행 완료!\n"; }
	Player(int id, int hp, int atk);

	~Player();

	void Attack(Player& otherPlayer);

	// Getter
	int GetID() const { return id; }
	int GetHP() const { return hp; }
	int GetATK() const { return atk; }

	// Setter
	void SetHP(int hp) { (*this).hp = hp; }
	void SetATK(int atk) { this->atk = atk; }
	int* ptr = nullptr;

private:
	int hp = 0;
	int atk = 0;

	int* arr = nullptr;

	const int id;
};

class Part03
{
public:
	Part03();

private:
	void Class();
};