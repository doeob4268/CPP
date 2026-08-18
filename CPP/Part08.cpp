#include "pch.h"
#include "Part08.h"

Part08::Part08()
{
	Auto();
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

	cout << "\n\n===== 범위 기반 for문 결과 =====\n";
	for (int val : arr)
		cout << val << ", ";

}
