#pragma once

namespace Part05_ArrayList
{
	class ArrayList
	{
	public:
		// ===== 자원 관리 =====
		// 생성자: capacity만큼 힙 공간 새로 임대
		explicit ArrayList(size_t capacity = 0);//묵시적인 형변환을 막는게 explicit, (size_t capacity = 0)기본인자값
		// 복사 생성자: other와 같은 값으로 새 힙 공간 할당 (깊은 복사)
		ArrayList(const ArrayList& other);
		
		// 이동 생성자 : other의 자원을 그대로 가져오고 other는 비움
		ArrayList(ArrayList&& other) noexcept;
		
		// 소멸자 : 힙 공간 반납
		~ArrayList();

		// ===== 연산자 오버로딩 =====
		// 복사 대입: 기존 자원 반납 후, other를 깊은 복사해서 교체
		ArrayList& operator=(const ArrayList& other);
		
		// 이동 대입: 기존 자원 반납 후, other의 자원을 그대로 가져오고 other는 비움
		ArrayList& operator=(ArrayList&& other) noexcept;
		
		// ===== 컨테이너 제어 =====
		int* data() { return arr; }//내부 원소를 수정할수있게, const는 수정할수없게
		const int* data() const {}

		size_t capacity() const { return cap; }
		size_t size() const { return numElements; }

		void reserve(size_t newCapacity);

		// 데이터 추가
		void push_back(int value);//push_back 제일 끝에다 값을 넣는다

	private:
		static size_t CalculateGrowth(size_t currntCapacity);

		size_t cap = 0; //배열의 크기
		size_t numElements = 0;
		int* arr = nullptr;
	};
}

class Part05
{
public:
	Part05();

	void ArrayListClass();

private:
	void PrintArray(int* arr, size_t size);
};