#pragma once

namespace Part04_Inheritance
{
	class Base
	{
	public:
		Base(int num, float fltNum);
		~Base();

		void PrintInfo() const;

	protected:
		int num = 0;
		float fltNum = 0.0f;
	};

	class Derived : public Base
	{
	public:
		Derived();
		Derived(int num, float fltNum, const char* string);
		~Derived();

		void PrintInfo() const;

	private:
		char string[100] = "";
	};
}

class Part04
{
public:
	Part04();

private:
	void Inheritance();
};