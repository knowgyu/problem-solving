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
    ios::sync_with_stdio(0);
    cin.tie(0);
    
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
            if (Use) break;

            if (cur.start > rooms[j])
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