#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;  cin >> N;
    long long best_x = 0, best_y = LLONG_MAX;

    for (int i = 0; i < N; ++i) {
        long long x, y;  cin >> x >> y;
        if (y < best_y) { best_y = y; best_x = x; }
    }
    cout << best_x << ' ' << best_y;
    return 0;
}
