#pragma once

namespace Part07_FuncTemplate
{
	struct Data
	{
		int val = 0;
		float fltVal = 0.0f;
	};
}

namespace Part07_LinkedListClassTemplate
{
	template <typename T>
	class LinkedList
	{
		
		// Rule of Five

		//맨 뒤 값 추가
		//맨 앞 값 추가

		//특정 인덱스의 노드 삭제

		//리스트의 모든 노드 삭제하고 초기화

		//[] 인덱스 연산자(읽기/쓰기 버전, 읽기 전용) 구현

		//리스트에 저장된 값의 개수 반환

		//리스트 비어있나 확인

	private:
		struct Node
		{
			Node* nextNode = nullptr;
			T val;

			Node(const T& v) : val(v), nextNode(nullptr){}
			
		};
		
		//특정 인덱스에 해당하는 노드 포인터 찾는 함수
		//void FoundNode()
		//{
		//
		//}
		//노드 생성(val 받아서)
		void AddNode(T val)
		{
			Node* newNode = new Node(val);
			headNode = newNode;
			tailNode = newNode;
			++numVals;
		}

		Node* headNode = nullptr;//시작노드
		Node* tailNode = nullptr;//끝 노드

		size_t numVals = 0;
		
	};
}

class Part07
{
public:
	Part07();
	
	// 함수 템플릿
	template <typename T>//T는 그냥 이름
	void Swap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;

	}

	template <>//함수 템플릿은 특수화만 가능하다
	void Swap(Part07_FuncTemplate::Data& data1, Part07_FuncTemplate::Data& data2)//Data : (20, 10.1), (10, 20.2) val만 바뀜 <- 특수화
	{
		Swap(data1.val, data2.val);
	}

	template <typename T, int LEN = 10>//typename T <- 형식인자
	T* MakeArr(int len = LEN) { return new T[len]; }

private:
	void FuncTemplate();
	void LinkedListClassTemplate();
};