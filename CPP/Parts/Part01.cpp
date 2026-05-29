#include "pch.h"
#include "Part01.h"

Part01::Part01()
{
	//IOStream();
	//OutputStream();
	InputStream();
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
	cout << "\nDefaultFloat: " << defaultfloat << 3.141592;//기본값으로 돌아가기
	cout << "\nScientific: " << scientific << 3.1415926546897932384626433832 << '\n';

}

void Part01::InputStream()
{
	cout << "정수 입력 : ";
	cin >> num;
	cout << "결과 : " << num << '\n';

	cout << "실수 입력 : ";
	cin >> fltNum;
	cout << "결과 : " << fltNum << '\n';
	cin.ignore(numeric_limits<streamsize>::max(), '\n');


	char string[100] = "";
	cout << "\n문자열 입력 : ";
	//cin >> string;
	cin.getline(string, sizeof(string));
	cout << "결과 : " << string;
}