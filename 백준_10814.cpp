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
	return a.age < b.age; // �׳� ������������ �����ϰڴٴ� ��. �ٸ� Ŭ���� ��ü�̱� ������ compare �Լ��� ����� ��.
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> m[i].age >> m[i].name;
	}

	stable_sort(m, m + N,compare); // Ŭ������ compare�� ������ ������ ����Ŵ. ���� ������ ������ ������ �� ���� ����.
	// stable sort ��ü�� �����ϱ� �� ���� �״�� �����Ѵٴ� ��.
	for (int i = 0; i < N; i++)
	{
		cout << m[i].age << " " << m[i].name << "\n"; // endl �� ���� �޸𸮸� ���� �����ϹǷ� N�� ���� Ŀ�� ���� �ð��� ���� �Ҹ��.
	}


	return 0;

}