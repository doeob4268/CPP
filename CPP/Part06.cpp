#include "pch.h"
#include "Part06.h"

int Part06_StaticMember::Widget::staticValue = 0;//초기화 할떄 0이라는 값이 들어감

Part06_Singleton::DataManager* Part06_Singleton::DataManager::instance = nullptr;

Part06::Part06()
{
	//StaticMember();
	Singleton();
}

void Part06::StaticMember()//멤버변수는 객체에 따라 저장된다
{
	using namespace Part06_StaticMember;

	Widget widget1;
	Widget widget2;

	widget1.SetValue(10);
	widget2.SetValue(20);

	widget1.SetStaticMemValue(20);
	widget2.SetStaticMemValue(30);

	cout << "===== 클래스 변수 조작 결과 =====\n";
	cout << "widget1 : " << widget1.GetValue() << ", " << widget1.GetStaticMemValue() << '\n';//객체생성 없이도 함수를 호출할수있다, 정적멤버 함수만 가능, :: 범위 확인 연산자, 범위는 정해줘야한다
	cout << "widget1 : " << widget2.GetValue() << ", " << widget2.GetStaticMemValue() << '\n';
}

void Part06::Singleton()
{
	using namespace Part06_Singleton;

	//DataManager::Get()->Create();//객체를 만들기도 전에 먼저 Get을 하면 nullptr이 나오는데 Func호출하면 오류가 나서 문제가 생김
	DataManager* manager = DataManager::Get();
	assert(manager == DataManager::Get());

	// 만든 기능들을 전부 1회 이상 활용해보는 예제 직접 만들어보기

	DataManager::Destroy();
	DataManager::AddData();
}

namespace Part06_Singleton
{
	DataManager* DataManager::Get()
	{
		if (instance == nullptr)
			instance = new DataManager();//이런 기법을 게으른 초기화 라고 한다
										//장점 : 필요하기 전까지 안 만들수있다 (메모리 이점)
										//단점 : 런타임에 동적할당 하는거기 때문에 (로딩창 없이) 좋지 않다 
		return instance;
	}

	void DataManager::Destroy() noexcept
	{
		SAFE_DELETE(instance);
	}
	void DataManager::AddData() noexcept
	{
		cout << "데이터 추가하기";
		int NewData;
		cin >> new Data
	}
	void DataManager::RemoveData() noexcept
	{
		cout << "데이터 삭제하기";

		SAFE_DELETE();
	}

	int DataManager::FindIndex(const string& id) const noexcept
	{
		for (size_t i = 0; i < numDatas; ++i)
		{
			if (datas[i].id == id)
				return static_cast<int>(i);
		}
		return -1;
	}

}