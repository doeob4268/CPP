#pragma once

namespace Part06_StaticMember
{
	class Widget
	{
	public:
		//Widget() : value(0) {}

		int GetValue() const { return value; }//비정적 멤버
		static int GetStaticMemValue() { return staticValue; }//정적멤버에만 접근할수있다 . this의 getvalue도 안된다
		//쓰는 이유 : 
		void SetValue(int value) { this->value = value; }
		void SetStaticMemValue(int value) { staticValue = value; }

	private:
		int value = 0;
		static int staticValue;//스태틱이여서 데이터 영역에 저장된다
	};
}

namespace Part06_Singleton
{

}

class Part06
{
public:
	Part06();

private:
	void StaticMember();
	void Singleton();
};