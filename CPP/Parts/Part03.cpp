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
	player1.SetHP(100);//player생성자에 player1이라는 객체의 체력을 100으로 지정
	player1.SetATK(15);//player생성자에 player1이라는 객체의 공격력을 15로 지정

	cout << '\n';
	Player player2(2, 50, 35);//player2 id, hp, atk 각각 2 50 35로 지정과 동시에 객체 생성

	cout << '\n';
	Player player3(3, 0, 0);//이것도 동시에 하는데 id만 3 나머지 0
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
	, ptr(other.ptr != nullptr ? new int(*other.ptr) : nullptr)		 //이 부분이 아래 arr ptr로 적용되게 완성해오기
	, arr(other.arr != nullptr ? new int[DEF_LEN] : nullptr)		 //이 부분이 아래 arr ptr로 적용되게 완성해오기
	, id(other.id)													 //이 부분이 아래 arr ptr로 적용되게 완성해오기
{																	 //이 부분이 아래 arr ptr로 적용되게 완성해오기
	if (arr != nullptr)												 //이 부분이 아래 arr ptr로 적용되게 완성해오기
		 memcpy(arr, other.arr, sizeof(int) * DEF_LEN);				 //이 부분이 아래 arr ptr로 적용되게 완성해오기

	cout << "Player(const Player&) 복사생성자 실행 완료!\n";
}
Player::Player(Player&& other) noexcept
	: hp(other.hp)
	, atk(other.atk)
	, ptr(other.ptr)
	, arr(other.arr)
	, id(other.id)
{
	other.hp = 0;
	other.atk = 0;
	other.ptr = nullptr;
	other.arr = nullptr;

	cout << "Player(Player&&) 이동생성자 실행 완료!\n";
}

Player& Player::operator=(Player&& other) noexcept
{
	// TODO: 여기에 return 문을 삽입합니다.
}

Player& Player::operator=(Player&& other) noexcept
{
	if (this == &other)
		return *this;

	SAFE_DELETE_ARRAY(arr);
	SAFE_DELETE(ptr);

	hp = other.hp;
	atk = other.atk;
	ptr = other.ptr;
	arr = other.arr;

	other.hp = 0;
	other.atk = 0;
	other.ptr = nullptr;
	other.arr = nullptr;

	cout << "operator=(Player&&) 이동대입연산자 실행 완료!\n";

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
