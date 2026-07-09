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

namespace Part04_Polymorphism
{
	class Base
	{
	public:
		Base() { cout << "Base() 생성자 실행 완료!\n"; }
		virtual ~Base() { cout << "~Base() 소멸자 실행 완료!\n"; }

		virtual void ShowInfo() const;
	};

	class Derived : public Base
	{
	public:
		Derived() { cout << "Derived() 생성자 실행 완료!\n"; }
		~Derived() override { cout << "~Derived() 소멸자 실행 완료!\n"; }

		void ShowInfo() const override;

	protected:
		virtual void DoShowInfo() const = 0;
	};

	class SubDerived final : public Derived
	{
	public:
		SubDerived() { cout << "SubDerived() 생성자 실행 완료!\n"; }
		~SubDerived() override { cout << "~SubDerived() 소멸자 실행 완료!\n"; }

		int GetValue() const { const_cast<SubDerived*>(this)->val = 20; return val; }//const_cast = const때문에 값을 못바꿀때 const_cast로 바꾼다 *과도하게 쓰지 말것*
		int GetValue() { val = 10;  return val; }

		int GetSumValue(const SubDerived& a, SubDerived& b);

		void SetValue(int val) { this->val = val; }

	protected:
		void DoShowInfo() const override;

	private:
		int val = 0;
	};
}

class Part04
{
public:
	Part04();

private:
	void Inheritance();
	void Polymorphsim();
};