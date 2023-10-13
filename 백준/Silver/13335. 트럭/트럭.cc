#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// truck 의 무게를 저장할 벡터
// i번째 트럭을 보낼 공간 queue
// queue에 담을 수 있는 조건 (현재 queue에 들어있는 트럭 무게의 합 <)
// 위 사이클 마다 시간 ++ (사이클 안에 큐 안에 들어가지 못한 트럭도 cnt 위해)

int N, W, L;
int truck[1001];

void bridge()
{
    int sum = 0;
    int delay = 0;
    queue<int> q;

    for (int i = 0; i < N; i++)
    {
        while (1)
        {
            if (q.size() == W) // 다리가 꽉차면
            {
                sum -= q.front();
                q.pop();
            }
            if (sum + truck[i] <= L)
                break;
            q.push(0); // 무게 0인 truck 추가, block 상태로 delay 추가되도록
            delay++;
        }
        q.push(truck[i]);
        sum += truck[i];
        delay++;
    }
    cout << delay + W << endl; // delay 자체는 모든 truck이 queue 안에 진입할 때까지 시간
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    cin >> N >> W >> L;
    for (int i = 0; i < N; i++)
    {
        cin >> truck[i];
    }

    bridge();
    return 0;
}