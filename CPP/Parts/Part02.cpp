#include "pch.h"
#include "Part02.h"

Part02::Part02()
{
	//Overloading();
	//Reference();
	RandomEngine();
}

void Part02::Overloading() //오버로딩은 함수의 이름이 똑같으면 c에서는 다 똑같은 함수 취급을 했는데
							//cpp에서는 이름은 똑같더라도 매개변수가 다르면 컴파일러는 서로 다른 취급을 한다 그런게 오버로딩이다
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
	int* ptr = &val;
	*ptr = 10;

	cout << "===== 간접 참조 결과 =====\n";
	cout << "Value : " << val << ", " << &val << '\n';
	cout << "Ptr : " << *ptr << ", " << ptr << "\n\n";

	int& ref = val;//이건 ref는 val의 별명이라는거고 ref에 대입해서 val 대입하는거랑 똑같다 그래서 둘이 방식은 다르지만 비슷하다
	ref = 20;

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
	random_device randomDevice;
	mt19937 generator(randomDevice()); //: 메르센 트위스터

	uniform_int_distribution<int> uniformIntDist(0, 99);
	uniform_real_distribution<float> uniformRealDist(0.0f, 10.0f);

	constexpr int len = 10;

	int arr[len]{};
	float fltArr[len]{};

	for (int i = 0; i < len; ++i)
	{
		arr[i] = uniformIntDist(generator);
		fltArr[i] = uniformRealDist(generator);
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
		int idx = uniformIntDist(generator);
		++uniformGraph[idx];
	}

	for (int i = 0; i < 100; ++i)
	{
		cout << i << '\t';

		for (int j = 0; j < uniformGraph[i]; ++j)
			cout << '*';

		cout << '\n';
	}

	normal_distribution<float> normalDist(50.0f, 7.0f);

	int normalGraph[100] = { 0 };

	cout << "\n\n===== 정규 분포 그래프 =====\n";
	for (int i = 0; i < 1500; ++i)
	{
		int idx = static_cast<int>(normalDist(generator));

		if (idx >= 0 && idx < 100)
			++normalGraph[idx];
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

	const double winProbability = winPercent / 100.0;

	bernoulli_distribution bernoulliDist(winProbability);

	int winCount = 0;

	cout << "\n당첨 확률 설정값 : " << winPercent << "%\n";
	cout << "\n시행 횟수 : " << tryCount << "회\n\n";

	cout << "===== 당첨 여부 (베르누이 분포) =====\n";
	for (int i = 0; i < tryCount; ++i)
	{
		cout << i + 1 << "회차 : ";

		if (bernoulliDist(generator))
		{
			cout << "당첨 되셨습니다!\n";
			++winCount;
		}
		else
		{
			cout << "꽝!\n";
		}
	}

	const double actualWinPercent = static_cast<double>(winCount) / tryCount * 100.0;

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
