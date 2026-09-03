#pragma once

namespace Part08_SmartPointer
{
	class Widget
	{
	public:
		Widget() { cout << "Widget::Widget() 생성자 실행 완료!\n"; }
		~Widget() { cout << "Widget::~Widget() 소멸자 실행 완료!\n"; }
	};
}

namespace Part08_WeakPointer//sharedptr에서 서로 참조해서 카운트가 그대로인 문제를 해결하기 위해 WeakPointer를 쓴다
{
	class Entity;

	class Component
	{
	public:
		Component() { cout << "Component 생성!\n"; }
		virtual ~Component() { cout << "Component 소멸!\n"; }

		weak_ptr<Entity> owner;

		void Update()
		{
			if (!owner.expired())//만료되지 않았다면 
				owner.lock()->Func();
		}
	};

	class Entity : public enable_shared_from_this<Entity>
	{
	public:
		Entity() { cout << "Entity 생성!\n"; }
		virtual ~Entity() { cout << "Entity 소멸!\n"; }

		vector<shared_ptr<Component>> components;//				   //서로 참조 하는 문제가 있음
																   //서로 참조 하는 문제가 있음
		void AddComponent(shared_ptr<Component> comp)			   //서로 참조 하는 문제가 있음
		{
			components.push_back(comp);
			comp->owner = shared_from_this();//내가 소유권의 주인이라는 뜻
		}

		void Update()
		{
			for (const auto& comp : components)
				comp->Update();
		}

		void Func() { cout << "Entity::Func() 함수 호출!\n"; }
	};
}

class Part08
{
public:
	Part08();

private:
	void Auto();
	void RangeBasedFor();
	void AutoPtr();
	void UniquePtr();
	void SharedPtr();
	void WeakPtr();
	void Lambda();

	static void CloseFStream(FILE* stream);
};

//				===== 스마트 포인터 =====
//유니크포인터 : 유일한 소유권을 나타내고 싶을떄
//쉐어드포인터 : 남들이 소유했는지는 알빠아니고 본인만 소유할때(소유를 주장하는 포인터)
//위크	포인터 : 관찰자 같은 느낌 / 댕글링 포인터의 위험이 있음