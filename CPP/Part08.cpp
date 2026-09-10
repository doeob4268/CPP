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
    //Lambda();
}

void Part08::Auto()//예전 c에서는 auto = 전역 / 지역 구분짓기 위해 사용함
{//요즘 cpp에는 컴파일러가 자동으로 추론한 자료형을 그대로 쓰는게 auto임 그래서 auto앞에 자료형쓰면 오류남 
   //-> 3.14이런식이면 double, 3.14f는 float 이런식 ( 숫자에 커서를 올리면 뜸 ) / 너무 남발 금지
    auto val1 = 10;
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

    auto_ptr<int> autoPtr(new int(10));//포인터를 객체로 만들고 소멸될때 할당받은 자원을(new int(10)) autoptr 소멸자가 실행될때 해제해줌
    *autoPtr = 20;//연산자 오버로딩때문에 간접참조가 된다

    cout << "autoPtr : " << autoPtr.get() << ", " << *autoPtr << "\n\n";

    int* otherPtr = autoPtr.get();
    *otherPtr = 30;

    cout << "autoPtr : " << autoPtr.get() << ", " << *autoPtr << "\n\n";

    otherPtr = new int;

    autoPtr.reset(otherPtr);//autoPtr해제시키고 소유권을 otherPtr -> autoPtr로 준다는 뜻 / autoPtr이 해제될때 new int도 해제됨
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

    ptr2 = ptr1;//대입연산자를 사용했지만 복사는 안되고 이동이 됨 (ptr1이 가지고 있던걸 ptr2가 뺏어버림) / autoPtr의 치명적인 결함 (파괴적인 복사)

    cout << "\n===== auto_ptr 권한 위임 후 =====\n";
    if (ptr1.get() != nullptr)
        cout << "ptr1 객체가 권한을 가지고 있습니다!\n";
    if (ptr2.get() != nullptr)
        cout << "ptr2 객체가 권한을 가지고 있습니다!\n";
}

void Part08::UniquePtr()
{
    using namespace Part08_SmartPointer;

    //unique_ptr<Widget> ptr1(new Widget());
    auto ptr1 = make_unique<Widget>(); // -> 14버전에서 나옴 
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

void Part08::SharedPtr()//컨트롤 블락은 별도의 공간이여서 부분특수화같은게 필요없다
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

void Part08::WeakPtr()
{
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
