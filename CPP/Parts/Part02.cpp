#include "pch.h"
#include "Part02.h"

Part02::Part02()
{
	Overloading();
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

int Part02::GetSumValue(int a, int b)
{
	return a + b;
}

int Part02::GetSumValue(int a, int b, int c)
{
	return a + b + c;
}
