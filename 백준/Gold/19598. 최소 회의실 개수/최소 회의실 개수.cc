#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> arr[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i].first >> arr[i].second;

    sort(arr, arr + N);

    priority_queue<int> pq;

    int ans = 0;
    for (int i = 0; i < N;i++) {
        while (!pq.empty() && -pq.top() <= arr[i].first)
            pq.pop();

        pq.push(-arr[i].second);
        ans = max(ans, int(pq.size()));
    }

    cout << ans << '\n';

    return 0;
}