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
	derived.PrintInfo();	////Derived 클래스의 PrintInfo() 함수를 호출한다. 자식 클래스에서	 클래스의 PrintInfo()를 호출하도록 작성되어 있다면 정수와 실수 정보를 출력한 뒤 문자열 정보도 출력함					
	cout << '\n';								
	//보면 동물이 base 거기에 뿔달린 동물은 derived 이런식이이여서 상속을 받는거같음 그래서 derived.PrintInfo();하면 base의 PrintInfo()도 같이 실행되는거임									
	Base* baseDerived = new Derived(20, 6.28f, "Hello!");//실제 객체는 Derived이지만 부모 클래스인 Base의 포인터로 가리킬 수 있다. 이를 통해 부모 클래스 포인터로 자식 객체를 다룰 수 있
	cout << '\n';
	baseDerived->PrintInfo();//baseDerived 포인터를 통해 PrintInfo() 함수를 실행한다. baseDerived가 가리키는 실제 객체는 Derived이지만, 포인터의 자료형은 Base*이고 PrintInfo()가 virtual로 선언되어 있지 않기 때문에 부모 클래스인 Base의 PrintInfo()가 실행되어 정수와 실수만 출력함
	cout << '\n';

	SAFE_DELETE(baseDerived);
	cout << '\n';
}

void Part04::Polymorphsim()
{
	using namespace Part04_Polymorphism;

	Base* base1 = new Base();//Base 객체를 동적으로 생성하고, 그 주소를 Base*형 포인터 변수 base1에 저장한다. Base* base2 = new SubDerived();는 SubDerived 객체를 생성하지만 부모 클래스인 Base*형 포인터로 해당 객체의 주소를 저장함
	cout << '\n';
	Base* base2 = new SubDerived();//이것도 SubDerived가 Derived를 상속받고 Derived가 Base를 상속받으니깐 출력에 Derived 생성자 까지 같이 출력됨 
	cout << '\n';//실제 객체는 SubDerived이므로 객체 생성 과정에서 Base, Derived, SubDerived 순서로 생성자가 실행

	Derived* derived1 = new SubDerived();
	cout << '\n';
	Derived* derived2 = dynamic_cast<Derived*>(base2);//base2가 가리키는 객체를 Derived*형으로 변환한다. 실제 객체가 SubDerived이고 Derived를 상속받았으므로 변환할수있다
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