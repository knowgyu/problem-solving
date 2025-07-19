#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, k;
    while (cin >> n >> k) {
        long long result = n + (n - 1) / (k - 1);
        cout << result << '\n';
    }
    return 0;
}
