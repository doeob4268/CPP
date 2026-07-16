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

	for (int i = 0; i < 10; ++i)
		arr1.push_back(i + 1);

	ArrayList arr2(arr1);
	ArrayList arr3;

	arr3 = arr1;

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

namespace Part05_ArrayList
{
	ArrayList& ArrayList::operator=(const ArrayList& other)
	{
		// TODO: 여기에 return 문을 삽입합니다.
		
		ArrayList push_back(10); // 초기 용량을 10으로 설정
		ArrayList arr1(10); 
		for (int i = 0; i < 10; ++i) 
			arr1.push_back(i + 1); 

		return *this; 

	}

	ArrayList& ArrayList::operator=(ArrayList&& other) noexcept
	{
		// TODO: 여기에 return 문을 삽입합니다.
	}

	ArrayList::ArrayList(size_t capacity)
	{
	}

	ArrayList::ArrayList(const ArrayList& other)
	{
	}

	ArrayList::ArrayList(ArrayList&& other) noexcept
	{
	}

	ArrayList::~ArrayList()
	{
	}

	void ArrayList::push_back(int value)
	{
	}
}