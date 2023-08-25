#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int N, M, V;
int arr[1001][1001];
bool visited_DFS[10001] = { false };
bool visited_BFS[10001] = { false };

void DFS(int v)
{
	stack<int> s;
	visited_DFS[v] = true;

	s.push(v);
	cout << v << " ";
	while (!empty(s))
	{
		int j = s.top();
		s.pop();

		for (int i = 1; i <= N; i++)
		{
			if (arr[j][i] == 1 && visited_DFS[i] == false)
			{
				visited_DFS[i] = true;
				cout << i << " ";
				s.push(j); // j와 인접한 배열을 다시 방문하기 위함
				s.push(i); // 방문하지 않은 j 인접 배열을 stack에 넣음
				break; // for문을 빠져나와야 next depth로 바로 갈 수 있음. (DFS)
			}
		}
	}
}

void BFS(int v)
{
	queue<int> q;
	q.push(v);
	visited_BFS[v] = true;
	while (!empty(q))
	{
		int cur = q.front();
		q.pop();
		cout << cur << " ";

		for (int i = 1; i <= N; i++)
		{
			if (arr[cur][i] == 1 && !visited_BFS[i])
			{
				visited_BFS[i] = true;
				q.push(i);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> V;
	int a, b;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	DFS(V);
	cout << endl;
	BFS(V);

	return 0;
}