#include "pch.h"
#include <iomanip>
#include "Part08.h"

Part08::Part08()
{
    //Auto(); //17버전에서 삭제
    //RangeBaseFor();
    //AutoPtr();
    //UniquePtr();
    //SharedPtr();
    //WeakPtr();  
    Lambda();
}

void Part08::Auto()//예전 c에서는 auto = 전역 / 지역 구분짓기 위해 사용함
{//요즘 cpp에는 컴파일러가 자동으로 추론한 자료형을 그대로 쓰는게 auto임 그래서 auto앞에 자료형쓰면 오류남 
   //-> 3.14이런식이면 double, 3.14f는 float 이런식 ( 숫자에 커서를 올리면 뜸 ) / 너무 남발 금지
    auto val1 = 10;//자료형을 직접 작성하지 않고, 오른쪽에 있는 초기값을 보고 컴파일러가 변수의 자료형을 자동으로 결정하도록 하는 코드이고 10은 정수형 값이기 때문에 컴파일러가 val1의 자료형을 int로 자동으로 정해진다 결정된 이후에는 일반적인 변수처럼 그 자료형으로 유지함
    auto val2 = 3.14f;
    string str = "Hello, World!";

    cout << val1 << ", " << val2 << ", " << str << '\n';
}//실수방지, 타이핑 줄이기 등등 사용됨

void Part08::RangeBasedFor()
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
    //new int(10)으로 정수 값 10을 저장할 메모리를 동적으로 할당하고, 그 메모리의 주소를 autoPtr이라는 스마트 포인터 객체에 전달하는 코드이고 auto_ptr<int>에서 int는 관리할 데이터의 자료형을 의미하고, autoPtr은 스마트 포인터 객체의 이름이다. 일반 포인터와 달리 autoPtr은 자신이 관리하는 메모리를 자동으로 해제하며, autoPtr 객체가 소멸할 때 소멸자가 실행되어 할당받은 메모리를 해제한다. 따라서 직접 delete를 호출하지 않아도 메모리 누수를 방지함
    auto_ptr<int> autoPtr(new int(10));//포인터를 객체로 만들고 소멸될때 할당받은 자원을(new int(10)) autoptr 소멸자가 실행될때 해제해줌
    *autoPtr = 20;//연산자 오버로딩때문에 간접참조가 된다

    cout << "autoPtr : " << autoPtr.get() << ", " << *autoPtr << "\n\n";

    int* otherPtr = autoPtr.get();
    *otherPtr = 30;

    cout << "autoPtr : " << autoPtr.get() << ", " << *autoPtr << "\n\n";

    otherPtr = new int;
    //autoPtr이 현재 관리하고 있는 메모리를 해제한 다음, otherPtr이 가리키는 메모리를 새롭게 관리하도록 변경하는 기능이다. 여기서 기존 autoPtr이 관리하던 메모리가 있다면 먼저 해제되며, 이후 otherPtr이 가리키는 메모리의 소유권을 autoPtr로 넘겨준다
    autoPtr.reset(otherPtr);//autoPtr해제시키고 소유권을 otherPtr -> autoPtr로 준다는 뜻 / autoPtr이 해제될때 new int도 해제됨
    *autoPtr = 30;

    cout << "otherPtr : " << otherPtr << ", " << *otherPtr << "\n\n";
    //autoPtr이 관리하던 메모리의 주소를 반환하여 otherPtr2에 저장하고, autoPtr은 더 이상 해당 메모리를 관리하지 않도록 만드는 코드이다 / 메모리 안의 값이 복사되는 것이 아니라 메모리의 주소가 전달, 메모리를 자동으로 해제하지 않는다. 그러므로 otherPtr2가 메모리를 관리하는 역할을 맡게 되며, 사용이 끝나면 delete otherPtr2;를 호출하여 직접 메모리를 해제해야함 (메모리 권한만 넘겨줌)
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

    ptr2 = ptr1;//대입연산자를 사용했지만 복사는 안되고 이동이 됨 (ptr1이 가지고 있던걸 ptr2가 뺏어버림) / autoPtr의 치명적인 결함 (파괴적인 복사)

    cout << "\n===== auto_ptr 권한 위임 후 =====\n";
    if (ptr1.get() != nullptr)
        cout << "ptr1 객체가 권한을 가지고 있습니다!\n";
    if (ptr2.get() != nullptr)
        cout << "ptr2 객체가 권한을 가지고 있습니다!\n";
}

