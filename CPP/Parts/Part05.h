#pragma once

namespace Part05_ArrayList
{
	class ArrayList
	{
	public:
		// ===== 연산자 오버로딩 =====
		// 복사 대입
		ArrayList& operator=(const ArrayList& other);
		// 이동 대입
		ArrayList& operator=(ArrayList&& other) noexcept;

		// ===== 자원 관리 =====
		// 생성자
		explicit ArrayList(size_t capacity = 0);
		// 복사 생성자
		ArrayList(const ArrayList& other);
		// 이동 생성자
		ArrayList(ArrayList&& other) noexcept;
		// 소멸자
		~ArrayList();

		// ===== 컨테이너 제어 =====
		int* data() {}
		const int* data() const {}

		size_t capacity() const {}
		size_t size() const {}
		// 데이터 추가
		void push_back(int value);

	private:
		size_t cap = 0;
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