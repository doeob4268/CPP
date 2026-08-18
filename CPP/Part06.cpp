#include "pch.h"
#include "Part06.h"

int Part06_StaticMember::Widget::staticValue = 0;

Part06_Singleton::DataManager* Part06_Singleton::DataManager::instance = nullptr;

Part06::Part06()
{
	//StaticMember();
	//Singleton();
	//MeyersSingleton();
	Singletons();
}

void Part06::StaticMember()
{
	using namespace Part06_StaticMember;

	Widget widget1;
	Widget widget2;

	widget1.SetValue(10);
	widget2.SetValue(20);

	widget1.SetStaticMemValue(20);
	widget2.SetStaticMemValue(30);

	cout << "===== 클래스 변수 조작 결과 =====\n";
	cout << "widget1 : " << widget1.GetValue() << ", " << Widget::GetStaticMemValue() << '\n';
	cout << "widget2 : " << widget2.GetValue() << ", " << widget2.GetStaticMemValue() << '\n';
}

void Part06::Singleton()
{
	using namespace Part06_Singleton;

	DataManager* manager = DataManager::Get();
	assert(manager == DataManager::Get());

	// 만든 기능들을 전부 1회 이상 활용해보는 예제 직접 만들어보기

	DataManager::Destroy();
}

void Part06::MeyersSingleton()
{
	using namespace Part06_MeyersSingleton;

	DataService& service1 = DataService::Get();
	DataService& service2 = DataService::Get();

	assert(&service1 == &service2);

	service1.SetValue(10);
	service2.AddValue(20);

	cout << "===== Meyers Singleton 결과 =====\n";
	cout << "service1 값 : " << service1.GetValue() << '\n';
	cout << "service2 값 : " << service2.GetValue() << '\n';
}

void Part06::Singletons()
{
	using namespace Part06_Singletons;

	SingletonA::Get().ShowInfo();
	cout << '\n';

	SingletonB::Get().ShowInfo();
	cout << '\n';

	SingletonC::Get().ShowInfo();
	cout << '\n';
}

namespace Part06_Singleton
{
	DataManager* DataManager::Get()
	{
		if (instance == nullptr)
			instance = new DataManager();

		return instance;
	}

	void DataManager::Destroy() noexcept
	{
		SAFE_DELETE(instance);
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

namespace Part06_MeyersSingleton
{
	DataService& DataService::Get()
	{
		static DataService instance;

		return instance;
	}

	void DataService::SetValue(int value) noexcept
	{
		this->value = value;
	}

	void DataService::AddValue(int value) noexcept
	{
		this->value += value;
	}

	int DataService::GetValue() const noexcept
	{
		return value;
	}
}

namespace Part06_Singletons
{
	void SingletonA::ShowInfo() const
	{
		cout << "SingletonA::ShowInfo() 호출!\n";
	}

	void SingletonB::ShowInfo() const
	{
		cout << "SingletonB::ShowInfo() 호출!\n";
	}

	void SingletonC::ShowInfo() const
	{
		cout << "SingletonC::ShowInfo() 호출!\n";
	}
}