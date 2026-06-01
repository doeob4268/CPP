#include "pch.h"
#include "Part02.h"

Part02::Part02()
{
	//Overloading();
	//Reference();
	RandomEngine();
}

void Part02::Overloading()
{
	int a = 10, b = 20, c = 30;

	cout << "===== 함수 오버로딩 결과 =====\n";
	cout << "숫자 2개 합계 : " << GetSumValue(a, b) << '\n';
	cout << "숫자 3개 합계 : " << GetSumValue(a, b, c) << '\n';
	cout << "숫자 2개 평균 : " << GetAvr(a, b) << '\n';
	cout << "숫자 3개 평균 : " << GetAvr(a, b, c) << '\n';
}

void Part02::Reference()
{
	int val = 0;
	int* ptr = &val;
	*ptr = 10;

	cout << "===== 간접 참조 결과 =====\n";
	cout << "Value : " << val << ", " << &val << '\n';
	cout << "Ptr : " << *ptr << ", " << ptr << "\n\n";

	int& ref = val;
	ref = 20;

	cout << "===== 레퍼런스 결과 =====\n";
	cout << "Value : " << val << ", " << &val << '\n';
	cout << "Ref : " << ref << ", " << &ref << "\n\n";

	int a = 10, b = 20;

	cout << "===== 값 교환 전 =====\n";
	cout << a << ", " << b << "\n\n";

	SwapByRef(a, b);

	cout << "===== 값 교환 후 =====\n";
	cout << a << ", " << b << '\n';
}

void Part02::RandomEngine()
{
	random_device randomDevice;
	mt19937 generator(randomDevice());

	uniform_int_distribution<int> uniformIntDist(1, 100);

	constexpr int len = 10;

	int arr[len]{};


	for (int i = 0; i < len; ++i)
	{
		arr[i] = uniformIntDist(generator);
	}

	cout << "===== 정수형 배열 원소 (균등 분포) =====\n";
	for (int i = 0; i < len; ++i)
		cout << arr[i] << ", ";
}

int Part02::GetSumValue(int a, int b)
{
	return a + b;
}

int Part02::GetSumValue(int a, int b, int c)
{
	return a + b + c;
}

void Part02::SwapByRef(int& ref1, int& ref2)
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}
