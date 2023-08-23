#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // # of Test case
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string p;    // string of the func(R or D)
        int num;     // # of digits of array
        string arr;  // input array
        string temp; // save the digit
        deque<int> dq;
        bool err = false;
        int cnt = 0; // Reverse 함수 counting

        cin >> p;   // ex) RDD
        cin >> num; // ex) 4
        cin >> arr; // ex) [1,2,3,4]

        for (int j = 0; j < arr.size(); j++)
        {
            if (isdigit(arr[j]))
            {
                temp += arr[j];
            }
            else
            {
                if (temp != "")
                {
                    dq.push_back(stoi(temp));
                    temp = "";
                }
            }
        }

        // dq에는 int형 숫자가 들어가있는 상태 (순서대로)

        for (int k = 0; k < p.size(); k++)
        {
            if (p[k] == 'R')
            {
                cnt++;
            }
            else
            {
                if (dq.empty())
                {
                    err = true;
                    cout << "error" << endl;
                    break;
                }
                if (cnt % 2 == 1)
                {
                    dq.pop_back();
                }
                else if (cnt % 2 == 0)
                {
                    dq.pop_front();
                }
            }
        }

        if (!err)
        {
            cout << "[";
            if (cnt % 2 == 1)
            {

                for (int i = dq.size() - 1; i >= 0; i--)
                {
                    cout << dq[i];
                    if (i != 0)
                    {
                        cout << ",";
                    }
                }
            }
            else
            {
                for (int i = 0; i < dq.size(); i++)
                {
                    cout << dq[i];
                    if (i != dq.size() - 1)
                    {
                        cout << ",";
                    }
                }
            }
            cout << "]" << endl;
        }
    }
  
    return 0;
}