#include "pch.h"
#include "Part02.h"

Part02::Part02()
{
	//Overloading();
	//Reference();
	RandomEngine();
}

void Part02::Overloading()
{
	int a = 10, b = 20, c = 30;

	cout << "===== 함수 오버로딩 결과 =====\n";
	cout << "숫자 2개 합계 : " << GetSumValue(a, b) << '\n';
	cout << "숫자 3개 합계 : " << GetSumValue(a, b, c) << '\n';
	cout << "숫자 2개 평균 : " << GetAvr(a, b) << '\n';
	cout << "숫자 3개 평균 : " << GetAvr(a, b, c) << '\n';
}

void Part02::Reference()
{
	int val = 0; //val 변수를 만들어 0으로 초기화를 시키고 *ptr포인터에 val가르키게 하고 *ptr에 10 대입 (c Part09에서 했던거)
	int* ptr = &val;
	*ptr = 10;

	cout << "===== 간접 참조 결과 =====\n";
	cout << "Value : " << val << ", " << &val << '\n';
	cout << "Ptr : " << *ptr << ", " << ptr << "\n\n";

	int& ref = val;
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

void Part02::RandomEngine()
{
	random_device randomDevice;
	mt19937 generator(randomDevice());

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
