#include <iostream>
#include <vector>
using namespace std;

int N, M; // 총 사람 수, 부모-자식 관계 개수
int x, y; // 특정 사람 x,y
int a, b; // 부모-자식 관계
vector<int> v[101];
bool visited[101];
int cnt = 0;
// 재귀로 구현

void DFS(int cur, int dest, int num)
{
    if (cur == dest)
    {
        cnt = num;
    }

    visited[cur] = true;

    for (int i = 0; i < v[cur].size(); i++)
    {
        int next = v[cur][i];
        if (!visited[next])
        {
            DFS(next, dest, num + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    cin >> x >> y;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    DFS(x, y, 0);
    if (cnt != 0)
    {
        cout << cnt;
    }
    else
    {
        cout << -1;
    }
  return 0;
}