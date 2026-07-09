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

	Base base(10, 3.14f);
	cout << '\n';
	base.PrintInfo();
	cout << '\n';

	Derived derived(3, 0.1f, "Hello, World!");
	cout << '\n';
	derived.PrintInfo();
	cout << '\n';

	Base* baseDerived = new Derived(20, 6.28f, "Hello!");
	cout << '\n';
	baseDerived->PrintInfo();
	cout << '\n';

	SAFE_DELETE(baseDerived);
	cout << '\n';
}

void Part04::Polymorphsim()
{
	using namespace Part04_Polymorphism;

	Base* base1 = new Base();
	cout << '\n';
	Base* base2 = new SubDerived();
	cout << '\n';

	Derived* derived1 = new SubDerived();
	cout << '\n';
	Derived* derived2 = dynamic_cast<Derived*>(base2);
	assert(derived2 != nullptr);

	base1->ShowInfo();
	cout << '\n';
	base2->ShowInfo();
	cout << '\n';
	derived1->ShowInfo();
	cout << '\n';
	derived2->ShowInfo();
	cout << '\n';

	cout << "GetSumValue : " << dynamic_cast<SubDerived*>(derived1)->GetSumValue(*dynamic_cast<SubDerived*>(base2), *dynamic_cast<SubDerived*>(derived1));
	cout << '\n';

	short num = 10;
	//int* ptr = (int*)&num;
	int* ptr = static_cast<int*>(&num);
	*ptr = 20;

	SAFE_DELETE(derived1);
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
		cout << "~Base() 소멸자 실행 완료!\n";
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
		cout << "~Derived() 소멸자 실행 완료!\n";
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
	void Base::ShowInfo() const
	{
		cout << "Base::ShowInfo() 실행 완료!\n";
	}

	void Derived::ShowInfo() const
	{
		cout << "Derived::ShowInfo() 실행 완료!\n";
		this->DoShowInfo();
	}

	int SubDerived::GetSumValue(const SubDerived& a, SubDerived& b)
	{
		return a.GetValue() + b.GetValue();
	}

	void SubDerived::DoShowInfo() const
	{
		cout << "SubDerived::DoShowInfo() 실행 완료!\n";
	}
}