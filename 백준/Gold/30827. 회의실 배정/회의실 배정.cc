#include <bits/stdc++.h>
using namespace std;
int N, K;

struct Time
{
    int start, end;
    bool operator<(const Time &r) const
    {
        return tie(end, start) < tie(r.end, r.start);
    }
};
vector<Time> arr;
vector<int> rooms;

int main()
{
    cin >> N >> K;
    arr.reserve(N);
    rooms.resize(K);

    for (int i = 0; i < N; i++)
    {
        int s, e;
        cin >> s >> e;
        arr.push_back({s, e});
    }

    sort(arr.begin(), arr.end());

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        Time cur = arr[i];

        bool Use = false;

        for (int j = 0; j < K; j++)
        {
            if (Use)
                break; // 만약 회의실 차지했으면 그만 돌려도 됨.

            if (cur.start > rooms[j]) // 현재 회의가 j번 회의실 종료보다 늦다면
            {
                Use = true;
                rooms[j] = cur.end;
            }
        }

        if (Use)
        {
            ++ans;
            sort(rooms.rbegin(), rooms.rend());
        }
    }

    cout << ans;

    return 0;
}