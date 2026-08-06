#include "pch.h"
#include "Part04.h"

Part04::Part04()
{
	//Inheritance();
	Polymorphsim();
}

void Part04::Inheritance()//상속은 부모클래스의 속성을 자식클래스에 물려받는 내용인데 예로들면 코끼리는 자식 동물은 부모라고 가정하면 코끼리는 동물에 속하니깐 코끼리가 동물을 물려받는다로 생각하면 쉽다
{							//사용하면 코드의 재사용성이랑 유지보수성도 늘릴수있다 하지만 너무 많이 상속하면 복잡해질수도있음
	using namespace Part04_Inheritance;

	Base base(10, 3.14f);
	cout << '\n';
	base.PrintInfo();
	cout << '\n';

	Derived derived(3, 0.1f, "Hello, World!"); //base는 int flt 인 매개변수밖에 없는데 derived는 + string까지 있어서 더 큰 범위다
	cout << '\n';								//class Derived : public Base 헤더에 써있는건 derived클래스는 base에 상속받는다 라는 뜻인데 
	derived.PrintInfo();						//derived가 범위가 더 큰데 왜 상속을 받는거지? <--  생각 해보니깐 
	cout << '\n';								//base는 int flt고 derived는 +@ 인거니깐 전체적으로
	//보면 동물이 base 거기에 뿔달린 동물은 derived 이런식이이여서 상속을 받는거같음 그래서 derived.PrintInfo();하면 base의 PrintInfo()도 같이 실행되는거임									
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
	Base* base2 = new SubDerived();//이것도 SubDerived가 Derived를 상속받고 Derived가 Base를 상속받으니깐 출력에 Derived 생성자 까지 같이 출력됨 
	cout << '\n';

	Derived* derived1 = new SubDerived();
	cout << '\n';
	Derived* derived2 = dynamic_cast<Derived*>(base2);
	assert(derived2 != nullptr);//문제 발생시 미리 nullptr로 발견하는 코드

	base1->ShowInfo();//base1이 new Base()로 주소를 가리키고 있으니깐 Base::ShowInfo() 실행 완료! 출력하고 .이 아니라 ->를 쓰는 이유는 base1이 포인터이기 때문에 .을 쓰면 안됨
	cout << '\n';
	base2->ShowInfo();
	cout << '\n';
	derived1->ShowInfo();
	cout << '\n';
	derived2->ShowInfo();
	cout << '\n';

	cout << "GetSumValue : " << static_cast<SubDerived*>(derived1)->GetSumValue(*dynamic_cast<SubDerived*>(base2), *dynamic_cast<SubDerived*>(derived1));//dynamic_cast는 느리려서 static_cast를 써주면 좋다
	cout << "\n\n";

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