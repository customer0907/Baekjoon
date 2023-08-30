#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int vtx;
int edg;
int x, y;
int cnt = 0;
vector<int> v[101];
int visited[101];

void DFS(int start)
{
    stack<int> s;
    visited[start] = true;
    s.push(start);

    while (!s.empty())
    {
        int cur = s.top();
        s.pop();

        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i];
            if (!visited[next])
            {
                visited[next] = true;
                cnt++;
                s.push(cur);
                s.push(next);
                break;
            }
        }
    }
    cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> vtx;
    cin >> edg;
    for (int i = 0; i < edg; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    DFS(1);

    return 0;
}