#include "pch.h"
#include "Part01.h"

Part01::Part01()
{
	//IOStream();
	OutputStream();
}

void Part01::IOStream()
{
	cout << "Hello, World!\n";

	cout << "Int: " << num << ", Float: " << fltNum << '\n';

	cout << "\n데이터 입력 (정수) : ";
	cin >> num;

	cout << '\n' << num << " * " << num << " = " << num * num << '\n';
}

void Part01::OutputStream()
{
	cout.width(18);
	cout.fill('=');
	cout << " 자릿수 ";
	cout.width(11);
	cout << '\n';

	cout.precision(5);
	cout << "Int: " << num << ", Float: " << fltNum << '\n';
	cout << "RoundOff1: " << 1.23454 << '\n';
	cout << "RoundOff2: " << 1.23455 << '\n';

	cout.precision(10);
	cout << "\nBasic: " << 3.141592;
	cout << "\nShowPoint: " << showpoint << 3.141592 << noshowpoint; //precision, showpoint 바꾸기 전까지 계속 유지됨
	cout << "\nFixed: " << fixed << 3.141592;//fixed는 precision으로 설정한 값으로 
}

void Part01::InputStream()
{
}
