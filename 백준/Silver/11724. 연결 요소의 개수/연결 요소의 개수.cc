#include <iostream>
#include <vector>
using namespace std;

vector<int> v[1001];
bool visited[1001];
void DFS(int node)
{
    visited[node] = true;
    for (int i = 0; i < v[node].size(); i++)
    {
        int next = v[node][i];
        if (!visited[next])
        {
            visited[next] = true;
            DFS(next);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M; // # of vertex, edge
    int cnt=0;  // # of connected component
    int a, b;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            DFS(i);
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}