void Part08::UniquePtr()//동적으로 할당한 메모리를 자동으로 관리하는 스마트 포인터로, 하나의 메모리를 한 번에 하나의 unique_ptr만 소유하도록 제한시킴
{
    using namespace Part08_SmartPointer;

    //unique_ptr<Widget> ptr1(new Widget());
    auto ptr1 = make_unique<Widget>(); // -> 14버전에서 나옴 //Widget 객체를 동적으로 생성하고, 그 객체를 관리하는 unique_ptr을 만들고 auto는 오른쪽의 반환값을 바탕으로 자료형을 자동으로 결정하므로, ptr1의 실제 자료형은 unique_ptr<Widget>다 / Widget 객체를 생성하고 그 객체의 소유권을 ptr1에 전달하며, ptr1이 소멸하면 관리하던 Widget 객체와 메모리도 자동으로 정리함
    unique_ptr<Widget> ptr2;

    cout << "\n===== auto_ptr 권한 위임 전 =====\n";
    if (ptr1.get() != nullptr)
        cout << "ptr1 객체가 권한을 가지고 있습니다!\n";
    if (ptr2.get() != nullptr)
        cout << "ptr2 객체가 권한을 가지고 있습니다!\n";

    ptr2 = move(ptr1);

    cout << "\n===== auto_ptr 권한 위임 후 =====\n";
    //if (ptr1.get() != nullptr)
    //   cout << "ptr1 객체가 권한을 가지고 있습니다!\n";
    if (ptr2.get() != nullptr)
        cout << "ptr2 객체가 권한을 가지고 있습니다!\n\n";

    unique_ptr<FILE, decltype(&CloseFStream)> wStreamPtr(fopen("Part08.txt", "wt"), &CloseFStream);//decltype 자동으로 자료형 대입해줌 fclose 주소만 넣으면 알아서 타입을 넣어준다

    if (wStreamPtr.get() != nullptr)
        fprintf(wStreamPtr.get(), "Hello World!\n");
}

void Part08::SharedPtr()//컨트롤 블락은 별도의 공간이여서 부분특수화같은게 필요없다//객체를 여러 스마트 포인터가 공동으로 소유하고 관리할 수 있도록 해 주는 스마트 포인터다 그리고 아무도 쓰지 않게 되면(참조 횟수가 0이 되면) 컴퓨터가 알아서 자동으로 메모리를 삭제함
{//deprecated //삭제 예정인데 아직 사용 가능하다 
    using namespace Part08_SmartPointer;

    auto sharedPtr1 = make_shared<Widget>();
        shared_ptr<Widget> sharedPtr2;//shared_ptr가 몇개의 자원을 물고있나가 -> 래퍼런스 포인터

    cout << "\n===== sharedPtr2 할당 전 =====\n";
    cout << "Ref Count : " << sharedPtr1.use_count() << '\n';

    sharedPtr2 = sharedPtr1;//이 행위 자체가 공유한다는 뜻

    cout << "\n===== sharedPtr2 할당 후 =====\n";
    cout << "Ref Count : " << sharedPtr1.use_count() << '\n';

    sharedPtr1.reset();//매개변수없으면 그냥 주소값 nullPtr로 바꾸기

    cout << "\n===== sharedPtr1 참조 해제 후 =====\n";
    cout << "Ref Count : " << sharedPtr2.use_count() << '\n';

    shared_ptr<FILE> rStreamPtr(fopen("part08.txt", "rt"), &CloseFStream);

    if (rStreamPtr.get() != nullptr)
    {
        char buffer[20] = { 0 };
        fgets(buffer, sizeof(buffer), rStreamPtr.get());
        cout << "\n===== Part08.txt 출력 =====\n";
        cout << buffer << '\n';
    }
}

void Part08::WeakPtr()//shared_ptr이 관리하는 객체를 소유권 없이 참조하는 스마트 포인터
//weakPtr이 객체를 가리키고 있었더라도 소유권이 없기 때문에 객체의 메모리 해제를 못함
{//모든 shared_ptr이 소멸하면 객체의 메모리는 해제된다 lock()으로 객체가 살아 있는지 확인하고 접근할 수 있으며, 주로 shared_ptr의 순환 참조 문제를 방지
    using namespace Part08_WeakPointer;

    shared_ptr<Entity> player = make_shared<Entity>();
    player->AddComponent(make_shared<Component>());

    cout << '\n';

    player->Update();

    cout << '\n';
}

void Part08::CloseFStream(FILE* stream)
{
    fclose(stream);
    cout << "CloseFStream() 실행 완료!\n";
}

namespace Part08_WeakPointer
{
    void Component::Update()
    {
        if (!owner.expired())
            owner.lock()->Func();
    }
}

//void reset(_Ty* _Ptr = nullptr) noexcept
//{                        // destroy designated object and store new pointer
//      if (_Ptr != _Myptr) 
//  {
//      delete _Myptr; 
//   }
//
//   _Myptr = _Ptr;
//}

// ^^^ reset에 인자가 없으면 그냥 해제한다는 것 (스마트 포인터를 빈 상태로 만들겠다는 뜻)

// ^^^ 서로 다른 포인터여야 함

//그리고 autoPtr.reset(otherPtr); autoPtr이 해제되고 otherPtr의 주소값을 가지고 소유권도 가지게 된다는건데 소유권을 이전한다는게 아마도 
//otherPtr은 해제해도 그것만 해제되는거지만 autoPtr이 해제되면 나머지 주소값이 같은 모든 포인터들이 해제 된다는거 같다 autoPtr이라는 큰 범위 안에 otherPtr이 있다는 뜻

//release는 reset의 정반대라고 생각하면 된다 그 소유권을 해제한다고 생각하면 된다 소유권 버리기 같은 느낌 그래서 아래 따로 SAFE_DELETE(otherPtr2); 해제를 해줌

//get은 스마트 포인터의 주소나 권한을 유지하고 주소값만 일반 포인터에 복사한다는 뜻
