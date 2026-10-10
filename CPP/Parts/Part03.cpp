#include "pch.h"
#include "Part03.h"

#define DEF_LEN 5

Part03::Part03()
{
	Class();
}

void Part03::Class()
{
	Player player1;//Player라는 클래스를 자료형으로 사용하여 player1이라는 객체를 생성하는 코드이다. 클래스는 객체를 만들기 위한 설계도이며, player1그 객체다
	player1.SetHP(100);
	player1.SetATK(15);

	cout << '\n';
	Player player2(2, 50, 35);//Player 클래스에서 int형 매개변수 3개를 받는 생성자를 호출하여 player2 객체를 생성하는 코드이다. 클래스에 선언된 Player(int id, int hp, int atk); 생성자가 호출되며, 전달된 값 2, 50, 35는 각각ID, 체력, 공격력을 초기화하는 데 사용

	cout << '\n';
	Player player3(3, 0, 0);
	cout << '\n';
	player3 = player2;//이미 생성된 player3 객체에 player2 객체의 값을 대입하는 코드이다. 이때 클래스에 정의된 Player& operator=(const Player& other); 복사 대입 연산자 함수가 사용된다 새로운 객체를 만드는 것이 아니라 기존 player3 객체에 player2의 데이터를 대입하는 코드

	cout << "\n===== 공격 전 =====\n";
	cout << "player1 : " << player1.GetHP() << ", " << player1.GetATK() << '\n';//1, 100, 15
	cout << "player2 : " << player2.GetHP() << ", " << player2.GetATK() << '\n';//2, 50, 35
	cout << "player3 : " << player3.GetHP() << ", " << player3.GetATK() << '\n';//3, 50, 35

	player1.Attack(player2);//player1 객체의 Attack() 함수를 호출하여 player2 객체를 대상으로 공격 기능을 실행하는 코드이다. player2는 함수의 인자로 전달되며, 클래스에 선언된 void Attack(Player& otherPlayer);에서 otherPlayer가 player2 객체를 참조함

	cout << "\n===== player1 공격 결과 =====\n";
	cout << "player1 : " << player1.GetHP() << ", " << player1.GetATK() << '\n';
	cout << "player2 : " << player2.GetHP() << ", " << player2.GetATK() << '\n';//체력 35
	cout << "player3 : " << player3.GetHP() << ", " << player3.GetATK() << '\n';

	player2.Attack(player1);

	cout << "\n===== player2 공격 결과 =====\n";
	cout << "player1 : " << player1.GetHP() << ", " << player1.GetATK() << '\n';//체력 65
	cout << "player2 : " << player2.GetHP() << ", " << player2.GetATK() << '\n';//체력 35 유지
	cout << "player3 : " << player3.GetHP() << ", " << player3.GetATK() << '\n';

	cout << '\n';
}

Player::Player(int id, int hp, int atk)//Player 클래스의 생성자를 정의하는 코드로, 정수형 매개변수 3개를 전달받아 객체를 생성할 때 실행된다. : id(id), hp(hp), atk(atk)는 전달받은 매개변수의 값을 각각 멤버 변수 id, hp, atk에 초기화하는 부분
	: id(id), hp(hp), atk(atk), ptr(new int(15))//ptr(new int(15))는 정수 하나를 저장할 메모리를 동적으로 할당하고 그 공간에 15를 저장한 뒤, 해당 메모리 주소를 ptr에 저장
	, arr(new int[DEF_LEN] { 1, 2, 3, 4, 5 })
{
	cout << "Player(int, int, int) 생성자 실행 완료!\n";
}

