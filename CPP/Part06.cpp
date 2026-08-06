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
	DataManager::AddData();//비정적 멤버를 참조하려면 특정 개체가 필요합니다가 아래에서 static을 뺴니깐 작동했는데 static을 뺴서 오류가 사라졌는데 이건 같은 오류인데 static을 뺴니깐 오류가 사라졌다, static 뺴도 오류가 안사라진다
}//removeData는 이거를 안써도 되는데 아마도 static 유무 차이떄문에 오류가 생기는거같다 <- 스태틱을 쓰면 AddData를 호출할때 객체가 다같이 공유되는데 그게 문제인거 같다

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
		numDatas++;//이것만 쓰려고했는데 비정적 멤버를 참조하려면 특정 개체가 필요합니다.라고 떠서 객체를 만들어서 참조를 해야된다
	}//근데 static를 뺴니깐 작동했는데 static이 클래스에 속하는 객체를 공유하는 멤버라서 객체를 만들지 않아도 접근이 가능하다, 근데 비정적 멤버는 특정 객체에 속하는 멤버라서 객체를 만들어야 접근이 가능하다
	void DataManager::RemoveData() noexcept
	{
		cout << "데이터 삭제하기";
	
		numDatas--; //추가에서 하나 늘렸으면 삭제하기에서 하나 줄여야한다 이것도 마찬가지로 static를 뺴니깐 작동했는데 static을 뺴니깐 오류가 사라졌다
		if (numDatas < 0)//근데 0보다 작아지면 안되기 때문에 0보다 작으면 0으로 초기화 시켜준다
		{
			numDatas = 0;
		}
	}
	bool DataManager::Contains()
	{
		cout << "데이터 존재 확인";

		if (numDatas == 0) //numDatas는 객체가 가지고있는 데이터인데 그게 존재하지 않으면 false를 반환하고 아니면 true를 반환한다
		{
			cout << "데이터가 존재하지 않습니다.";
			return false;
		}
		return true;
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