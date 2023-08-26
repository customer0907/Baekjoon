#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N, M;
// graph
int grp[100][100];
// x,y 증분 (상하좌우)
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void maze()
{
    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty())
    {
        int x = q.front().first;  // queue에 들어있는 현재 x 좌표
        int y = q.front().second; // queue에 들어있는 현재 y 좌표

        q.pop();
        // 상하좌우 유효성 검사 && 길 유효성 검사 (==1)
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < N && ny < M && nx >= 0 && ny >= 0 && grp[nx][ny] == 1)
            {
                grp[nx][ny] = grp[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    cout << grp[N - 1][M - 1];
}
int main()
{
    // cin >> N >> M;

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         scanf("%1d", &grp[i][j]);
    //     }
    // }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    string temp;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            temp = s[j];
            if (temp != "")
            {
                grp[i][j] = stoi(temp);
                temp = "";
            }
        }
    }

    maze();
    return 0;
}
