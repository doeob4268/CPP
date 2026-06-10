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

	cout << "===== 공격 전 =====\n";
	cout << "player1 : " << player1.GetHP() << ", " << player1.GetATK() << '\n';
	cout << "player2 : " << player2.GetHP() << ", " << player2.GetATK() << '\n';



	cout << "\n===== player1 공격 결과 =====\n";
	cout << "player1 : " << player1.GetHP() << ", " << player1.GetATK() << '\n';
	cout << "player2 : " << player2.GetHP() << ", " << player2.GetATK() << '\n';



	cout << "\n===== player2 공격 결과 =====\n";
	cout << "player1 : " << player1.GetHP() << ", " << player1.GetATK() << '\n';
	cout << "player2 : " << player2.GetHP() << ", " << player2.GetATK() << '\n';
}

Player::Player(int id, int hp, int atk)
	: id(id), hp(hp), atk(atk)
{
	cout << "Player(int, int, int) 생성자 실행 완료!\n";
}
