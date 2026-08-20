#include "pch.h"
#include <iomanip>
#include "Part08.h"

Part08::Part08()
{
	//Auto();
	//RangeBaseFor();
	//AutoPtr();
	UniquePtr();
}

void Part08::Auto()//예전 c에서는 auto = 전역 / 지역 구분짓기 위해 사용함
{//요즘 cpp에는 컴파일러가 자동으로 추론한 자료형을 그대로 쓰는게 auto임 그래서 auto앞에 자료형쓰면 오류남 
	//-> 3.14이런식이면 double, 3.14f는 float 이런식 ( 숫자에 커서를 올리면 뜸 ) / 너무 남발 금지
	auto val1 = 10;
	auto val2 = 3.14f;
	string str = "Hello, World!";

	cout << val1 << ", " << val2 << ", " << str << '\n';
}//실수방지, 타이핑 줄이기 등등 사용됨

void Part08::RangeBaseFor()
{
	array<int, 5> arr = { 1,2,3,4,5 };

	cout << "===== 일반 for문 결과 =====\n";//index base for문이라고 한다 이러한 방법은 
	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << ", ";

	cout << "\n\n===== 범위 기반 for문 결과 =====\n";//범위 기반 for문에서도 참조를 사용할 수 있다
	for (int& ref : arr)
		ref *= 2;

	for (int val : arr)
		cout << val << ", ";

	int matrix[5][5]{};
	cout << "\n\n===== 2차원 배열 범위 기반 for문 결과(원시 배열) ===== \n";
	int value = 1;

	for (auto& row : matrix)
	{
		for (int& elem : row)
			elem = value++;
	}

	for (const auto& row : matrix)//바뀌지 않을값이라면 const를 넣도록 하자.
	{
		for (int elem : row)
			cout << elem << ", ";

		cout << '\n';
	}

	array<array<int, 5>, 5> matrix2{};
	cout << "\n\n===== 2차원 배열 범위 기반 for문 결과(STL array) =====\n";
	value = 1;

	for (auto& row : matrix2)//값 늘어나는
	{
		for (int& elem : row)
			elem = value++;
	}

	for (const auto& row : matrix2)
	{
		for (int elem : row)
			cout << setw(2) << elem << ", ";//setw 최소 2칸을 차지하게 만들게 (공백넣기 <- 일렬로 깔끔해보이게)

		cout << '\n';
	}
}

void Part08::AutoPtr()//자동으로 해제 해주는게 autoptr
{
	using namespace Part08_SmartPointer;

	auto_ptr<int> autoPtr(new int(10));//포인터를 객체로 만들고 소멸될때 할당받은 자원을(new int(10)) autoptr 소멸자가 실행될때 해제해줌
	*autoPtr = 20;//연산자 오버로딩때문에 간접참조가 된다

	cout << "autoPtr : " << autoPtr.get() << ", " << *autoPtr << "\n\n";

	int* otherPtr = autoPtr.get();
	*otherPtr = 30;

	cout << "autoPtr : " << autoPtr.get() << ", " << *autoPtr << "\n\n";

	otherPtr = new int;

	autoPtr.reset(otherPtr);//otherPtr해제시키고 그냥 리셋만 할수있고 otherPtr을 넣으면 otherPtr로 해제됨 / autoPtr이 해제될때 new int도 해제된다는 말
	*autoPtr = 30;

	cout << "otherPtr : " << otherPtr << ", " << *otherPtr << "\n\n";

	int* otherPtr2 = autoPtr.release();//null로 바꿈 가지고있던걸 반환하고 otherPtr2가 가져감 <- 값이 똑같음 근데 릴리스를 otherPtr2로 받아서 (otherPtr2 해제를 해야한다)

	cout << "otherPtr2 : " << otherPtr2 << ", " << *otherPtr2 << "\n\n";

	SAFE_DELETE(otherPtr2);

	auto_ptr<Widget> ptr1(new Widget());
	auto_ptr<Widget> ptr2;

	cout << "\n===== auto_ptr 권한 위임 전 =====\n";
	if (ptr1.get() != nullptr)
		cout << "ptr1 객체가 권한을 가지고 있습니다!\n";
	if (ptr2.get() != nullptr)
		cout << "ptr2 객체가 권한을 가지고 있습니다!\n";

	ptr2 = ptr1;//대입연산자를 사용했지만 복사는 안되고 이동이 됨 (ptr1이 가지고 있던걸 ptr2가 뺏어버림) / autoPtr의 치명적인 결함

	cout << "\n===== auto_ptr 권한 위임 후 =====\n";
	if (ptr1.get() != nullptr)
		cout << "ptr1 객체가 권한을 가지고 있습니다!\n";
	if (ptr2.get() != nullptr)
		cout << "ptr2 객체가 권한을 가지고 있습니다!\n";
}

void Part08::UniquePtr()
{
	using namespace Part08_SmartPointer;

	unique_ptr<Widget> ptr1(new Widget());
	unique_ptr<Widget> ptr2;

	cout << "\n===== auto_ptr 권한 위임 전 =====\n";
	if (ptr1.get() != nullptr)
		cout << "ptr1 객체가 권한을 가지고 있습니다!\n";
	if (ptr2.get() != nullptr)
		cout << "ptr2 객체가 권한을 가지고 있습니다!\n";

	ptr2 = move(ptr1);

	cout << "\n===== auto_ptr 권한 위임 후 =====\n";
	//if (ptr1.get() != nullptr)
	//	cout << "ptr1 객체가 권한을 가지고 있습니다!\n";
	if (ptr2.get() != nullptr)
		cout << "ptr2 객체가 권한을 가지고 있습니다!\n\n";
}