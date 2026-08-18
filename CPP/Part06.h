#pragma once

namespace Part06_StaticMember
{
	class Widget
	{
	public:
		int GetValue() const { return value; }
		static int GetStaticMemValue() { return staticValue; }

		void SetValue(int value) { this->value = value; }
		void SetStaticMemValue(int value) { staticValue = value; }

	private:
		int value = 0;
		static int staticValue;
	};
}

namespace Part06_Singleton
{
	struct Data
	{
		string id;

		int value = 0;
		float fltValue = 0.0f;
	};

	class DataManager final
	{
	public:
		static DataManager* Get();

		static void Destroy() noexcept;

		// 데이터 추가 함수 (AddData)
		// 데이터 삭제 함수 (RemoveData)
		// 데이터 존재 확인 함수 (Contains)
		// 저장된 데이터 개수 반환 함수 (Size)
		// 비었는지 확인하는 함수 (Empty)
		// 싱글턴 객체는 유지하면서 내부 데이터만 제거하는 함수 (Clear)

	private:
		// ID로 배열 인덱스 찾기
		int FindIndex(const string& id) const noexcept;

		// 객체 생성과 복사 제한
		DataManager() = default;
		~DataManager() = default;

		DataManager(const DataManager&) = delete;
		DataManager& operator=(const DataManager&) = delete;

		DataManager(DataManager&&) = delete;
		DataManager& operator=(DataManager&&) = delete;

		// 멤버 변수
		static constexpr size_t MAX_DATA_COUNT = 100;

		Data datas[MAX_DATA_COUNT]{};
		size_t numDatas = 0;

		static DataManager* instance;
	};
}

namespace Part06_MeyersSingleton
{
	class DataService final
	{
	public:
		static DataService& Get();

		void SetValue(int value) noexcept;
		void AddValue(int value) noexcept;

		[[nodiscard]]
		int GetValue() const noexcept;

	private:
		// 객체 생성과 복사 제한
		DataService() = default;
		~DataService() = default;

		DataService(const DataService&) = delete;
		DataService& operator=(const DataService&) = delete;

		DataService(DataService&&) = delete;
		DataService& operator=(DataService&&) = delete;

		// 멤버 변수
		int value = 0;
	};
}

namespace Part06_Singletons
{
	class SingletonA
	{
		DECLARE_SINGLETON(SingletonA)

	public:
		void ShowInfo() const;
	};

	class SingletonB
	{
		DECLARE_SINGLETON(SingletonB)

	public:
		void ShowInfo() const;
	};

	class SingletonC
	{
		DECLARE_SINGLETON(SingletonC)

	public:
		void ShowInfo() const;
	};
}

class Part06
{
public:
	Part06();

private:
	void StaticMember();
	void Singleton();
	void MeyersSingleton();
	void Singletons();
};