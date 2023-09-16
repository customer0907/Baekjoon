#include <iostream>
#include <algorithm>
using namespace std;

int N, M; // M*N board row, col
char bd[51][51];
int cnt = 0;

int check(int x, int y)
{
    int temp1 = 0;
    int temp2 = 0;

    for (int i = x; i < x + 8; i++)
    {
        for (int j = y; j < y + 8; j++)
        {
            if ((i + j) % 2 == bd[i][j])
                temp1++;
            if ((i + j + 1) % 2 == bd[i][j])
                temp2++;
        }
    }

    return min(temp1, temp2);
}
int main()
{
    cin >> N >> M;
    char fst;
    int min = 64;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> fst;
            if (fst == 'B')
            {
                bd[i][j] = 0; // Black = 0
            }
            else
                bd[i][j] = 1; // White = 1
        }
    }

    for (int i = 0; i <= N - 8; i++)
    {
        for (int j = 0; j <= M - 8; j++)
        {
            if (min > check(i, j))
                min = check(i, j);
        }
    }

    cout << min;
    return 0;
}
