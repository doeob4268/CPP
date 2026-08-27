#include "pch.h"
#include "Part07.h"

Part07::Part07()
{
	FuncTemplate();
	//LinkedListClassTemplate();
	//SingletonClassTemplate();
	//ClassTemplateSpecialization();
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
//함수템플릿은 함수의 기능은 같지만 자료형만 다를때 자료형을 미리 정하지말고 함수가 시작할때 컴파일러가 자동으로 맞는 타입을 정해주는 기능

//함수템플릿은 인자로 타입을 자동으로 추론할 수 있지만 
// 클래스 템플릿은 대부분 타입을 지정해줘야함

//완전 특수화는 내가 정한 자료형으로 모두 고정한다는거고 

//부분 특수화는 내가 정한 자료형을 일부만 고정하거나 조건을 거는거다

//======================================================================================

//연결리스트를 하기전에 배열리스트 부터 보자면 배열리스트는 메모리가 순서대로 채워지고 값을 추가하거나 제거할때 [ 1 | 3 | 4 | 5 | 6 ] 로 표현할때 2를 2번째 칸에 넣고싶으면 3 4 5 6이 한칸씩 밀려나서 [ 1 |   | 3 | 4 | 5 | 6 ] 시간이 오래걸린다 삭제도 똑같음
//그래도 장점은 있는데 순서만 알면 바로 접근 가능해서(임의접근) 탐색이 빠르다 그게 장점이다 ( O{1} )

//연결리스트는 연속으로 저장하는 구조가 아니고 데이터와 다음 데이터의 주소를 노드로 연결하여 관리하는 구조[ 1 ]-[ 3 ]-[ 4 ]-[ 5 ]-[ 6 ] 이런식으로 저장 그래서 추가 제거는 그냥 추가만 하면 되서 빠름 [ 1 ]-[ 2 ]-[ 3 ]-[ 4 ]-[ 5 ]-[ 6 ]
//하지만 단점은 접근을 할때 순서대로 접근을 해야해서 (순차접근) 오래걸린다

//기본적으로 배열리스트를 많이 쓰지만 중간 값을 자주 바꾸는 경우는 연결리스트를 쓰는게 좋다

//====================================================================================