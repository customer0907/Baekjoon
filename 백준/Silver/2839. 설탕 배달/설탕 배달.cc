#include <iostream>
using namespace std;

int env[5001];

int main()
{
    int N;
    int x = 0, y = 0; // x는 5 y는 3 개수
    int min = 0;
    cin >> N;
    int num = N;
    while (5 * x + 3 * y != N)
    {
        if (num > 0)
        {
            num -= 5;
            x++;
        }
        else if (num == 0)
        {
            min = x;
            break;
        }
        else if (5 * (x - 1) + 3 * y < N)
        {
            y++;
            if (x == 0)
            {
                min = -1;
                break;
            }
        }
        else
        {
            x = x - 1;
            if (x == -1)
            {
                min = -1;
                break;
            }
        }
    }
    if (min == -1)
    {
        cout << min;
    }
    else
    {
        cout << x + y;
    }
    return 0;
}
