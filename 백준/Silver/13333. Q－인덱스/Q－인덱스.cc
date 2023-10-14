#include <iostream>
#include <algorithm>
using namespace std;

int ts[1001] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int cnt = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> ts[i];
    }

    for (int i = N; i >= 0; i--)
    {
        cnt = 0;
        for (int j = 0; j < N; j++)
        {
            if (ts[j] >= i)
            {
                cnt++;
            }
        }
        if (cnt >= i)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
