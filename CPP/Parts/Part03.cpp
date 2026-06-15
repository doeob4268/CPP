#include "pch.h"
#include "Part03.h"

#define DEF_LEN 5

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

	cout << '\n';
	Player player3(3, 0, 0);
	cout << '\n';
	player3 = player2;

	cout << "\n===== 공격 전 =====\n";
	cout << "player1 : " << player1.GetHP() << ", " << player1.GetATK() << '\n';
	cout << "player2 : " << player2.GetHP() << ", " << player2.GetATK() << '\n';
	cout << "player3 : " << player3.GetHP() << ", " << player3.GetATK() << '\n';

	player1.Attack(player2);

	cout << "\n===== player1 공격 결과 =====\n";
	cout << "player1 : " << player1.GetHP() << ", " << player1.GetATK() << '\n';
	cout << "player2 : " << player2.GetHP() << ", " << player2.GetATK() << '\n';
	cout << "player3 : " << player3.GetHP() << ", " << player3.GetATK() << '\n';

	player2.Attack(player1);

	cout << "\n===== player2 공격 결과 =====\n";
	cout << "player1 : " << player1.GetHP() << ", " << player1.GetATK() << '\n';
	cout << "player2 : " << player2.GetHP() << ", " << player2.GetATK() << '\n';
	cout << "player3 : " << player3.GetHP() << ", " << player3.GetATK() << '\n';

	cout << '\n';
}

Player::Player(int id, int hp, int atk)
	: id(id), hp(hp), atk(atk), ptr(new int(15))
	, arr(new int[DEF_LEN] { 1, 2, 3, 4, 5 })
{
	cout << "Player(int, int, int) 생성자 실행 완료!\n";
}

Player::Player(const Player& other)
	: hp(other.hp)
	, atk(other.atk)
	, ptr(other.ptr != nullptr ? new int(*other.ptr) : nullptr)
	, arr(other.arr != nullptr ? new int[DEF_LEN] : nullptr)
	, id(other.id)
{
	if (arr != nullptr)
		 memcpy(arr, other.arr, sizeof(int) * DEF_LEN);

	cout << "Player(const Player&) 복사생성자 실행 완료!\n";
}

Player& Player::operator=(const Player& other)
{
	hp = other.hp;
	atk = other.atk;

	SAFE_DELETE_ARRAY(arr);
	SAFE_DELETE(ptr);



	ptr = new int(*other.ptr);
	arr = new int[DEF_LEN];
	memcpy(arr, other.arr, sizeof(int) * DEF_LEN);

	cout << "operator=(const Player&) 복사대입연산자 실행 완료!\n";

	return *this;
}

Player::~Player()
{
	SAFE_DELETE_ARRAY(arr);
	SAFE_DELETE(ptr);

	cout << "~Player() 소멸자 실행 완료!\n";
}

void Player::Attack(Player& otherPlayer)
{
	otherPlayer.hp -= atk;
}
