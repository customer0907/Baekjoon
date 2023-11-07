#include <iostream>
using namespace std;
#define MAX 100

int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    int T[MAX] = {
        0,
    };
    int P[MAX] = {
        0,
    };
    int dp[MAX] = {
        0,
    };

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> T[i] >> P[i];
    }

    for (int i = N; i > 0; i--)
    {
        if (i + T[i] <= N + 1)
        {
            dp[i] = max(P[i] + dp[i + T[i]], dp[i + 1]);
        }
        else
        {
            dp[i] = dp[i + 1];
        }
    }

    cout << dp[1] << endl;
    return 0;
}