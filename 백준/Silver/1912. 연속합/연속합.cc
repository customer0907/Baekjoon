#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    dp[0] = arr[0];

    for (int i = 1; i < N; i++)
    {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    }

    sort(dp, dp + N);
    cout << dp[N - 1] << endl;
    return 0;
}
