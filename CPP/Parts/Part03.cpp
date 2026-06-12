#include "pch.h"
#include "Part03.h"

Part03::Part03()
{
	Class();
}

void Part03::Class()
{
	Player player1;
	player1.SetHP(100);
	player1.SetATK(15);

	cout << '\n';
	Player player2(2, 50, 35);

	cout << "\n===== 공격 전 =====\n";
	cout << "player1 : " << player1.GetHP() << ", " << player1.GetATK() << '\n';
	cout << "player2 : " << player2.GetHP() << ", " << player2.GetATK() << '\n';

	player1.Attack(player2);

	cout << "\n===== player1 공격 결과 =====\n";
	cout << "player1 : " << player1.GetHP() << ", " << player1.GetATK() << '\n';
	cout << "player2 : " << player2.GetHP() << ", " << player2.GetATK() << '\n';

	player2.Attack(player1);

	cout << "\n===== player2 공격 결과 =====\n";
	cout << "player1 : " << player1.GetHP() << ", " << player1.GetATK() << '\n';
	cout << "player2 : " << player2.GetHP() << ", " << player2.GetATK() << '\n';

	cout << '\n';

	*(player1.ptr) = 30;
}

Player::Player(int id, int hp, int atk)
	: id(id), hp(hp), atk(atk)
{
	ptr = new int(15);

	cout << "Player(int, int, int) 생성자 실행 완료!\n";
}

Player::~Player()
{
	delete(ptr);
	cout << "~Player() 소멸자 실행 완료!\n";
}

void Player::Attack(Player& otherPlayer)
{
	otherPlayer.hp -= atk;
}
