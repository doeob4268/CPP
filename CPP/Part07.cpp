#include "pch.h"
#include "Part07.h"

Part07::Part07()
{
	//FuncTemplate();
	//LinkedListClassTemplate();
	//SingletonClassTemplate();
	ClassTemplateSpecialization();
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

	constexpr int len = 20;

	int* intArr = MakeArr<int>(len);
	float* fltArr = MakeArr<float>(len);

	for (int i = 0; i < len; ++i)
	{
		intArr[i] = i + 1;
		fltArr[i] = i + 1.5f;
	}

	cout << "===== MakeArr 결과 =====\n";
	cout << "Int : ";
	for (int i = 0; i < len; ++i)
		cout << intArr[i] << ", ";

	cout << "\nFloat : ";
	for (int i = 0; i < len; ++i)
		cout << fltArr[i] << ", ";

	cout << '\n';

	SAFE_DELETE_ARRAY(fltArr);
	SAFE_DELETE_ARRAY(intArr);
}

void Part07::LinkedListClassTemplate()
{
	using namespace Part07_LinkedListClassTemplate;


}

void Part07::SingletonClassTemplate()
{
	using namespace Part07_SingletonClassTemplate;

	Widget& widget = Widget::Get();
	cout << '\n';

	widget.ShowInfo();
	cout << '\n';
	widget.ShowInfo();
	cout << '\n';
	widget.ShowInfo();
	cout << '\n';
}

void Part07::ClassTemplateSpecialization()
{
	using namespace Part07_ClassTemplateSpecialization;

	Datas<string, string> data1;
	cout << '\n';
	Datas<int, string> data2;
	cout << '\n';
	Datas<int, float> data3;
	cout << '\n';
}