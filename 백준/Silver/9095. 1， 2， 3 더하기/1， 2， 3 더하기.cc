#include <iostream>
using namespace std;

int save[11] = {0};

int sumOfThree(int n)
{
    save[1] = 1;
    save[2] = 2;
    save[3] = 4;
    for (int i = 4; i <= n; i++)
    {
        save[i] = save[i - 1] + save[i - 2] + save[i - 3];
    }
    return save[n];
}

int main()
{
    int T; // # of test case
    int num[11];
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> num[i];
    }

    for (int i = 0; i < T; i++)
    {
        cout << sumOfThree(num[i]) << endl;
    }

}