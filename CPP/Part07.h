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

		// 맨 뒤 값 추가
		// 맨 앞 값 추가

		// 특정 인덱스의 노드 삭제

		// 리스트의 모든 노드 삭제하고 초기화

		// [] 인덱스 연산자(읽기/쓰기 버전, 읽기 전용)

		// 리스트에 저장된 값의 개수 반환

		// 리스트 비어있나 확인

	private:
		struct Node
		{
			Node* nextNode = nullptr;
			T val;

			Node(const T& v) : val(v), nextNode(nullptr) {}
		};

		// 특정 인덱스에 해당하는 노드 포인터 찾는 함수

		// 노드 생성(val 받아서)

		Node* headNode = nullptr;
		Node* tailNode = nullptr;

		size_t numVals = 0;
	};
}

namespace Part07_SingletonClassTemplate
{
	template <typename T>
	class Singleton
	{
	public:
		static T& Get()
		{
			static T instance;
			return instance;
		}

	protected:
		Singleton() { cout << "Singleton::Singleton() 생성자 실행 완료!\n"; }
		virtual ~Singleton() { cout << "Singleton::~Singleton() 소멸자 실행 완료!\n"; }

		Singleton(const Singleton&) = delete;
		Singleton(Singleton&&) = delete;
		Singleton& operator=(const Singleton&) = delete;
		Singleton& operator=(Singleton&&) = delete;
	};

	class Widget : public Singleton<Widget>
	{
		friend class Singleton<Widget>;

	public:
		void ShowInfo() { cout << "Widget::ShowInfo() 함수 호출!\n"; }

	private:
		Widget() { cout << "Widget::Widget() 생성자 실행 완료!\n"; }
		~Widget() override { cout << "Widget::~Widget() 소멸자 실행 완료!\n"; }
	};
}

namespace Part07_ClassTemplateSpecialization
{
	template <typename T1, typename T2>
	class Datas
	{
	public:
		Datas() { cout << "Datas<T1, T2>::Datas() 생성자 실행 완료!\n"; }

	private:
		T1 val1{};
		T2 val2{};
	};

	template <typename T>
	class Datas<int, T>
	{
	public:
		Datas() { cout << "Datas<int, T>::Datas() 생성자 실행 완료!\n"; }

	private:
		int val1 = 0;
		T val2{};
	};

	template <>
	class Datas<int, float>
	{
	public:
		Datas() { cout << "Datas<int, float>::Datas() 생성자 실행 완료!\n"; }

	private:
		int val1 = 0;
		float val2 = 0.0f;
	};
}

class Part07
{
public:
	Part07();

	// 함수 템플릿
	template <typename T>
	void Swap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;
	}

	template <>
	void Swap(Part07_FuncTemplate::Data& data1, Part07_FuncTemplate::Data& data2)
	{
		Swap(data1.val, data2.val);
	}

	template <typename T, int LEN = 10>
	T* MakeArr(int len = LEN) { return new T[len]; }

private:
	void FuncTemplate();
	void LinkedListClassTemplate();
	void SingletonClassTemplate();
	void ClassTemplateSpecialization();
};