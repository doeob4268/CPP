#include "pch.h"
#include "Part05.h"

Part05::Part05()
{
	ArrayListClass();
}

void Part05::ArrayListClass()
{
	using namespace Part05_ArrayList;

	ArrayList arr1;

	for (int i = 0; i < 10; ++i)//arr1에 1~10을 순서대로 채워 넣음
		arr1.push_back(i + 1);

	ArrayList arr2(arr1);//arr1을 복제해서 arr2를 만듦 (복사 생성자)
	ArrayList arr3;//빈 창고 하나 더 생성

	arr3 = arr1;//arr1의 값을 arr3에 덮어씀 (복사 대입 연산자)

	cout << "===== 배열 리스트 1 원소 =====\n";
	PrintArray(arr1.data(), arr1.size());

	cout << "===== 배열 리스트 2 원소 =====\n";
	PrintArray(arr2.data(), arr2.size());

	cout << "===== 배열 리스트 3 원소 =====\n";
	PrintArray(arr3.data(), arr3.size());
}

void Part05::PrintArray(int* arr, size_t size)
{
	for (size_t i = 0; i < size - 1; ++i)
		cout << arr[i] << ", ";

	cout << arr[size - 1];

	cout << '\n';
}

namespace Part05_ArrayList//얕은 복사로 인해 arr1, arr2, arr3가 같은 힙 공간을 바라보게 되므로 깊은 복사로 구현해야함
{						//new로 새 공간 확보 + for문으로 값 하나씩 복사
	ArrayList& ArrayList::operator=(const ArrayList& other) // 복사 대입: 기존 자원 반납 후, other를 깊은 복사해서 교체
	{
		// TODO: 여기에 return 문을 삽입합니다.

	}

	ArrayList& ArrayList::operator=(ArrayList&& other) noexcept// 이동 대입: 기존 자원 반납 후, other의 자원을 그대로 가져오고 other는 비움
	{														   
		// TODO: 여기에 return 문을 삽입합니다.
		
	}

	ArrayList::ArrayList(size_t capacity)// 생성자: capacity만큼 힙 공간 새로 임대
		: cap(capacity)
	{

	}

	ArrayList::ArrayList(const ArrayList& other)// 복사 생성자: other와 같은 값으로 새 힙 공간 할당 (깊은 복사)
	{

	}

	ArrayList::ArrayList(ArrayList&& other) noexcept// 이동 생성자 : other의 자원을 그대로 가져오고 other는 비움
	{

	}

	ArrayList::~ArrayList()// 소멸자 : 힙 공간 반납
	{

	}

	void ArrayList::push_back(int value)// 데이터 추가
	{

	}
}