#include "pch.h"
#include "Part07.h"

Part07::Part07()
{
	FuncTemplate();
}

void Part07::FuncTemplate()
{
	using namespace Part07_FuncTemplate;

	int val1 = 10;
	int val2 = 20;

	float fltVal1 = 10.1f;
	float fltVal2 = 20.2f;

	string str1 = "ABCD";
	string str2 = "abcd";

	Data data1 = { 10, 10.1f };
	Data data2 = { 20, 20.2f };

	cout << "===== 교환 전 =====\n";
	cout << "Int : " << val1 << ", " << val2 << '\n';
	cout << "Float : " << fltVal1 << ", " << fltVal2 << '\n';
	cout << "String : " << str1 << ", " << str2 << '\n';
	cout << "Data : (" << data1.val << ", " << data1.fltVal << "), ("
		<< data2.val << ", " << data2.fltVal << ")\n\n";

	Swap(val1, val2);
	Swap(fltVal1, fltVal2);
	Swap(str1, str2);
	Swap(data1, data2);

	cout << "===== 교환 후 =====\n";
	cout << "Int : " << val1 << ", " << val2 << '\n';
	cout << "Float : " << fltVal1 << ", " << fltVal2 << '\n';
	cout << "String : " << str1 << ", " << str2 << '\n';
	cout << "Data : (" << data1.val << ", " << data1.fltVal << "), ("
		<< data2.val << ", " << data2.fltVal << ")\n\n";

	int* intArr = MakeArr<int>();//컴파일러가 자료형을 못알아볼때 직접 <int>를 넣는다 
	float* fltArr = MakeArr<float>();//인자값 안넣으면 10으로 초기화

	constexpr int len = 20;

	for (int i = 0; i < len; ++i)
	{
		intArr[i] = i + 1;
		fltArr[i] = i + 1.5f;
	}

	cout << "===== MakeArr 결과 =====\n";
	cout << "Int : ";
	for (int i = 0; i < len; ++i)
		cout << intArr[i] << ",";

	cout << "\nFloat :";
	for (int i = 0; i < len; ++i)
		cout << fltArr[i] << ",";

	cout << '\n';
}

void Part07::LinkedListClassTemplate()
{
	using namespace Part07_LinkedListClassTemplate;


}