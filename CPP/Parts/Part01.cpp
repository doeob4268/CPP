#include "pch.h"
#include "Part01.h"

Part01::Part01()
{
	//IOStream();
	OutputStream();
	//InputStream();
}

void Part01::IOStream()
{
	cout << "Hello, World!\n";// endl이랑 없는거랑 차이는 endl을 쓰면 자동으로 개행도(\n)도 출력되고 버퍼에 쌓인걸 즉시 내보냄 그냥 개행만 쓰는거는 프로그램이 끝날떄 버퍼가 사라져서 개행으로 하는거랑 endl이랑 대량출력할때 속도가 차이가 남 (개행만 쓰는게 빠름) 
	cout << "Int: " << num << ", Float: " << fltNum << '\n';

	cout << "\n데이터 입력 (정수) : ";
	cin >> num;

	cout << '\n' << num << " * " << num << " = " << num * num << '\n';
}

void Part01::OutputStream()
{
	cout.width(18);//width 함수를 호출하여 출력할 데이터의 너비를 지정한다. 지정한 너비가 실제 데이터의 길이보다 길면 남는 공간을 기본적으로 공백으로 채우는데 앞에서 부터 채워짐 그리고 데이터의 길이가 18칸보다 길면 데이터를 자르지 않고 그대로 출력한다.
	cout.fill('=');//함수를 호출하여 출력할 데이터의 너비가 지정된 경우 길이가 지정한 너비보다 짧아 남는 공간이 발생하면 =로 채워지게 한다 기본적으로 오른쪽 정렬이여서 데이터의 앞 부분 부터 채워진다
	cout << " 자릿수 ";
	cout.width(11);
	cout << '\n';

	cout.precision(5);//함수를 호출하여 실수 출력의 정밀도를 5자리로 지정한다 소수점부터 5자리까지만 출력 그리고 5자리 보다 긴 경우 반올림을 하여 출력한다
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