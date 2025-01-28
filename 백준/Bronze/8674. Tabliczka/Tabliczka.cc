#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a, b;
    cin >> a >> b;
    ll total = a * b;

    ll x = a / 2;
    ll v = abs(2 * x * b - total);

    ll y = b / 2;
    ll h = abs(2 * y * a - total);

    cout << min(v, h);
    return 0;
}
