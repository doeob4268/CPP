#include "pch.h"
#include <iomanip>
#include "Part08.h"

Part08::Part08()
{
	//Auto();
	//RangeBaseFor();
	AutoPtr();
}

void Part08::Auto()//예전 c에서는 auto = 전역 / 지역 구분짓기 위해 사용함
{//요즘 cpp에는 컴파일러가 자동으로 추론한 자료형을 그대로 쓰는게 auto임 그래서 auto앞에 자료형쓰면 오류남 
	//-> 3.14이런식이면 double, 3.14f는 float 이런식 ( 숫자에 커서를 올리면 뜸 ) / 너무 남발 금지
	auto val1 = 10;
	auto val2 = 3.14f;
	string str = "Hello, World!";

	cout << val1 << ", " << val2 << ", " << str << '\n';
}//실수방지, 타이핑 줄이기 등등 사용됨

void Part08::RangeBaseFor()
{
	array<int, 5> arr = { 1,2,3,4,5 };

	cout << "===== 일반 for문 결과 =====\n";//index base for문이라고 한다 이러한 방법은 
	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << ", ";

	cout << "\n\n===== 범위 기반 for문 결과 =====\n";//범위 기반 for문에서도 참조를 사용할 수 있다
	for (int& ref : arr)
		ref *= 2;

	for (int val : arr)
		cout << val << ", ";

	int matrix[5][5]{};
	cout << "\n\n===== 2차원 배열 범위 기반 for문 결과(원시 배열) ===== \n";
	int value = 1;

	for (auto& row : matrix)
	{
		for (int& elem : row)
			elem = value++;
	}

	for (const auto& row : matrix)//바뀌지 않을값이라면 const를 넣도록 하자.
	{
		for (int elem : row)
			cout << elem << ", ";

		cout << '\n';
	}

	array<array<int, 5>, 5> matrix2{};
	cout << "\n\n===== 2차원 배열 범위 기반 for문 결과(STL array) =====\n";
	value = 1;

	for (auto& row : matrix2)//값 늘어나는
	{
		for (int& elem : row)
			elem = value++;
	}

	for (const auto& row : matrix2)
	{
		for (int elem : row)
			cout << setw(2) << elem << ", ";//setw 최소 2칸을 차지하게 만들게 (공백넣기 <- 일렬로 깔끔해보이게)

		cout << '\n';
	}
}

void Part08::AutoPtr()
{
	using namespace Part08_SmartPointer;
}
