#include <iostream>
#include <string>
using namespace std;

bool pd(int num)
{
    for (int i = 2; i <= 64; i++)
    {
        int N = num;
        string s;
        while (N)
        {
            s.push_back(N % i);
            N /= i;
        }

        string reverse;

        for (int i = s.length() - 1; i >= 0; i--)
        {
            reverse += s[i];
        }

        if (reverse == s)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, num;
    cin >> N; // # of test

    for (int i = 0; i < N; i++)
    {
        cin >> num;

        cout << pd(num) << endl;
    }
    return 0;
}