Player::Player(const Player& other)//Player 클래스의 복사 생성자로, 기존 Player 객체인 other의 데이터를 복사하여 새로운 객체를 생성하는 코드이다. hp, atk, id는 기존 객체의 체력과 공격력을 복사
	: hp(other.hp)
	, atk(other.atk)
	, ptr(other.ptr != nullptr ? new int(*other.ptr) : nullptr)//other.ptr이 nullptr이 아니라면 새로운 정수형 메모리를 할당하고, 기존 포인터가 가리키는 값을 복사하여 저장하고 반대로 other.ptr이 nullptr이면 새로운 ptr도 nullptr로 초기화
	, arr(other.arr != nullptr ? new int[DEF_LEN] : nullptr)//other.arr이 nullptr이 아니라면 DEF_LEN에 지정된 개수만큼 정수형 배열을 저장할 새로운 메모리를 할당하는 코드
	, id(other.id)
{
	if (arr != nullptr)
		memcpy(arr, other.arr, sizeof(int) * DEF_LEN);//memcpy는 메모리에 저장된 데이터를 다른 메모리 공간으로 복사하는 함수인데 / 기존 배열 other.arr의 데이터를 새 배열 arr에 DEF_LEN개만큼 복사하는 코드이다.

	cout << "Player(const Player&) 복사생성자 실행 완료!\n";
}

Player::Player(Player&& other) noexcept//기존 객체 other의 데이터를 새 객체로 이동하는 이동 생성자
	: hp(other.hp) //hp랑 atk은 기존 객체에 새 객체에 복사하고 기존에 있던 객체를 0으로 초기화
	, atk(other.atk)
	, ptr(other.ptr)//ptr이랑 arr 기존 객체에 저장된 메모리 주소를 새 객체에 전달하고 기존 객체의 ptr을 nullptr로 초기화해서 이동 시킨다
	, arr(other.arr)
	, id(other.id)//id는 const int로 선언되어 있어 한 번 초기화하면 값을 변경할 수 없으므로, 생성자의 초기화 목록에서 값을 설정해서 이동
{
	other.hp = 0;
	other.atk = 0;
	other.ptr = nullptr;
	other.arr = nullptr;

	cout << "Player(Player&&) 이동생성자 실행 완료!\n";
}

Player& Player::operator=(Player&& other) noexcept//기존에 생성된 객체에 다른 객체의 데이터를 이동하여 대입하는 이동 대입 연산자
{
	if (this == &other)
		return *this;

	SAFE_DELETE_ARRAY(arr);//현재 객체가 기존에 사용하던 배열과 정수형 메모리를 해제
	SAFE_DELETE(ptr);

	hp = other.hp;//다른 객체의 체력과 공격력을 현재 객체에 복사하고 다른 객체를 0으로 초기화
	atk = other.atk;
	ptr = other.ptr;//상대 객체가 가지고 있던 메모리 주소를 현재 객체에 전달하고 상대객체의 포인터를 nullptr로 초기화하여 더 이상 해당 메모리를 가리키지 않도록 한다.
	arr = other.arr;

	other.hp = 0;
	other.atk = 0;
	other.ptr = nullptr;
	other.arr = nullptr;

	cout << "operator=(Player&&) 이동대입연산자 실행 완료!\n";

	return *this;
}

Player& Player::operator=(const Player& other)//복사 대입 연산자야. 이미 존재하는 객체에 다른 객체의 데이터를 복사해서 넣음
{
	if (this == &other)
		return *this;

	hp = other.hp;//other 객체의 HP와 공격력을 현재 객체에 복사
	atk = other.atk;

	SAFE_DELETE_ARRAY(arr);//현재 객체가 기존에 사용하던 동적 메모리를 해제 / 기존 메모리를 정리하지 않고 새 메모리를 할당하면 메모리 누수가 나서
	SAFE_DELETE(ptr);

	ptr = other.ptr != nullptr ? new int(*other.ptr) : nullptr;//새로운 정수 메모리를 만들고, 그 안에 기존 값을 복사

	if (other.arr != nullptr)//새로운 배열 메모리를 만들고, memcpy()로 배열 안의 데이터를 복사
	{
		arr = new int[DEF_LEN];
		memcpy(arr, other.arr, sizeof(int) * DEF_LEN);
	}
	else
		arr = nullptr;

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
