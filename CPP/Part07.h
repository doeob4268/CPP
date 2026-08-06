#pragma once

namespace Part07_FuncTemplate
{
	struct Data
	{
		int val = 0;
		float fltVal = 0.0f;
	};
}

namespace Part07_LinkedListClassTemplate
{
	template <typename T>
	class LinkedList
	{

	};
}

class Part07
{
public:
	Part07();
	
	// 함수 템플릿
	template <typename T>//T는 그냥 이름
	void Swap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;

	}

	template <>//함수 템플릿은 특수화만 가능하다
	void Swap(Part07_FuncTemplate::Data& data1, Part07_FuncTemplate::Data& data2)//Data : (20, 10.1), (10, 20.2) val만 바뀜 <- 특수화
	{
		Swap(data1.val, data2.val);
	}

	template <typename T, int LEN = 10>//typename T <- 형식인자
	T* MakeArr(int len = LEN) { return new T[len]; }

private:
	void FuncTemplate();
	void LinkedListClassTemplate();
};