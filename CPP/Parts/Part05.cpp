#include "pch.h"
#include "Part05.h"

Part05::Part05()
{
	ArrayListClass();
}

void Part05::ArrayListClass()
{
	using namespace Part05_ArrayList;

	ArrayList arr1;//초기값 설정안해서 기본인자값으로 초기화

	for (int i = 0; i < 10; ++i)//arr1에 1~10을 순서대로 채워 넣음
		arr1.push_back(i + 1);

	ArrayList arr2(arr1);//arr1을 복제해서 arr2를 만듦 (복사 생성자)
	cout << '\n';

	ArrayList arr3;//빈 창고 하나 더 생성
	cout << '\n';

	arr3 = arr1;//arr1의 값을 arr3에 덮어씀 (복사 대입 연산자)
	cout << '\n';

	cout << "===== 배열 리스트 1 원소 =====\n";
	PrintArray(arr1.data(), arr1.size());

	cout << "\n===== 배열 리스트 2 원소 =====\n";
	PrintArray(arr2.data(), arr2.size());

	cout << "\n===== 배열 리스트 3 원소 =====\n";
	PrintArray(arr3.data(), arr3.size());

	cout << '\n';

	ArrayList arr;
	//vector<int> arr;//템플릿을 사용함

	constexpr int capacity = 10;

	arr.reserve(capacity);//reserve를 안하면 캐퍼스티가 부족할때마다 이사를 계속감, 무턱대고 push_back 막 쓰지말고 숫자가 바뀔수도 있으니깐 reserve 사용하기

	for (int i = 0; i < capacity
		; ++i)
		arr.push_back(i + 1);


	for (size_t i = 0; i < arr.size(); ++i)
		arr[i] *= 10;//메모리상에 존재하면 lvalue

	cout << "\n===== 배열 리스트 원소 =====\n";
	//PrintArray(arr.data(), arr.size());
	arr.Print();

	//cout << arr;

	cout << '\n';

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

	ArrayList::ArrayList(size_t capacity)// 생성자: capacity만큼 힙 공간 새로 임대
		:cap(capacity),
		numElements(0),
		arr(nullptr)
	{
		if (cap > 0)
			arr = new int[cap];//동적할당으로 arr이 new cap만큼 할당

		cout << "ArrayList 생성자 실행 완료!\n";
	}

	ArrayList::ArrayList(const ArrayList& other)// 복사 생성자: other와 같은 값으로 새 힙 공간 할당 (깊은 복사)
		:cap(other.cap),
		numElements(other.numElements),
		arr(nullptr)
	{
		if (cap > 0)
			arr = new int[cap];

		if (numElements > 0)
		{
			assert(other.arr != nullptr);//안전하게 하기 위해 
			copy_n(other.arr, numElements, arr);//<--메모리카피의 c++용
		}

		cout << "ArrayList 복사생성자 실행 완료!\n";
	}

	ArrayList::ArrayList(ArrayList&& other) noexcept// 이동 생성자 : other의 자원을 그대로 가져오고 other는 비움
		:cap(exchange(other.cap, 0))//교환하면서 동시에 ty밸류값 리턴, other.cap 0으로 바꾸면서 원래의 값은 리턴
		, numElements(exchange(other.numElements, 0))
		, arr(exchange(other.arr, nullptr))
	{
		cout << "ArrayList 이동 생성자 실행 완료!\n";
	}

	ArrayList::~ArrayList()
	{
		SAFE_DELETE_ARRAY(arr);

		cap = 0;
		numElements = 0;

		cout << "ArrayList 소멸자 실행 완료!\n";
	}
	ArrayList& ArrayList::operator=(const ArrayList& other) // 복사 대입: 기존 자원 반납 후, other를 깊은 복사해서 교체
	{
		if (this == &other) return *this;

		ArrayList temp(other);//내부의 자원들을 교환, 메모리 누수 X
		swap(cap, temp.cap);
		swap(numElements, temp.numElements);
		swap(arr, temp.arr);

		return *this;
	}

	int& ArrayList::operator[](size_t index)
	{
		assert(index < numElements && "ArrayList index out of range");

		return arr[index];
	}

	// 전위 증가 연산자 //원소의 값
	ArrayList& ArrayList::operator++()//더하고 출력
	{//&  lvalue : 계속 남아있고 참조를 한다
		for (size_t i = 0; i < numElements; ++i)
			++arr[i];

		return *this;//&로 받는 이유는
	}

	//후위 증가 연산자
	ArrayList ArrayList::operator++(int)//출력하고 더하기
	{// rvalue
		ArrayList temp(*this);

		++(*this);

		return temp;//temp는 이 함수에서 만든 객체여서 함수가 끝나면 사라짐
	}

	ArrayList& ArrayList::operator=(ArrayList&& other) noexcept// 이동 대입: 기존 자원 반납 후, other의 자원을 그대로 가져오고 other는 비움
	{
		if (this == &other) return *this;

		SAFE_DELETE_ARRAY(arr);

		cap = exchange(other.cap, 0);
		numElements = exchange(other.numElements, 0);
		arr = exchange(other.arr, nullptr);

		return *this;
	}

	void ArrayList::reserve(size_t newCapacity)
	{
		if (newCapacity <= cap) return;

		int* newArr = new int[newCapacity];

		if (numElements > 0)
			copy_n(arr, numElements, newArr);

		SAFE_DELETE_ARRAY(arr);

		arr = newArr;
		cap = newCapacity;

	}

	void ArrayList::push_back(int value)
	{
		if (numElements >= cap)
			reserve(CalculateGrowth(cap));

		arr[numElements++] = value;

	}

	void ArrayList::Print() const		  //* 복습 *
	{									  //* 복습 *
		cout << *this << '\n';			  //* 복습 *
	}

	size_t ArrayList::CalculateGrowth(size_t currntCapacity)
	{
		if (currntCapacity == 0) return 1;

		constexpr size_t maxCapacity = numeric_limits<size_t>::max();//최대치를 넘기지 않기 위한 조치
																	 //최대치를 넘기지 않기 위한 조치
		if (currntCapacity > maxCapacity / 2)						 //최대치를 넘기지 않기 위한 조치
			throw length_error("ArrayList capcity overflow");		 //최대치를 넘기지 않기 위한 조치

		return currntCapacity * 2;
	}

	ostream& operator<<(ostream& stream, const ArrayList& arr)
	{
		if (arr.empty())
		{
			stream << "(empty)";
			return stream;
		}

			for (size_t i = 0; i < arr.size(); ++i)
			{
				stream << arr[i];

				if (i + 1 < arr.size())
					stream << ", ";
			}

		return stream;
	}
}
//ArrayList 생성자 실행 완료! <- arr1 (ArrayList arr1;)
//ArrayList 복사생성자 실행 완료! <- arr2 (ArrayList arr2(arr1);)
//
//ArrayList 생성자 실행 완료! <- arr3 (ArrayList arr3;)
//
//ArrayList 복사생성자 실행 완료! <-arr3 (arr3 = arr1;)
//ArrayList 소멸자 실행 완료! <- arr2 (깊은 복사 하고 이중해제를 하지 않기 위해)
//
//==== = 배열 리스트 1 원소 ==== =
//1, 2, 3, 4, 5, 6, 7, 8, 9, 10
//
//==== = 배열 리스트 2 원소 ==== =
//1, 2, 3, 4, 5, 6, 7, 8, 9, 10
//
//==== = 배열 리스트 3 원소 ==== =
//1, 2, 3, 4, 5, 6, 7, 8, 9, 10
//
//ArrayList 소멸자 실행 완료! <- arr1
//ArrayList 소멸자 실행 완료! <- arr2
//ArrayList 소멸자 실행 완료! <- arr3