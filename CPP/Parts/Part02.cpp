#include "pch.h"
#include "Part02.h"

Part02::Part02()
{
	//Overloading();
	//Reference();
	RandomEngine();
}

void Part02::Overloading() //오버로딩은 함수의 이름이 똑같으면 c에서는 다 똑같은 함수 취급을 했는데
							//cpp에서는 같은 이름의 함수가 매개변수의 개수나 자료형을 다르게 하여 서로 다른 기능을 할수있다
{
	int a = 10, b = 20, c = 30;

	cout << "===== 함수 오버로딩 결과 =====\n";
	cout << "숫자 2개 합계 : " << GetSumValue(a, b) << '\n';//이것도 함수의 이름이 똑같지만 매개변수가 a, b랑 a, b, c로 서로 다르므로 다른 취급을 받게되어 저장되는 값도 다르다
	cout << "숫자 3개 합계 : " << GetSumValue(a, b, c) << '\n';
	cout << "숫자 2개 평균 : " << GetAvr(a, b) << '\n';
	cout << "숫자 3개 평균 : " << GetAvr(a, b, c) << '\n';
}

void Part02::Reference() //래퍼런스는 변수의 별명을 지어준다고 하면 이해하기 쉽다 새로운 변수를 만드는게 아니라 기존변수를 가르키는 별명을 만드는것이다
						//포인터랑 비슷한데 다르다 포인터는 nullptr로 비워둘수 있는데 래퍼런스는 비워둘수 없이 무조건 정해줘야 함 그리고 포인터랑 다르게 바꿀수도 없음
{
	int val = 0; // 이건 val가 ptr에 주소를 저장해서 역참조해서 하는 방식이고
	int* ptr = &val;//정수형 변수 val의 메모리 주소를 저장할 수 있는 포인터 변수 ptr을 선언하고, &val을 통해 얻은 val의 메모리 주소로 초기화
	*ptr = 10;//ptr에 저장된 메모리 주소로 이동하여, 해당 주소에 있는 원본 변수 val의 값을 10으로 변경

	cout << "===== 간접 참조 결과 =====\n";
	cout << "Value : " << val << ", " << &val << '\n';
	cout << "Ptr : " << *ptr << ", " << ptr << "\n\n";

	int& ref = val;//이건 ref는 val의 별명이라는거고 ref에 대입해서 val 대입하는거랑 똑같다 그래서 둘이 방식은 다르지만 비슷하다
	ref = 20;//ptr에 저장된 메모리 주소로 이동하여, 해당 주소에 있는 원본 변수 val의 값을 10으로 변경

	cout << "===== 레퍼런스 결과 =====\n";
	cout << "Value : " << val << ", " << &val << '\n';
	cout << "Ref : " << ref << ", " << &ref << "\n\n";

	int a = 10, b = 20;

	cout << "===== 값 교환 전 =====\n";
	cout << a << ", " << b << "\n\n";

	SwapByRef(a, b);

	cout << "===== 값 교환 후 =====\n";
	cout << a << ", " << b << '\n';
}

