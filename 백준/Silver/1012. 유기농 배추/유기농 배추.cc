#include <iostream>
#include <queue>
using namespace std;

int arr[50][50];
bool visited[50][50] = {false};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int cnt = 0;

void batchu(int m, int n)
{
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1 && visited[i][j] == false)
            {
                q.push({i, j});
                visited[i][j] = true; // Mark as visited when adding to queue
                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;

                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx >= 0 && ny >= 0 && nx < m && ny < n && arr[nx][ny] == 1 && visited[nx][ny] == false)
                        {
                            visited[nx][ny] = true; // Mark as visited before pushing to queue
                            q.push({nx, ny});
                        }
                    }
                }
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

    int T, M, N, num, x, y;
    cin >> T;
    
    for (int t = 0; t < T; t++) // Process multiple test cases
    {
        cin >> M >> N >> num;

        for (int i = 0; i < num; i++)
        {
            cin >> x >> y;
            arr[x][y] = 1;
        }

        batchu(M, N);
        cout << cnt << "\n"; // Print result for each test case

        // Reset arrays and variables for the next test case
        cnt = 0;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                arr[i][j] = 0;
                visited[i][j] = false;
            }
        }
    }

    return 0;
}
