#include <iostream>
#include <queue>
using namespace std;

int arr[101][101];         // 좌표 (r,c)
bool visited[101][101];    // 방문 여부
int dx[4] = {-1, 1, 0, 0}; // 좌,우 validation
int dy[4] = {0, 0, -1, 1}; // 상,하 validation
int N, M;                  // 세로, 가로 길이 (행,열)
int row, col;              // 좌표
int K;                     // 쓰레기 개수
int cnt = 0;               // 쓰레기 계수(local)
int temp = 0;              // 쓰레기 계수(global)
void BFS(int r, int c)
{
    queue<pair<int, int>> q;
    q.push(make_pair(r, c));
    cnt++;
    visited[r][c] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && ny >= 1 && nx <= N && ny <= M && !visited[nx][ny] && arr[nx][ny] == 1)
            {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
                cnt++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> K;

    for (int i = 0; i < K; i++)
    {
        cin >> row >> col;
        arr[row][col] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (!visited[i][j] && arr[i][j] == 1)
            {
                cnt = 0;
                BFS(i, j);
                if (cnt > temp)
                    temp = cnt;
            }
        }
    }

    cout << temp;
    return 0;
}
