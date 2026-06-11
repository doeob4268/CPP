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

	player1.Attack(player2);// player1이 player2를 공격

	cout << "\n===== player1 공격 결과 =====\n";
	cout << "player1 : " << player1.GetHP() << ", " << player1.GetATK() << '\n';
	cout << "player2 : " << player2.GetHP() << ", " << player2.GetATK() << '\n';

	player2.Attack(player1);// player2가 player1을 공격

	cout << "\n===== player2 공격 결과 =====\n";
	cout << "player1 : " << player1.GetHP() << ", " << player1.GetATK() << '\n';
	cout << "player2 : " << player2.GetHP() << ", " << player2.GetATK() << '\n';
}

Player::Player(int id, int hp, int atk)
	: id(id), hp(hp), atk(atk)
{
	cout << "Player(int, int, int) 생성자 실행 완료!\n";
}
void Player::Attack(Player& target)
{
	cout << "\nPlayer" << id << "이(가) Player" << target.GetID() << "을(를) 공격!\n";// 공격 메시지 출력
	target.SetHP(target.GetHP() - atk);// 대상의 HP를 공격력만큼 감소
}
