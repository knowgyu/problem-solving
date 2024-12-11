#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    vector<ull> arr(N + 2, 0);  // +2 for padding
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    ull ans = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i] == 0) continue;

        if (arr[i + 1] > arr[i + 2]) {  // 3번째가 더 작은 경우
            ull m = min(arr[i], arr[i + 1] - arr[i + 2]);
            arr[i] -= m;
            arr[i + 1] -= m;
            ans += 5 * m;  // 2곳 구매

            // 남은 수량에 대해 3곳 구매
            m = min({ arr[i], arr[i + 1], arr[i + 2] });
            arr[i] -= m;
            arr[i + 1] -= m;
            arr[i + 2] -= m;
            ans += 7 * m;

            // 마지막 남은 수량은 1곳 구매
            ans += 3 * arr[i];
        }
        else {  // 일반적인 경우
            // 3곳 구매
            ull m = min({ arr[i], arr[i + 1], arr[i + 2] });
            arr[i] -= m;
            arr[i + 1] -= m;
            arr[i + 2] -= m;
            ans += 7 * m;

            // 2곳 구매
            m = min(arr[i], arr[i + 1]);
            arr[i] -= m;
            arr[i + 1] -= m;
            ans += 5 * m;

            // 1곳 구매
            ans += 3 * arr[i];
        }
    }

    cout << ans;
    return 0;
}