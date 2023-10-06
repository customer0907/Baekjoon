#include <iostream>
#include <algorithm>
using namespace std;

int rgb[1001][3];

int main()
{
    int N;
    int cost[3];
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> cost[0] >> cost[1] >> cost[2];
        rgb[i][0] = min(rgb[i - 1][1], rgb[i - 1][2]) + cost[0]; // i번째 집 빨간색 칠할 경우, i-1번째(G or B)까지 최솟값 비교
        rgb[i][1] = min(rgb[i - 1][0], rgb[i - 1][2]) + cost[1];
        rgb[i][2] = min(rgb[i - 1][0], rgb[i - 1][1]) + cost[2];
    }

    cout << min({rgb[N][0], rgb[N][1], rgb[N][2]});
    return 0;
}