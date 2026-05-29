#pragma once

extern "C"
{
	//float GetAvr(int a, int b) { return (a + b) / 2.0f; }
	//float GetAvr(int a, int b, int c) { return (a + b + c) / 3.0f; }
}

class Part02
{
public:
	Part02();

private:
	// 예제 실행 함수
	void Overloading();

	// 오버로딩 예제 함수
	int GetSumValue(int a, int b);
	int GetSumValue(int a, int b, int c);
	float GetAvr(int a, int b) { return (a + b) / 2.0f; }
	float GetAvr(int a, int b, int c) { return (a + b + c) / 3.0f; }

	// 참조 예제 함수
};