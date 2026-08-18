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

namespace Part07_SingletonClassTemplate
{
	template <typename T> //T=Widget
	class Singleton
	{//기반 클래스 생성자 호술 -> 기반 객체 생성 -> 파생 객체 생성 (실행 완료되는 기준)
	public:
		static T& Get()
		{
			static T instance;
			return instance;

		}
//멤버에 엑세스할 수 없다고 뜨는데 세부 정보를 보니 선언을 참조하라는 오류가 나는데
// 아마 static T instance;이거랑 Widget& widget = Widget::Get(); 이거의 참조 문제 같거나(1순위)
// 아니면 static T instance;의 스태틱 문제같음(2순위)
// 그것도 아니라면 함수 템플릿에 T랑 Widget이랑 관련된 문제 같다(3순위)
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
		friend class Singleton<Widget>;//기존에 접근제어자의 캡슐화의 한계를 극복해 보고자 나온게 friend다 (Singleton에게만 내 private에 있는걸 공유해줌 서로 공개 X )
		//캡슐화의 정밀도를 올리는 키워드. const_cast같은 그정도 까진 아니고~ 남용하면 안됨
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
		T1 val1{};//{} = 초기화. 가장 심플한 방법
		T2 val2{};
	};

	template <typename T>	//2개중에 하나만 특수화를 한다
	class Datas<int, T>		//앞에있는 애를 int T로 특수화 한다
	{						//템플릿을 활용하여 부분 특수화가 가능하다
	public:
		Datas() { cout << "Datas<int, T>::Datas() 생성자 실행 완료!\n"; }//


	private:
		int val1 = 0;
		T val2{};//얘는 더블 val2가 된다
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
	void SingletonClassTemplate();
	void ClassTemplateSpecialization();
};