void Part02::RandomEngine()//c에서는 rand를 써서 난수를 표현했지만 cpp에서는 random이 따로 있어서 더 다양하고 정교한 방식으로 난수를 다룰 수 있다.
						  //rand는 시간마다 값이 바뀌어서 같은 시간에 실행되면 똑같은 난수가 나온다 random은 더 다양하고, 더 정확하고, 더 안전하게 난수를 다룰 수 있다
{
	random_device randomDevice;//random_device 객체인 randomDevice를 선언하여 난수를 생성하는 코드
	mt19937 generator(randomDevice()); //:randomDevice()에서 얻은 값을 시작값으로 사용하여 메르센 트위스터 방식의 난수 엔진인 generator를 생성 generator는 난수를 생성하는 역할을 한다. randomDevice()에서 얻은 값을 초기값으로 사용하여 생성
	//메르센 트위스터 : 난수 생성 알고리즘으로, 다양한 난수를 빠르고 효율적으로 생성하는 데 사용함
	uniform_int_distribution<int> uniformIntDist(0, 99); //0부터 99까지의 정수 중 하나를 균등한 확률로 선택할 수 있도록 난수의 범위를 설정
	uniform_real_distribution<float> uniformRealDist(0.0f, 10.0f);//0.0부터 10.0 사이의 실수 중 하나를 균등한 확률로 선택할 수 있도록 범위를 설정하며, 일반적으로 0.0은 포함하고 10.0은 포함하지 않는다 10은 왜 포함이 안되냐면 생성되는 값의 범위는 0 <= x < 10 이기 떄문에

	constexpr int len = 10;//컴파일 시간 상수를 만드는 키워드다 len은 이제 10이며 다른값으로 변경할수없다

	int arr[len]{};
	float fltArr[len]{};

	for (int i = 0; i < len; ++i)
	{
		arr[i] = uniformIntDist(generator);//generator를 사용하여 uniformIntDist에 설정된 범위인 0부터 99까지의 정수 난수를 생성하고, 그 값을 배열 arr의 i번째 위치에 저장하는 코드
		fltArr[i] = uniformRealDist(generator);//generator를 사용하여 uniformRealDist에 설정된 범위인 0.0 이상 10.0 미만의 실수 난수를 생성하고, 그 값을 배열 fltArr의 i번째 위치에 저장하는 코드
	}

	cout << "===== 정수형 배열 원소 (균등 분포) =====\n";
	for (int i = 0; i < len; ++i)
		cout << arr[i] << ", ";

	cout << "\n\n===== 실수형 배열 원소 (균등 분포) =====\n";
	for (int i = 0; i < len; ++i)
		cout << fltArr[i] << ", ";

	int uniformGraph[100] = { 0 };

	cout << "\n\n===== 균등 분포 그래프 =====\n";
	for (int i = 0; i < 1500; ++i)
	{
		int idx = uniformIntDist(generator);//generator를 사용하여 uniformIntDist에 설정된 범위인 0부터 99까지의 정수 난수를 생성하고, 그 값을 idx 변수에 저장하는 코드
		++uniformGraph[idx];//난수로 정해진 idx 위치의 uniformGraph 배열 값을 1 증가시키는 코드다 0부터 99까지 뽑고 해당 숫자 1증가 시킴
	}

	for (int i = 0; i < 100; ++i)
	{
		cout << i << '\t';

		for (int j = 0; j < uniformGraph[i]; ++j)//uniformGraph[i]에 저장된 횟수만큼 *을 출력해서 아까 증가 시켰던걸 *로 한눈에 보기 쉽게 출력해줌
			cout << '*';

		cout << '\n';
	}

	normal_distribution<float> normalDist(50.0f, 7.0f);//정규분포를 따르는 실수 난수를 만들기 위한 분포를 설정하는 코드 50.0f는 평균 표준편차가 7로 해서 50의 근처값이 잘 나옴

	int normalGraph[100] = { 0 };

	cout << "\n\n===== 정규 분포 그래프 =====\n";
	for (int i = 0; i < 1500; ++i)
	{
		int idx = static_cast<int>(normalDist(generator));//평균 50, 표준편차 7의 정규분포 난수를 생성하고, static_cast<int>를 사용하면 자료형을 바꿀수 있는데 이걸 사용해서 실수인 난수를 정수로 변환한 뒤 idx에 저장하는 코드

		if (idx >= 0 && idx < 100)
			++normalGraph[idx];//해당 숫자가 나온 횟수를 1 증가
	}

	for (int i = 0; i < 100; ++i)
	{
		cout << i << '\t';

		for (int j = 0; j < normalGraph[i]; ++j)
			cout << '*';

		cout << '\n';
	}

	double winPercent = 0.0;

	cout << "\n베르누이 분포 당첨 확률 입력(0 ~ 100) : ";
	cin >> winPercent;

	if (winPercent < 0.0)
		winPercent = 0.0;
	if (winPercent > 100.0)
		winPercent = 100.0;

	int tryCount = 0;

	cout << "시행 횟수 입력(0 이상) : ";
	cin >> tryCount;

	if (tryCount < 0)
		tryCount = 0;

	const double winProbability = winPercent / 100.0;//winPercent에 저장된 백분율 값을 100으로 나누어 확률로 변환하고, 그 결과를 winProbability 변수에 저장하는 코드

	bernoulli_distribution bernoulliDist(winProbability);//winProbability에 저장된 확률을 사용하여 성공 또는 실패 중 하나의 결과를 무작위로 생성하는 분포 객체 bernoulliDist를 선언하는 코드

	int winCount = 0;

	cout << "\n당첨 확률 설정값 : " << winPercent << "%\n";
	cout << "\n시행 횟수 : " << tryCount << "회\n\n";

	cout << "===== 당첨 여부 (베르누이 분포) =====\n";
	for (int i = 0; i < tryCount; ++i)
	{
		cout << i + 1 << "회차 : ";

		if (bernoulliDist(generator))//bernoulliDist라는 확률 결정 도구에 generator라는 난수 엔진을 전달하여, 설정된 확률로 참 거짓 확인하는 코드
		{
			cout << "당첨 되셨습니다!\n";
			++winCount;
		}
		else
		{
			cout << "꽝!\n";
		}
	}

	const double actualWinPercent = static_cast<double>(winCount) / tryCount * 100.0;//winCount의 값을 double 자료형으로 변환하여 소수점이 포함된 계산이 가능하도록 하고, 이를 tryCount로 나눈 뒤 100.0을 곱하여 백분율로 나타낸다 / 전체 시도 횟수에서 성공한 횟수가 차지하는 비율을 계산하여 실제 승률을 구하는 코드

	cout << "\n===== 결과 요약 =====\n";
	cout << "총 시도 횟수 : " << tryCount << '\n';
	cout << "당첨 횟수 : " << winCount << '\n';
	cout << "꽝 횟수 : " << tryCount - winCount << '\n';
	cout << "실제 당첨 확률 : " << actualWinPercent << "%\n";
}

int Part02::GetSumValue(int a, int b)
{
	return a + b;
}

int Part02::GetSumValue(int a, int b, int c)
{
	return a + b + c;
}

void Part02::SwapByRef(int& ref1, int& ref2)
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}
