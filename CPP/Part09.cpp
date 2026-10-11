#include "pch.h"
#include "Part09.h"

Part09::Part09()
{
	//Array();
	//Vector();
	//Iterator();
	Algorithm();
}

void Part09::Array()
{
	// STL
	// Standard Template Library
	// Container - 자료구조 std::array(배열). std::vector(배열리스트) std::list(연결리스트)
	// Algorithm - 알고리즘 std::sort std::for_each std::find std::find_if
	// Iterator - 반복자
	// Functor - 함수자 greater less 
	array<int, 10> valList1{};
	array<string, 10> valList2{};

	for (size_t i = 0; i < valList1.size(); ++i)//범위기반for문 쓰기 추천 / size = 배열의 원소 갯수
		valList1[i] = static_cast<int>(i) + 1;

	for (size_t i = 0; i < valList2.size(); ++i)
		valList2[i] = to_string(valList2.size() - i);

	cout << "===== array<int> 원소 출력 =====\n";
	for (size_t i = 0; i < valList1.size(); ++i)
		cout << valList1[i] << ", ";

	cout << "\n\n===== array<string> 원소 출력 =====\n";
	for (size_t i = 0; i < valList2.size(); ++i)
		cout << valList2[i] << ", ";

	cout << '\n';
}
void Part09::Vector()
{
	vector<int> valList1{};
	vector<string> valList2{};	//vector는 push.back을 쓸때 /메모리 재할당이 발생하여 주소가 바뀌면, 기존 원소를 가리키고 있던 포인터를 잃어버린다
								//reserve를 안하면 공간이 부족할때마다 이사를 계속감, 무턱대고 push_back 막 쓰지말고 숫자가 바뀔수도 있으니깐 reserve 사용하기
	valList1.reserve(10);

	for (int i = 0; i < 10; ++i)
	{
		valList1.push_back(i + 1);
		valList2.insert(valList2.begin(), to_string(i + 1));
	}

	cout << "===== vector<int> 원소 출력 =====\n";
	for (size_t i = 0; i < valList1.size(); ++i)
		cout << valList1[i] << ", ";

	cout << "\n\n===== vector<string> 원소 출력 =====\n";
	for (size_t i = 0; i < valList2.size(); ++i)
		cout << valList2[i] << ", ";

	cout << '\n';
}
void Part09::Iterator()
{
	vector<int> valList;

	valList.reserve(10);

	for (int i = 0; i < 10; ++i)
	{
		valList.push_back(i + 1);
	}

	cout << "===== 반복자를 통한 vector 원소 출력 =====\n";
	for (vector<int>::iterator iter = valList.begin(); iter != valList.end(); ++iter)//end begin이 있다는건 시작과 끝이 있다
		cout << *iter << ", ";

	cout << '\n';
}
void Part09::Algorithm()
{
	vector<int> valList;

	valList.reserve(10);

	for (int i = 0; i < 10; ++i)
		valList.push_back(i + 1);

	auto lambda = [](int val) { cout << val << ", "; };
	
	cout << "===== for_each 함수를 통한 vector 원소 출력 =====\n";
	for_each(valList.begin(), valList.end() - 2, lambda);

	auto iter1 = find(valList.begin(), valList.end(), 5);

	if (iter1 != valList.end())
		valList.erase(iter1);//지울 범위를 지정해줘야함 

	cout << "\n\n===== 5 제거 후 vector 원소 출력 =====\n";
	for_each(valList.begin(), valList.end(), lambda);
}