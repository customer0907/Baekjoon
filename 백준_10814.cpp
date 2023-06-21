#include <iostream>
#include <algorithm>
using namespace std;

class Member {
public:
	int age;
	string name;
	Member()
	{
		age = 0;
		name = "";
	}
	~Member()
	{

	}
};

Member* m = new Member[100001];

bool compare(Member a, Member b)
{
	return a.age < b.age; // 그냥 오름차순으로 적용하겠다는 뜻. 다만 클래스 객체이기 때문에 compare 함수를 써줘야 함.
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> m[i].age >> m[i].name;
	}

	stable_sort(m, m + N,compare); // 클래스는 compare이 없으면 에러를 일으킴. 정렬 기준이 없으면 정렬을 할 수가 없음.
	// stable sort 자체가 정렬하기 전 순서 그대로 정렬한다는 것.
	for (int i = 0; i < N; i++)
	{
		cout << m[i].age << " " << m[i].name << "\n"; // endl 은 버퍼 메모리를 많이 차지하므로 N의 값이 커질 수록 시간이 오래 소모됨.
	}


	return 0;

}