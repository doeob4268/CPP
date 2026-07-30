#include "pch.h"
#include "Part06.h"

int Part06_StaticMember::Widget::staticValue = 0;//초기화 할떄 0이라는 값이 들어감

Part06::Part06()
{
	StaticMember();
}

void Part06::StaticMember()//멤버변수는 객체에 따라 저장된다
{
	using namespace Part06_StaticMember;

	Widget widget1;
	Widget widget2;

	widget1.SetValue(10);
	widget2.SetValue(20);

	widget1.SetStaticMemValue(20);
	widget2.SetStaticMemValue(30);

	cout << "===== 클래스 변수 조작 결과 =====\n";
	cout << "widget1 : " << widget1.GetValue() << ", " << widget1.GetStaticMemValue() << '\n';//객체생성 없이도 함수를 호출할수있다, 정적멤버 함수만 가능, :: 범위 확인 연산자, 범위는 정해줘야한다
	cout << "widget1 : " << widget2.GetValue() << ", " << widget2.GetStaticMemValue() << '\n';
}

void Part06::Singleton()
{

}