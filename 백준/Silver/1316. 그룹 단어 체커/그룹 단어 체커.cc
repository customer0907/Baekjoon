#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
// 나왔던 문자가 떨어져서 다시 한번 나오면 그룹문자가 아님.
// 나왔던 문자를 저장할 또는 기억할 필요성 temp or array[]
// 문자열 길이를 모두 순회하면서, 지금까지의 배열에 있는 문자이면서 이전 string과 다르다면 break 아니면 cnt++

int cnt = 0;
void checker(string s)
{
    bool apb[26] = {false};
    apb[(int)(s[0] - 97)] = true; // 첫번째 문자열 true
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i - 1] == s[i])
        {
            continue;
        }
        else if (s[i - 1] != s[i] && apb[(int)(s[i] - 97)] == true)
        {
            cnt++;
            break;
        }
        else
        {
            apb[(int)(s[i] - 97)] = true;
        }
    }
}

int main()
{
    int N;
    string str;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> str;
        checker(str);
    }

    cout << N - cnt << endl;

    return 0;
}