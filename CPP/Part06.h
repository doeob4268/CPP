#pragma once

namespace Part06_StaticMember
{
	class Widget
	{
	public:
		//Widget() : value(0) {}

		int GetValue() const { return value; }//비정적 멤버
		static int GetStaticMemValue() { return staticValue; }//정적멤버에만 접근할수있다 . this의 getvalue도 안된다
		//쓰는 이유 : 
		void SetValue(int value) { this->value = value; }
		void SetStaticMemValue(int value) { staticValue = value; }

	private:
		int value = 0;
		static int staticValue;//스태틱이여서 데이터 영역에 저장된다
	};
}

namespace Part06_Singleton//유일한 객체 하나만 만드는 것, 게임업계에서 많이 쓰임 <- 싱글턴
{
	struct Data
	{
		string id;

		int value = 0;
		float fltValue = 0.0f;
	};

	class DataManager final //data를 가지고 관리하는 클래스
	{
	public:
		//static void Create()
		//{
		//	if (instance == nullptr)
		//		instance = new DataManager();
		//}
		static DataManager* Get();

		static void Destroy() noexcept;
		static void AddData()noexcept;
		static void RemoveData()noexcept;

		// 데이터 추가 함수 (AddData)
		// 데이터 삭제 함수 (RemoveData)
		// 데이터 존재 확인 함수 (Contains)
		// 저장된 데이터 개수 반환 함수 (Size)
		// 비었는지 확인하는 함수 (Empty)
		// 싱글턴 객체는 유지하면서 내부 데이터만 제거하는 함수 (Clear)

	private:
		// ID로 배열 인덱스 찾기
		int FindIndex(const string& id) const noexcept;


		//객체 생성과 복사 제한
		DataManager() = default;//자동으로 생성자가 public에 생성되는데 private에 먼저 만들어 둔다
		~DataManager() = default;//외부에서 소멸자도 막기 위해 내부에서 만든다, 생성이랑 소멸은 해야해서 내부에서 감춘다

		DataManager(const DataManager&) = delete;//이 함수를 사용하면 삭제가 되어 컴파일러에서 막는다
		DataManager& operator=(const DataManager&) = delete;

		DataManager(DataManager&&) = delete;
		DataManager& operator=(DataManager&&) = delete;
		// 멤버변수
		static constexpr size_t MAX_DATA_COUNT = 100;//스태틱 붙으면 정적멤버, 선언할때 초기화가 되야하기 때문에 여기서 초기화가 된다

		Data datas[MAX_DATA_COUNT]{};
		size_t numDatas = 0;
		
		static DataManager* instance;//포인터는 그냥 주소값이기 때문에 가능함
	};
}

class Part06
{
public:
	Part06();

private:
	void StaticMember();
	void Singleton();
};