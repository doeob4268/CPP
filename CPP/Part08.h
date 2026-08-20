#pragma once

namespace Part08_SmartPointer
{
	class Widget
	{
	public:
		Widget() { cout << "Widget::Widget() 생성자 실행 완료!\n"; }
		~Widget() { cout << "Widget::~Widget() 소멸자 실행 완료!\n"; }
	};
}

class Part08
{
public:
	Part08();

private:
	void Auto();
	void RangeBaseFor();
	void AutoPtr();
	void UniquePtr();
};