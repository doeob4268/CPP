#include "pch.h"
#include "Part04.h"

Part04::Part04()
{
	//Inheritance();
	Polymorphsim();
}

void Part04::Inheritance()
{
	using namespace Part04_Inheritance;

	Base base(10, 3.14f);//객체 생성 -> Base(int, float) 생성자 실행 완료! 출력
	cout << '\n';
	base.PrintInfo();//기반 객체 정보 출력
	cout << '\n';

	Derived derived(3, 0.1f, "Hello, World!\n");
	cout << '\n';
	derived.PrintInfo();//파생 객체 -> 기반 객체 정보 + @(hello world) -> base(int, float) 생성자 실행 완료! 
	cout << '\n';

	Base* baseDerived = new Derived(20, 6.28f, "Hello!");
	cout << '\n';
	baseDerived->PrintInfo();
	cout << '\n';
}

void Part04::Polymorphsim()
{
	using namespace Part04_Polymorphism;

	Base* base1 = new Base();
	cout << '\n';
	Base* base2 = new Derived();
	cout << '\n';

	base1->ShowInfo();
	cout << '\n';
	base2->ShowInfo();
	cout << '\n';

	SAFE_DELETE(base2);
	cout << '\n';
	SAFE_DELETE(base1);
	cout << '\n';
}

namespace Part04_Inheritance
{
	Base::Base(int num, float fltNum)
		: num(num), fltNum(fltNum)
	{
		cout << "Base(int, float) 생성자 실행 완료!\n";
	}

	Base::~Base()
	{
		cout << "~Base() 소멸자 실행 완료!\n";//함수가 끝나서 소멸자 실행 완료 -> 2번째로 출력 (derived함수) -> 3번쨰로	출력 (base함수)
	}

	void Base::PrintInfo() const
	{
		cout << "===== 기반 객체 정보 =====\n";
		cout << "Int : " << num << '\n';
		cout << "Float : " << fltNum << '\n';
	}

	Derived::Derived()
		: Derived(0, 0.0f, "")
	{
		cout << "Derived() 생성자 실행 완료!\n";
	}

	Derived::Derived(int num, float fltNum, const char* string)
		: Base(num, fltNum)
	{
		strcpy(this->string, string);
		cout << "Derived(int, float, const char*) 생성자 실행 완료!\n";
	}

	Derived::~Derived()
	{
		cout << "~Derived() 소멸자 실행 완료!\n"; //함수가 끝나서 소멸자 실행 완료 -> 소멸자중에서 제일 먼저 출력
	}

	void Derived::PrintInfo() const
	{
		Base::PrintInfo();

		cout << "===== 파생 객체 정보 =====\n";
		cout << "String : " << string << '\n';
	}
}

namespace Part04_Polymorphism
{
	void Base::ShowInfo()
	{
		cout << "Base::ShowInfo() 실행 완료!\n";
	}

	void Derived::ShowInfo()
	{
		cout << "Derived::ShowInfo() 실행 완료!\n";
	}
}